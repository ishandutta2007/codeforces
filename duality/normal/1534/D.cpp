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
 
int d[2000];
set<pii> S;
int main() {
    int n;
    cin >> n;
 
    int i,j;
    cout << "? " << 1 << endl;
    for (i = 0; i < n; i++) {
        cin >> d[i];
        if (d[i] == 1) S.insert(mp(0,i)),S.insert(mp(i,0));
    }
    int e = 0,o = 0;
    for (i = 1; i < n; i++) {
        if (d[i] & 1) o++;
        else e++;
    }
    if (o < e) {
        for (i = 0; i < n; i++) {
            if (d[i] & 1) {
                int x;
                cout << "? " << i+1 << endl;
                for (j = 0; j < n; j++) {
                    cin >> x;
                    if (x == 1) S.insert(mp(i,j)),S.insert(mp(j,i));
                }
            }
        }
    }
    else {
        for (i = 1; i < n; i++) {
            if (!(d[i] & 1)) {
                int x;
                cout << "? " << i+1 << endl;
                for (j = 0; j < n; j++) {
                    cin >> x;
                    if (x == 1) S.insert(mp(i,j)),S.insert(mp(j,i));
                }
            }
        }
    }
    cout << "!" << endl;
    for (auto it = S.begin(); it != S.end(); it++) {
        if (it->first < it->second) cout << it->first+1 << " " << it->second+1 << endl;
    }
 
    return 0;
}