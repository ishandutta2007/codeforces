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

vi pos;
int bit[100001];
int update(int i,int num,int n) {
    for (i++; i <= n; i += i & (-i)) bit[i] += num;
    return 0;
}
int query(int i) {
    int sum = 0;
    for (i++; i > 0; i -= i & (-i)) sum += bit[i];
    return sum;
}
int main() {
    string s;
    cin >> s;
    int x,y;
    cin >> x >> y;

    int i,n = s.size();
    for (i = 0; i < s.size(); i++) {
        if (s[i] == '?') pos.pb(i),s[i] = '0';
    }
    for (i = 0; i < s.size(); i++) {
        if (s[i] == '1') update(i,1,s.size());
    }
    LLI best = 9e18,c = 0;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            c += (LLI) y*query(i-1);
            c += (LLI) x*(query(n-1)-query(i));
        }
    }
    best = c;
    for (i = 0; i < pos.size(); i++) {
        int u = pos[i];
        s[u] = '1';
        update(u,1,s.size());
        c -= (LLI) y*query(u-1);
        c -= (LLI) x*(query(n-1)-query(u));
        c += (LLI) x*(u-query(u-1));
        c += (LLI) y*(n-u-1-(query(n-1)-query(u)));
        best = min(best,c);
    }
    for (i = 0; i < pos.size(); i++) {
        int u = pos[i];
        s[u] = '0';
        update(u,-1,s.size());
        c += (LLI) y*query(u-1);
        c += (LLI) x*(query(n-1)-query(u));
        c -= (LLI) x*(u-query(u-1));
        c -= (LLI) y*(n-u-1-(query(n-1)-query(u)));
        best = min(best,c);
    }
    cout << best << endl;

    return 0;
}