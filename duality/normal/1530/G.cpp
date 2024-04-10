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

string a,b;
vpii A,B;
int main() {
    int i;
    int t,n,k;
    cin >> t;
    while (t--) {
        cin >> n >> k >> a >> b;
        A.clear(),B.clear();

        if (a == b) {
            cout << 0 << endl;
            continue;
        }
        else if (k == 0) {
            cout << -1 << endl;
            continue;
        }
        int x = 0,y = 0;
        for (char c: a) x += c-'0';
        for (char c: b) y += c-'0';
        if ((x != y) || (k > x)) {
            cout << -1 << endl;
            continue;
        }
        else if (k == x) {
            for (i = n-1; i >= 0; i--) {
                if (a[i] == '1') {
                    reverse(a.begin(),a.begin()+i+1),A.pb(mp(0,i));
                    break;
                }
            }
            for (i = n-1; i >= 0; i--) {
                if (a[i] == '1') {
                    string o = a;
                    reverse(a.begin(),a.begin()+i+1);
                    if (a > o) reverse(a.begin(),a.begin()+i+1);
                    else A.pb(mp(0,i));
                    break;
                }
            }
            for (i = n-1; i >= 0; i--) {
                if (b[i] == '1') {
                    reverse(b.begin(),b.begin()+i+1),B.pb(mp(0,i));
                    break;
                }
            }
            for (i = n-1; i >= 0; i--) {
                if (b[i] == '1') {
                    string o = b;
                    reverse(b.begin(),b.begin()+i+1);
                    if (b > o) reverse(b.begin(),b.begin()+i+1);
                    else B.pb(mp(0,i));
                    break;
                }
            }
        }
        else if (k == 1) {
            int c = 0;
            for (i = 0; i < n; i++) {
                if (a[i] == '1') {
                    if (i == c) c++;
                    else reverse(a.begin()+c,a.begin()+i+1),A.pb(mp(c,i)),c++;
                }
            }
            c = 0;
            for (i = 0; i < n; i++) {
                if (b[i] == '1') {
                    if (i == c) c++;
                    else reverse(b.begin()+c,b.begin()+i+1),B.pb(mp(c,i)),c++;
                }
            }
        }
        else {
            int tt;
            for (tt = 0; tt < 2; tt++) {
                while (1) {
                    for (i = 0; i < n; i++) {
                        if (a[i] == '0') break;
                    }
                    int p = i,c = 0;
                    for (i = p; i < n; i++) {
                        if (a[i] == '1') c++;
                        if (c == k) {
                            reverse(a.begin()+p,a.begin()+i+1),A.pb(mp(p,i));
                            break;
                        }
                    }
                    if (c < k) break;
                }
                if (k > 2) {
                    int j;
                    for (i = 0; i < k-1; i++) {
                        vi v;
                        for (j = n-1; j >= 0; j--) {
                            if (a[j] == '1') v.pb(j);
                            if (v.size() == k+1) break;
                        }
                        reverse(v.begin(),v.end());
                        if (i & 1) {
                            reverse(a.begin()+v[0]+1,a.begin()+v.back()+1);
                            A.pb(mp(v[0]+1,v.back()));
                        }
                        else {
                            reverse(a.begin()+v[0],a.begin()+v.back());
                            A.pb(mp(v[0],v.back()-1));
                        }
                    }
                    vi v;
                    for (j = n-1; j >= 0; j--) {
                        if (a[j] == '1') v.pb(j);
                        if (v.size() == k+2) break;
                    }
                    if (v.size() == k+1) v.pb(-1);
                    reverse(v.begin(),v.end());
                    reverse(a.begin()+v[0]+1,a.begin()+v[v.size()-2]+1),A.pb(mp(v[0]+1,v[v.size()-2]));
                    if (k & 1) {
                        int l = v[0]+1,r = v.back();
                        for (i = 0; i < k; i++) {
                            if (i & 1) reverse(a.begin()+l,a.begin()+r),A.pb(mp(l,r-1));
                            else reverse(a.begin()+l+1,a.begin()+r+1),A.pb(mp(l+1,r));
                        }
                    }
                }
                swap(A,B),swap(a,b);
            }
        }

        if (a == b) {
            cout << A.size()+B.size() << endl;
            reverse(B.begin(),B.end());
            for (pii p: A) cout << p.first+1 << " " << p.second+1 << endl;
            for (pii p: B) cout << p.first+1 << " " << p.second+1 << endl;
        }
        else cout << -1 << endl;
    }

    return 0;
}