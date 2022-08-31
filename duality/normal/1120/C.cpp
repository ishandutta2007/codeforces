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

int Z[5000][5000];
int dp[5001];
int main() {
    int n,a,b;
    string s;
    cin >> n >> a >> b >> s;

    int i,j;
    reverse(s.begin(),s.end());
    for (i = 0; i < s.size(); i++) {
        int l = 0,r = 0;
        string t;
        for (j = i; j < s.size(); j++) t += s[j];
        Z[i][i] = 0;
        for (j = 1; j < t.size(); j++) {
            if (j > r) {
                l = r = j;
                while ((r < t.size()) && (t[r-l] == t[r])) r++;
                Z[i][j+i] = (r--)-l;
            }
            else {
                if (Z[i][j-l+i] < (r-j+1)) Z[i][j+i] = Z[i][j-l+i];
                else {
                    l = j;
                    while ((r < t.size()) && (t[r-l] == t[r])) r++;
                    Z[i][j+i] = (r--)-l;
                }
            }
            //cout<<Z[i][j+i]<<" ";
        }//cout<<endl;
    }
    for (i = n-1; i >= 0; i--) {
        int m = 0;
        for (j = i; j < n-1; j++) m = max(m,min(Z[i][j+1],j-i+1));
        //cout<<m<<endl;
        dp[i] = dp[i+1]+a;
        for (j = i+1; j <= i+m; j++) dp[i] = min(dp[i],dp[j]+b);
    }
    printf("%d\n",dp[0]);

    return 0;
}