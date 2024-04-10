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

int a[200000];
vpii S;
int ans[200000],ans2[200000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),a[i]--;

    int s = 0;
    for (i = 0; i < n; i++) {
        if (a[i] == 0) break;
    }
    s = i;
    rotate(a,a+s,a+n);
    int c = 0;
    for (i = 1; i < n; i++) {
        if (S.empty()) S.pb(mp(a[i],1)),c = 1;
        else {
            int x = 0,c2 = 0;
            while (!S.empty() && (a[i] < S.back().first)) c2 = max(c2+1,S.back().second),S.pop_back(),x++;
            c = max(c,c2+(int) S.size()+1);
            if (S.empty()) S.pb(mp(a[i],c));
            else S.pb(mp(a[i],c2+1));
        }
        ans[i] = c;
    }
    S.clear(),c = 0;
    for (i = n-1; i >= 1; i--) {
        if (S.empty()) S.pb(mp(a[i],1)),c = 1;
        else {
            int x = 0,c2 = 0;
            while (!S.empty() && (a[i] < S.back().first)) c2 = max(c2+1,S.back().second),S.pop_back(),x++;
            c = max(c,c2+(int) S.size()+1);
            if (S.empty()) S.pb(mp(a[i],c));
            else S.pb(mp(a[i],c2+1));
        }
        ans2[i] = c;
    }
    int bi = 0,b = 1e9;
    for (i = 0; i < n; i++) {
        int x = max(ans[i],ans2[i+1]);
        if (x < b) b = x,bi = i;
    }
    printf("%d %d\n",b+1,(bi+s+1) % n);

    return 0;
}