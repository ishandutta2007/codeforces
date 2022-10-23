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

char s[1000][1000],o[1000][1000];
int del[1000][1000];
int dp[1000][1000];
vpii pos[5000];
int main() {
    int i,j;
    int t,n,k;
    scanf("%d",&t);
    while (t--) {
        int z = 0;
        scanf("%d %d",&n,&k);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) scanf(" %c",&s[i][j]);
        }
        for (i = 0; i < n-i-1; i++) {
            for (j = 0; j < n; j++) swap(s[i][j],s[n-i-1][j]);
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                o[i][j] = s[i][j],del[i][j] = 1;
                z += s[i][j] == '1';
            }
        }
        if (z < (n-k+1)*(n-k+1)) {
            printf("NO\n");
            continue;
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i+j < k-1) s[i][j] = '0';
                if (n-i-1+n-j-1 < k-1) s[i][j] = '0';
            }
        }
        int bad = 0;
        for (i = n-1; i >= 0; i--) {
            for (j = 0; j < n; j++) {
                dp[i][j] = (s[i][j] == '0');
                if (s[i][j] != '0') {
                    if (i < n-1) dp[i][j] = max(dp[i][j],dp[i+1][j]);
                    if (j > 0) dp[i][j] = max(dp[i][j],dp[i][j-1]);
                }
                if ((i < n-1) && (j > 0)) dp[i][j] = max(dp[i][j],dp[i+1][j-1]+(s[i][j] == '0'));
                if (dp[i][j] >= k) bad = 1;
                if ((i+j >= k-2) && (n-i-1+n-j-1 >= k-2) && (s[i][j] == '0')) pos[dp[i][j]].pb(mp(i,j));
            }
        }
        if (bad) {
            printf("NO\n");
            for (i = 0; i < 2*n+5; i++) pos[i].clear();
            continue;
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) dp[i][j] *= (s[i][j] == '0') * ((i+j >= k-2) && (n-i-1+n-j-1 >= k-2));
        }
        for (i = 1; i <= k-1; i++) {
            sort(pos[i].begin(),pos[i].end());
            int x = pos[i][0].first,y = pos[i][0].second;
            del[x][y] = 0;
            for (auto [xx,yy]: pos[i]) {
                while ((x < xx) || (y < yy)) {
                    if ((x < xx) && del[x+1][y]) del[x+1][y] = 0,x++;
                    else {
                        assert(del[x][y+1]);
                        del[x][y+1] = 0,y++;
                    }
                }
            }
        }

        z = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (s[i][j] == '0') del[i][j] = 0;
                z += del[i][j];
            }
        }
        z = (n-k+1)*(n-k+1)-z;
        printf("YES\n");
        for (i = n-1; i >= 0; i--) {
            for (j = 0; j < n; j++) {
                if (!del[i][j] && (o[i][j] == '1') && (z > 0)) z--,del[i][j] = 1;
                if (del[i][j]) printf("0");
                else printf("1");
            }
            printf("\n");
        }

        for (i = 0; i < 2*n+5; i++) pos[i].clear();
    }
    
    return 0;
}