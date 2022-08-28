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

int n,k,tt[40],qq[10];
LLI m[10][41];
vi ss[10];
int check(int c,LLI s) {
    if (c == k) return (s == 0) || ((s+(s & (-s))) == (1LL << n));
    int i,z = ss[c].size()-qq[c]-__builtin_popcountll(s & m[c][0]);
    s &= ~m[c][0],s |= m[c][z];
    for (i = 0; i <= qq[c]; i++) {
        if (!check(c+1,s)) return 0;
        if (i < qq[c]) s ^= (1LL << ss[c][z+i]);
    }
    return 1;
}
int main() {
    int i,j;
    int q;
    cin >> n >> k;
    for (i = 0; i < n; i++) tt[i] = -1;
    for (i = 0; i < k; i++) {
        cin >> q;
        ss[i].resize(q);
        for (j = 0; j < q; j++) {
            cin >> ss[i][j],ss[i][j]--;
            if (tt[ss[i][j]] == -1) tt[ss[i][j]] = i;
        }
    }
    if (n == 1) {
        cout << "ACCEPTED" << endl;
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (tt[i] == -1) {
            cout << "REJECTED" << endl;
            return 0;
        }
        else qq[tt[i]]++;
    }
    for (i = 0; i < k; i++) {
        LLI a = 0;
        for (j = 0; j < ss[i].size(); j++) a |= (1LL << ss[i][j]);
        for (j = 0; j <= ss[i].size(); j++) {
            m[i][j] = a;
            if (j < ss[i].size()) a ^= (1LL << ss[i][j]);
        }
    }    
    if (check(0,0)) cout << "ACCEPTED" << endl;
    else cout << "REJECTED" << endl;
    
    return 0;
}