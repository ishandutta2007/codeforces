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
int dp[100000],dp2[100000],node[100000];
vpii cc[100000];
vi tree[100000];
int build(int s,int e,int i,int u) {
    if (s == e) {
        tree[u][i] = max(cc[u][s].first,1)+s;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1,u),build(mid+1,e,2*i+2,u);
    tree[u][i] = max(tree[u][2*i+1],tree[u][2*i+2]);
    return 0;
}
int query(int s,int e,int qs,int qe,int i,int u) {
    if ((s > qe) || (e < qs)) return -1e9;
    else if ((s >= qs) && (e <= qe)) return tree[u][i];

    int mid = (s+e) / 2;
    return max(query(s,mid,qs,qe,2*i+1,u),query(mid+1,e,qs,qe,2*i+2,u));
}
int doDFS(int u,int p) {
    int i;
    vpii c;
    cc[u].clear();
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u),c.pb(mp(dp[v],v));
    }
    if (c.empty()) dp[u] = 0,node[u] = u;
    else {
        dp[u] = 0;
        sort(c.begin(),c.end(),greater<pii>());
        node[u] = node[c[0].second];
        for (i = 0; i < c.size(); i++) dp[u] = max(dp[u],max(c[i].first,1)+i);
        cc[u] = c;
        tree[u] = vi(4*cc[u].size());
        build(0,cc[u].size()-1,0,u);
    }
    return 0;
}
int doDFS2(int u,int p,int num) {
    int i;
    dp2[u] = num;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            int x = lower_bound(cc[u].begin(),cc[u].end(),mp(max(dp[v],1),1e9),greater<pii>())-cc[u].begin();
            int y = lower_bound(cc[u].begin(),cc[u].end(),mp(num,1e9),greater<pii>())-cc[u].begin();
            int num2 = 0;
            if (y < x) {
                num2 = max(num2,query(0,cc[u].size()-1,0,y-1,0,u));
                num2 = max(num2,num+y);
                num2 = max(num2,query(0,cc[u].size()-1,y,x-1,0,u)+1);
                num2 = max(num2,query(0,cc[u].size()-1,x+1,cc[u].size()-1,0,u));
            }
            else if (x == y) {
                num2 = max(num2,query(0,cc[u].size()-1,0,y-1,0,u));
                num2 = max(num2,num+y);
                num2 = max(num2,query(0,cc[u].size()-1,y+1,cc[u].size()-1,0,u));
            }
            else {
                num2 = max(num2,query(0,cc[u].size()-1,0,x-1,0,u));
                num2 = max(num2,query(0,cc[u].size()-1,x+1,y-1,0,u)-1);
                num2 = max(num2,num+y-1);
                num2 = max(num2,query(0,cc[u].size()-1,y,cc[u].size()-1,0,u));
            }
            doDFS2(v,u,num2);
        }
    }
    return 0;
}
int main() {
    int i;
    int n,u,v;
    cin >> n;
    for (i = 0; i < n-1; i++) {
        cin >> u >> v;
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    if (n == 1) {
        int l;
        cout << 0 << endl;
        cin >> l;
        cout << "! " << 1 << " " << 1 << endl;
        return 0;
    }

    int j,m = 0;
    doDFS(0,-1);
    doDFS2(0,-1,-1e9);
    for (i = 0; i < n; i++) {
        vi c;
        for (j = 0; j < cc[i].size(); j++) c.pb(cc[i][j].first);
        if (i > 0) c.pb(dp2[i]);
        sort(c.begin(),c.end(),greater<int>());
        for (j = 0; j < c.size(); j++) {
            if (j == 0) m = max(m,max(c[j],1));
            else m = max(m,max(c[0],1)+max(c[j],1)+j-1);
        }
    }
    cout << m << endl;
    int f;
    cin >> f,f--;
    doDFS(f,-1);
    vpii c;
    for (i = 0; i < adjList[f].size(); i++) c.pb(mp(dp[adjList[f][i]],adjList[f][i]));
    sort(c.begin(),c.end(),greater<pii>());
    vpii qq;
    for (i = 0; i < c.size(); i++) {
        int l;
        cout << "? " << node[c[i].second]+1 << endl;
        cin >> l,l--;
        if (l != f) qq.pb(mp(node[c[i].second],l));
        if (qq.size() == 2) break;
    }
    vi ans;
    if (qq.size() == 0) ans.pb(f),ans.pb(f);
    else if (qq.size() == 1) ans.pb(f);
    for (i = 0; i < qq.size(); i++) {
        int u = qq[i].second;
        while (1) {
            int f = 0;
            for (j = 1; j < cc[u].size(); j++) {
                int l;
                cout << "? " << node[cc[u][j].second]+1 << endl;
                cin >> l,l--;
                if (l != u) {
                    u = l;
                    f = 1;
                    break;
                }
            }
            if (!f) {
                ans.pb(u);
                break;
            }
        }
    }
    cout << "! " << ans[0]+1 << " " << ans[1]+1 << endl;

    return 0;
}