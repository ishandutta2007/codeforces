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

int n,pt,flip[300],ans[300];
char ss[300];
pii query(int l,int r) {
    l++,r++;
    int i,t;
    assert(((l-1) & 1) != ((n-r) & 1));
    cout << "? " << l << " " << r << endl;
    cin >> t;/*
    if (rand() & 1) {
        for (i = 0; i < r; i++) ss[i] ^= '0'^'1';
    }
    else {
        for (i = l-1; i < n; i++) ss[i] ^= '0'^'1';
    }
    t = 0;
    for (i = 0; i < n; i++) t += (ss[i] == '1');
    cout<<t<<endl;*/
    int c = 0;
    if (((pt+r) & 1) == (t & 1)) {
        for (i = 0; i < r; i++) flip[i] ^= 1;
        c = 1;
    }
    else {
        for (i = l-1; i < n; i++) flip[i] ^= 1;
        c = 0;
    }
    pt = t;
    return mp(t,c);
}
int num[300];
int main() {
    cin >> n >> pt;
    int o = pt;
    if (n == 1) {
        cout << "! " << pt << endl;
        return 0;
    }

    int i;
    for (i = 0; i < n; i++) {
        int x = (n & 1) ? 1:0;
        if (i < x) continue;
        int fl = 0,fr = 0;
        while (1) {
            pii p = query(i-x,i);
            if (p.second == 0) fl ^= 1;
            else fr ^= 1;
            if (!fl && fr) {
                num[i] = p.first;
                break;
            }
        }
        while (1) {
            pii p = query(i-x,i);
            if (p.second == 0) fl ^= 1;
            else fr ^= 1;
            if (!fl && !fr) break;
        }
    }
    if (n & 1) {
        i = 0;
        int fl = 0,fr = 0;
        while (1) {
            pii p = query(1,n-1);
            if (p.second == 0) fl ^= 1;
            else fr ^= 1;
            if (fl && fr) {
                num[i] = p.first;
                break;
            }
        }
    }
    for (i = 0; i < n; i++) ans[i] = ((o-(num[i]-(i+1)))/2) & 1;
    for (i = n-1; i >= 1; i--) ans[i] ^= ans[i-1];
    cout << "! ";
    for (i = 0; i < n; i++) cout << ans[i];
    cout << endl;

    return 0;
}