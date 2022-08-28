#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

vi adjList[100000];
int parent[100000],size[100000],depth[100000],disc[100000],num = 1;
int doDFS(int u,int p) {
    int i;
    parent[u] = p,size[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) size[u] += doDFS(v,u);
    }
    return size[u];
}
int ss[100000];
vector<pair<int,pii> > vv[100000];
int doDFS2(int u,int p,int d,int r) {
    int i,x = -1;
    parent[u] = p,depth[u] = d,disc[u] = num++;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            int y = doDFS2(v,u,d+1,r);
            if (y != -1) {
                if (x == -1) x = y;
                else vv[r].pb(mp(d,mp(x,y))),x = -1;
            }
        }
    }
    if (x != -1) vv[r].pb(mp(d,mp(x,u))),x = -1;
    else x = u;
    return x;
}
int used[100000];
priority_queue<pii> H;
int main() {
    int i;
    int n,u,v;
    LLI k;
    scanf("%d %I64d",&n,&k);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    int j,s = 0;
    LLI b = 0;
    doDFS(0,-1);
    for (i = 1; i < n; i++) s += size[i] & 1,b += min(size[i],n-size[i]);
    if ((k < s) || (k > b) || ((k-s) & 1)) {
        printf("NO\n");
        return 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < adjList[i].size(); j++) {
            int v = adjList[i][j];
            if ((v == parent[i]) && (n-size[i] > n/2)) break;
            else if ((v != parent[i]) && (size[v] > n/2)) break;
        }
        if (j == adjList[i].size()) break;
    }
    printf("YES\n");
    int c = i;
    doDFS(c,-1);
    for (i = 0; i < adjList[c].size(); i++) {
        doDFS2(adjList[c][i],c,1,i),ss[i] = size[adjList[c][i]],H.push(mp(ss[i],i));
        reverse(vv[i].begin(),vv[i].end());
    }
    while (b > k) {
        int u = H.top().second;
        H.pop();

        if (b-2*vv[u].back().first < k) {
            int v = vv[u].back().second.first,d = (b-k)/2;
            while (depth[v] > d) v = parent[v];
            vi cc;
            if (!used[v]) cc.pb(v);
            for (i = 0; i < adjList[v].size(); i++) {
                if ((adjList[v][i] != parent[v]) && !used[adjList[v][i]]) cc.pb(adjList[v][i]);
            }
            printf("%d %d\n",cc[0]+1,cc[1]+1);
            used[cc[0]] = used[cc[1]] = 1;
            break;
        }
        else {
            printf("%d %d\n",vv[u].back().second.first+1,vv[u].back().second.second+1);
            used[vv[u].back().second.first] = used[vv[u].back().second.second] = 1;
            b -= 2*vv[u].back().first;
            vv[u].pop_back();
        }
        ss[u] -= 2;
        H.push(mp(ss[u],u));
    }
    vpii all;
    for (i = 0; i < n; i++) {
        if (!used[i]) all.pb(mp(disc[i],i));
    }
    sort(all.begin(),all.end());
    for (i = 0; i < all.size()/2; i++) printf("%d %d\n",all[i].second+1,all[i+all.size()/2].second+1);

    return 0;
}