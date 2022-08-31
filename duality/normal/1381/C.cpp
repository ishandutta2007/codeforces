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

int b[100000],a[100000];
vi occ[100005];
priority_queue<pii> H;
int main() {
    int i;
    int t,n,x,y;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&n,&x,&y);
        for (i = 0; i < n; i++) scanf("%d",&b[i]),occ[b[i]].pb(i);

        int z = -1,xx = x;
        fill(a,a+n,-1);
        for (i = 1; i <= n+1; i++) {
            H.push(mp(occ[i].size(),i));
            if (occ[i].empty()) z = i;
        }
        debug "here";
        for (i = 0; i < x; i++) {
            int u = H.top().second;
            H.pop();
            a[occ[u].back()] = b[occ[u].back()];
            printVar(occ[u].back());
            occ[u].pop_back(),H.push(mp(occ[u].size(),u));
        }
        x = n-x;
        if (2*H.top().first > x+(n-y)) printf("NO\n");
        else {
            while (2*H.top().first > x) {
                int u = H.top().second;
                H.pop();
                a[occ[u].back()] = b[occ[u].back()];
                occ[u].pop_back(),H.push(mp(occ[u].size(),u));
                x--;
            }
            while (x > 0) {
                int u = H.top().second;
                H.pop();
                int v = H.top().second;
                H.pop();
                if (x != 3) {
                    a[occ[u].back()] = b[occ[v].back()];
                    a[occ[v].back()] = b[occ[u].back()];
                    occ[u].pop_back(),H.push(mp(occ[u].size(),u));
                    occ[v].pop_back(),H.push(mp(occ[v].size(),v));
                    x -= 2;
                }
                else {
                    int w = H.top().second;
                    H.pop();
                    a[occ[u].back()] = b[occ[v].back()];
                    a[occ[v].back()] = b[occ[w].back()];
                    a[occ[w].back()] = b[occ[u].back()];
                    x = 0;
                }
            }
            printArr(a,n);
            int c = n-y;
            int cc = 0;
            for (i = 0; i < n; i++) {
                if (a[i] == b[i]) cc++;
            }
            for (i = 0; i < n; i++) {
                if ((a[i] == b[i]) && (cc > xx)) a[i] = z,cc--,c--;
            }
            for (i = 0; i < n; i++) {
                if ((a[i] != z) && (a[i] != b[i]) && (c > 0)) a[i] = z,c--;
            }
            printf("YES\n");
            for (i = 0; i < n; i++) printf("%d ",a[i]);
            printf("\n");
        }

        for (i = 0; i < n+5; i++) occ[i].clear();
        while (!H.empty()) H.pop();
    }

    return 0;
}