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
 
 
int main() {
    int n,k;
    cin >> n >> k;
    if (!(k & 1) && (n & 1)) {
        cout << -1 << endl;
        return 0;
    }
 
    int i,j,ans = 0,x;
    if (k > n-k) {
        if ((n & 1) || !(k & 1)) {
            cout << "?";
            for (i = 0; i < k; i++) cout << " " << i+1;
            cout << endl;
            cin >> x,ans ^= x;
            int l = k;
            while (l < n) {
                int d = min((n-l)/2,n-k);
                cout << "?";
                for (i = l; i < l+d; i++) cout << " " << i+1;
                for (i = 0; i < k-d; i++) cout << " " << i+1;
                cout << endl;
                cin >> x,ans ^= x;
                cout << "?";
                for (i = l+d; i < l+2*d; i++) cout << " " << i+1;
                for (i = 0; i < k-d; i++) cout << " " << i+1;
                cout << endl;
                cin >> x,ans ^= x;
                l += 2*d;
            }
        }
        else {
            int l = 0;
            while (l < n) {
                int d = min((n-l)/2,n-k);
                cout << "?";
                for (i = l; i < l+d; i++) cout << " " << i+1;
                for (i = l+2*d; i < l+d+k; i++) cout << " " << (i % n)+1;
                cout << endl;
                cin >> x,ans ^= x;
                cout << "?";
                for (i = l+d; i < l+2*d; i++) cout << " " << i+1;
                for (i = l+2*d; i < l+d+k; i++) cout << " " << (i % n)+1;
                cout << endl;
                cin >> x,ans ^= x;
                l += 2*d;
            }
        }
    }
    else {
        int q = (n+k-1)/k;
        if ((q*k-n) & 1) q++;
        if (q*k == n) {
            int l = 0;
            while (l+k <= n) {
                cout << "?";
                for (i = l; i < l+k; i++) cout << " " << i+1;
                cout << endl;
                cin >> x,ans ^= x;
                l += k;
            }
        }
        else {
            int p = (q*k-n)/2,l = p;
            for (i = 0; i < 3; i++) {
                cout << "?";
                for (j = 0; j < p; j++) cout << " " << j+1;
                for (j = 0; j < k-p; j++) cout << " " << l+1,l++;
                cout << endl;
                cin >> x,ans ^= x;
            }
            while (l+k <= n) {
                cout << "?";
                for (i = l; i < l+k; i++) cout << " " << i+1;
                cout << endl;
                cin >> x,ans ^= x;
                l += k;
            }
        }
    }
    cout << "! " << ans << endl;
 
    return 0;
}