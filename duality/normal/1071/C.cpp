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

int a[100000];
vpii ops;
vpii sol;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);

    int j;
    if (n <= 10) {
        for (i = 0; i < n; i++) {
            for (j = i+2; j < n; j += 2) ops.pb(mp(i,j));
        }
        int mm = 0;
        for (i = 0; i < n; i++) {
            if (a[i]) mm |= (1 << i);
        }
        int best = -1,num = 1e9;
        for (i = 0; i < (1 << ops.size()); i++) {
            int m = 0,b = 0;
            for (j = 0; j < ops.size(); j++) {
                if (i & (1 << j)) {
                    m ^= (1 << ops[j].first) | (1 << ops[j].second) | (1 << ((ops[j].first+ops[j].second)/2));
                    b++;
                }
            }
            if (m == mm) {
                if (b < num) best = i,num = b;
            }
        }
        if (best == -1) {
            printf("NO\n");
            return 0;
        }
        for (i = 0; i < ops.size(); i++) {
            if (best & (1 << i)) sol.pb(ops[i]);
        }
        printf("YES\n%d\n",sol.size());
        for (i = 0; i < sol.size(); i++) printf("%d %d %d\n",sol[i].first+1,(sol[i].first+sol[i].second)/2+1,sol[i].second+1);
        return 0;
    }

    int p = n-1;
    while (p >= 11) {
        if (!a[p]) p--;
        else {
            if (a[p-1] && a[p-2]) {
                sol.pb(mp(p-2,p));
                a[p] ^= 1,a[p-1] ^= 1,a[p-2] ^= 1;
                p -= 3;
            }
            else if (a[p-2] && !a[p-1]) {
                sol.pb(mp(p-4,p));
                a[p] ^= 1,a[p-2] ^= 1,a[p-4] ^= 1;
                p -= 3;
            }
            else if (!a[p-1] && !a[p-2]) {
                sol.pb(mp(p-6,p));
                a[p] ^= 1,a[p-3] ^= 1,a[p-6] ^= 1;
                p -= 3;
            }
            else {
                if (!a[p-3] && !a[p-4] && !a[p-5]) {
                    sol.pb(mp(p-7,p-1)),sol.pb(mp(p-8,p));
                    a[p-7] ^= 1,a[p-4] ^= 1,a[p-1] ^= 1;
                    a[p-8] ^= 1,a[p-4] ^= 1,a[p] ^= 1;
                    p -= 6;
                }
                else if ((a[p-3]+a[p-4]+a[p-5]) == 1) {
                    int q;
                    if (a[p-3]) q = p-3;
                    else if (a[p-4]) q = p-4;
                    else q = p-5;
                    sol.pb(mp(2*q-p,p)),sol.pb(mp(p-11,p-1));
                    a[2*q-p] ^= 1,a[q] ^= 1,a[p] ^= 1;
                    a[p-11] ^= 1,a[p-6] ^= 1,a[p-1] ^= 1;
                    p -= 6;
                }
                else if ((a[p-3]+a[p-4]+a[p-5]) == 2) {
                    int q,r;
                    if (!a[p-3]) q = p-4,r = p-5;
                    else if (!a[p-4]) q = p-3,r = p-5;
                    else q = p-3,r = p-4;
                    sol.pb(mp(2*q-p,p)),sol.pb(mp(2*r-(p-1),p-1));
                    a[2*q-p] ^= 1,a[q] ^= 1,a[p] ^= 1;
                    a[2*r-(p-1)] ^= 1,a[r] ^= 1,a[p-1] ^= 1;
                    p -= 6;
                }
                else {
                    sol.pb(mp(p-5,p-1)),sol.pb(mp(p-8,p));
                    a[p-5] ^= 1,a[p-3] ^= 1,a[p-1] ^= 1;
                    a[p-8] ^= 1,a[p-4] ^= 1,a[p] ^= 1;
                    p -= 6;
                }
            }
        }
    }
    for (i = 0; i < 11; i++) {
        for (j = i+2; j < min(11,i+7); j += 2) ops.pb(mp(i,j));
    }
    int mm = 0;
    for (i = 0; i < 11; i++) {
        if (a[i]) mm |= (1 << i);
    }
    int best = -1,num = 1e9;
    for (i = 0; i < (1 << ops.size()); i++) {
        int m = 0,b = 0;
        for (j = 0; j < ops.size(); j++) {
            if (i & (1 << j)) {
                m ^= (1 << ops[j].first) | (1 << ops[j].second) | (1 << ((ops[j].first+ops[j].second)/2));
                b++;
            }
        }
        if (m == mm) {
            if (b < num) best = i,num = b;
        }
    }
    if (best == -1) {
        printf("NO\n");
        return 0;
    }
    for (i = 0; i < ops.size(); i++) {
        if (best & (1 << i)) sol.pb(ops[i]);
    }
    printf("YES\n%d\n",sol.size());
    for (i = 0; i < sol.size(); i++) printf("%d %d %d\n",sol[i].first+1,(sol[i].first+sol[i].second)/2+1,sol[i].second+1);

    return 0;
}