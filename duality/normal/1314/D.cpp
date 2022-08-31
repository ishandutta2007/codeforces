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

int a[80][80];
vpii best[80][80];
int curr[5];
bitset<80> no;
int findBest(int c,int k,int n) {
    if (2*c == k) {
        int i,j,ans = 0;
        no.reset();
        for (i = 0; i < c; i++) no[curr[i]] = 1;
        for (i = 0; i < c; i++) {
            int a = curr[i],b = curr[(i+1) % c];
            for (j = 0; j < best[a][b].size(); j++) {
                if (!no[best[a][b][j].second]) break;
            }
            if (j < best[a][b].size()) ans += best[a][b][j].first;
            else return 1.5e9;
        }
        return ans;
    }

    int i;
    int ans = 1.5e9;
    for (i = 0; i < n; i++) {
        curr[c] = i;
        ans = min(ans,findBest(c+1,k,n));
    }
    return ans;
}
int main() {
    int i,j;
    int n,k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf("%d",&a[i][j]);
    }

    int l;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (l = 0; l < n; l++) {
                if ((l != i) && (l != j)) best[i][j].pb(mp(a[i][l]+a[l][j],l));
            }
            sort(best[i][j].begin(),best[i][j].end());
        }
    }
    curr[0] = 0;
    printf("%d\n",findBest(1,k,n));

    return 0;
}