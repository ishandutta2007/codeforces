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

vpii adjList[2000];
int need[2000];
int bit[2000],no = 0;
int doDFS(int u,int b) {
    if (bit[u] != -1) {
        if (bit[u] != b) no = 1;
        return 0;
    }
    int i;
    bit[u] = b;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (adjList[u][i].second) doDFS(v,!b);
        else doDFS(v,b);
    }
    return 0;
}
int ways(int N) {
    int i;
    int ans = 1;
    fill(bit,bit+N,-1),no = 0;
    for (i = 0; i < N; i++) {
        if (need[i] != -1) {
            doDFS(i,need[i]);
            if (no) return 0;
        }
    }
    for (i = 0; i < N; i++) {
        if (bit[i] == -1) {
            doDFS(i,0);
            if (no) return 0;
            else ans *= 2,ans %= MOD;
        }
    }
    return ans;
}
int main() {
    string s;
    cin >> s;

    int i,j;
    int ans = 0;
    for (i = 1; i < s.size(); i++) {
        for (j = 0; j < 2*s.size(); j++) need[j] = -1,adjList[j].clear();
        for (j = 0; j < s.size(); j++) {
            if (j < i) need[j] = 0;
            else if (j == i) need[j] = 1;
            else {
                int v = s.size()-1+i-j;
                adjList[j].pb(mp(v,0));
                adjList[v].pb(mp(j,0));
            }
            need[s.size()] = 1;
            int v = s.size()-1-j;
            adjList[j+s.size()].pb(mp(v+s.size(),0));
            adjList[v+s.size()].pb(mp(j+s.size(),0));
            if (s[j] == '0') {
                adjList[j].pb(mp(j+s.size(),0));
                adjList[j+s.size()].pb(mp(j,0));
            }
            else if (s[j] == '1') {
                adjList[j].pb(mp(j+s.size(),1));
                adjList[j+s.size()].pb(mp(j,1));
            }
        }
        ans += ways(2*s.size()),ans %= MOD;
    }
    printf("%d\n",ans);

    return 0;
}