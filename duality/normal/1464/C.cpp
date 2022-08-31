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

LLI occ[60],need[60];
int main() {
    int n;
    LLI T;
    string S;
    cin >> n >> T >> S;

    int i;
    T -= (1 << (S[n-1]-'a')),T += (1 << (S[n-2]-'a'));
    n -= 2,S.pop_back(),S.pop_back();
    if (n == 0) {
        if (T == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    for (i = 0; i < n; i++) {
        T += (1 << (S[i]-'a'));
        occ[S[i]-'a'+1]++;
    }
    if (T < 0) {
        cout << "No" << endl;
        return 0;
    }
    for (i = 0; i < 60; i++) {
        if (T & (1LL << i)) need[i] = 1;
    }
    for (i = 59; i >= 0; i--) {
        need[i] -= min(occ[i],need[i]);
        if (i > 0) need[i-1] += 2*need[i],need[i] = 0;
        else {
            if (need[i] == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}