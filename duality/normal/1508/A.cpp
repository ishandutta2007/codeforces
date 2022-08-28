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

string s[3];
int main() {
    int i,j;
    int t,n;
    cin >> t;
    while (t--) {
        cin >> n >> s[0] >> s[1] >> s[2];

        int c[3];
        c[0] = c[1] = c[2] = 0;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 2*n; j++) {
                if (s[i][j] == '1') c[i]++;
            }
        }
        if (min(c[1],c[2]) >= n) swap(s[0],s[2]),swap(c[0],c[2]);
        else if (min(2*n-c[1],2*n-c[2]) >= n) swap(s[0],s[2]),swap(c[0],c[2]);
        else if (min(c[0],c[2]) >= n) swap(s[1],s[2]),swap(c[1],c[2]);
        else if (min(2*n-c[0],2*n-c[2]) >= n) swap(s[1],s[2]),swap(c[1],c[2]);
        if (min(c[0],c[1]) >= n) {
            vi a,b;
            for (i = 0; i < 2*n; i++) {
                if (s[0][i] == '1') a.pb(i);
                if (s[1][i] == '1') b.pb(i);
            }
            string ans;
            int x = 0,y = 0;
            for (i = 0; i < n; i++) {
                while (x < a[i]) ans += s[0][x],x++;
                while (y < b[i]) ans += s[1][y],y++;
                ans += '1',x++,y++;
            }
            while (x < 2*n) ans += s[0][x],x++;
            while (y < 2*n) ans += s[1][y],y++;
            cout << ans << endl;
        }
        else {
            vi a,b;
            for (i = 0; i < 2*n; i++) {
                if (s[0][i] == '0') a.pb(i);
                if (s[1][i] == '0') b.pb(i);
            }
            string ans;
            int x = 0,y = 0;
            for (i = 0; i < n; i++) {
                while (x < a[i]) ans += s[0][x],x++;
                while (y < b[i]) ans += s[1][y],y++;
                ans += '0',x++,y++;
            }
            while (x < 2*n) ans += s[0][x],x++;
            while (y < 2*n) ans += s[1][y],y++;
            cout << ans << endl;
        }
    }

    return 0;
}