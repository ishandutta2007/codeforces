#define DEBUG 1

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

int num[10000];
int main() {
    int n,k;
    cin >> n >> k;

    int i,j,a,b,c,d,e,f;
    cout << "and 1 2" << endl;
    cin >> a;
    cout << "and 1 3" << endl;
    cin >> b;
    cout << "and 2 3" << endl;
    cin >> c;
    cout << "or 1 2" << endl;
    cin >> d;
    cout << "or 1 3" << endl;
    cin >> e;
    cout << "or 2 3" << endl;
    cin >> f;
    for (i = 0; i < 30; i++) {
        int ff = 0;
        if (a & (1 << i)) num[0] |= (1 << i),num[1] |= (1 << i),ff = 1;
        if (b & (1 << i)) num[0] |= (1 << i),num[2] |= (1 << i),ff = 1;
        if (c & (1 << i)) num[1] |= (1 << i),num[2] |= (1 << i),ff = 1;
        if (!ff) {
            if ((d & (1 << i)) && (e & (1 << i))) num[0] |= (1 << i);
            if ((d & (1 << i)) && (f & (1 << i))) num[1] |= (1 << i);
            if ((e & (1 << i)) && (f & (1 << i))) num[2] |= (1 << i);
        }
    }
    for (i = 3; i < n; i++) {
        int x,y;
        cout << "and 1 " << i+1 << endl;
        cin >> x;
        cout << "or 1 " << i+1 << endl;
        cin >> y;
        for (j = 0; j < 30; j++) {
            if (num[0] & (1 << j)) {
                if (x & (1 << j)) num[i] |= (1 << j);
            }
            else {
                if (y & (1 << j)) num[i] |= (1 << j);
            }
        }
    }
    sort(num,num+n);
    cout << "finish " << num[k-1] << endl;

    return 0;
}