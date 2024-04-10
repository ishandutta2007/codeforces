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
#define MOD 998244353

vi adjList[150000],adjList2[150000];
int parent[150000],size[150000],disc[150000],fin[150000],num = 0;
int doDFS(int u,int p) {
    int i;
    parent[u] = p,size[u] = 1;
    disc[u] = num++;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) size[u] += doDFS(v,u),adjList2[u].pb(v);
    }
    fin[u] = num;
    return size[u];
}
int bit[150001],all = 0;
int update(int i,int num,int n) {
    if (i == 0) {
        all += num;
        if (all >= MOD) all -= MOD;
        return 0;
    }
    for (i++; i <= n; i += i & (-i)) {
        bit[i] += num;
        if (bit[i] >= MOD) bit[i] -= MOD;
    }
    return 0;
}
int query(int i) {
    int sum = all;
    for (i++; i > 0; i -= i & (-i)) {
        sum += bit[i];
        if (sum >= MOD) sum -= MOD;
    }
    return sum;
}
int inv(LLI n) {
    int e = MOD-2;
    LLI r = 1;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n *= n,n %= MOD;
    }
    return r;
}
vi big;
int bigSum[150000];
int main() {
    int i,j;
    int n,q;
    int t,u,v,d;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    int B = sqrt(n);
    doDFS(0,-1);
    for (i = 0; i < n; i++) {
        if (adjList[i].size() > B) big.pb(i);
    }
    int invn = inv(n);
    for (i = 0; i < q; i++) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d",&u,&d),u--;
            if (adjList[u].size() > B) bigSum[u] += d,bigSum[u] %= MOD;
            else {
                update(0,d,n);
                for (j = 0; j < adjList[u].size(); j++) {
                    int v = adjList[u][j];
                    if (v != parent[u]) {
                        int x = ((LLI) size[v]*d) % MOD;
                        update(0,x,n),update(disc[v],MOD-x,n),update(fin[v],x,n);
                    }
                    else {
                        int x = ((LLI) (n-size[u])*d) % MOD;
                        update(disc[u],x,n),update(fin[u],MOD-x,n);
                    }
                }
            }
        }
        else {
            scanf("%d",&u),u--;
            int ans = query(disc[u]);
            for (j = 0; j < big.size(); j++) {
                v = big[j];
                if (u == v) ans += ((LLI) bigSum[v]*n) % MOD;
                else if ((disc[u] >= disc[v]) && (disc[u] < fin[v])) {
                    int l = 0,r = adjList2[v].size()-1;
                    while (l < r) {
                        int m = (l+r+1) / 2;
                        if (disc[u] >= disc[adjList2[v][m]]) l = m;
                        else r = m-1;
                    }
                    ans += ((LLI) (n-size[adjList2[v][l]])*bigSum[v]) % MOD;
                }
                else ans += ((LLI) size[v]*bigSum[v]) % MOD;
                if (ans >= MOD) ans -= MOD;
            }
            printf("%I64d\n",((LLI) ans*invn) % MOD);
        }
    }

    return 0;
}