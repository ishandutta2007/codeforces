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

int n;
vpii adjList[100000];
int s[100000],t[100000];
int parent[100000][17],disc[100000],fin[100000],num = 0;
LLI depth[100000];
int bit[100001],child[100000];
int update(int i,int num) {
    for (i++; i <= n; i += i & (-i)) bit[i] += num;
    return 0;
}
int query(int i) {
    int sum = 0;
    for (i++; i > 0; i -= i & (-i)) sum += bit[i];
    return sum;
}
int doDFS(int u,int p,LLI d) {
    int i,l = -1;
    parent[u][0] = p,depth[u] = d,disc[u] = num++;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (v != p) doDFS(v,u,d+adjList[u][i].second),l = v;
    }
    child[u] = l;
    if (l != -1) update(disc[l],1),update(fin[l],-1);
    fin[u] = num;
    return 0;
}
int tree[1 << 18];
int update(int s,int e,int ai,int i,int num) {
    if ((s > ai) || (e < ai)) return 0;
    else if (s == e) {
        tree[i] = num;
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,ai,2*i+1,num),update(mid+1,e,ai,2*i+2,num);
    tree[i] = max(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int query(int s,int e,int qs,int qe,int i) {
    if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) return tree[i];

    int mid = (s+e) / 2;
    return max(query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2));
}
vplli vv;
priority_queue<LLI,vlli,greater<LLI> > H;
int main() {
    int i;
    int m;
    int u,v,d;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d %d",&u,&v,&d);
        u--,v--;
        adjList[u].pb(mp(v,d));
        adjList[v].pb(mp(u,d));
    }
    for (i = 0; i < m; i++) scanf("%d %d",&s[i],&t[i]),s[i]--;

    int j;
    doDFS(0,-1,0);
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    int logn = i;
    for (i = 0; i < m; i++) {
        int u = s[i];
        while (u != -1) {
            for (j = logn-1; j >= 0; j--) {
                if ((parent[u][j] != -1) && (query(disc[u]) == query(disc[parent[u][j]])+(1 << j))) u = parent[u][j];
            }
            int p = parent[u][0];
            if (p != -1) {
                update(disc[u],1),update(fin[u],-1);
                update(disc[child[p]],-1),update(fin[child[p]],1);
                LLI pt = query(0,n-1,disc[p],fin[p]-1,0);
                if (pt > 0) pt += depth[p];
                vv.pb(mp(pt+1,t[i]+depth[p])),child[p] = u;
            }
            u = p;
        }
        if (s[i] != 0) update(0,n-1,disc[parent[s[i]][0]],0,t[i]); // apparently destinations are not necessarily leaves...
    }

    LLI ans = -1;
    vv.pb(mp(1e18,1e18));
    sort(vv.begin(),vv.end());
    for (i = 0; i < vv.size()-1; i++) {
        int c = 0;
        H.push(vv[i].second);
        while (!H.empty() && (c < vv[i+1].first-vv[i].first)) {
            if (H.top() < vv[i].first+c) {
                ans = H.top();
                break;
            }
            H.pop(),c++;
        }
        if (ans != -1) break;
    }
    printf("%I64d",ans);
    if (ans == -1) printf(" %d\n",vv.size()-1);
    else {
        int c = 0;
        for (i = 0; i < vv.size(); i++) {
            if (vv[i].second < ans) c++;
        }
        printf(" %d\n",c);
    }

    return 0;
}