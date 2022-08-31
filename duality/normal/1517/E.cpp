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
#define MOD 998244353

int a[200000];
LLI pre[200001],pre2[200001];
LLI query(int s,int e) {
    return pre[e+1]-pre[s];
}
LLI query2(int s,int e) {
    LLI x = pre2[e+1]-pre2[s];
    if (s & 1) x *= -1;
    return x;
}
int main() {
    int i;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d",&a[i]),pre[i+1] = pre[i]+a[i],pre2[i+1] = pre2[i]+((i & 1) ? -a[i]:a[i]);

        LLI ans = 0;
        LLI sum = 0;
        for (i = 0; i < n; i++) {
            if (i & 1) sum += a[i];
            else sum -= a[i];
        }
        if (sum != 0) ans++;
        printVar(ans);
        for (i = 0; i < n-1; i++) {
            LLI sum = query(i,n-1);
            if (i & 1) sum -= query2(0,i-1);
            else sum += query2(0,i-1);
            if (sum > 0) ans++;
        }
        printVar(ans);
        for (i = 0; i < n-2; i++) {
            LLI sum = query(i,n-2);
            sum -= a[n-1];
            if (i & 1) sum -= query2(0,i-1);
            else sum += query2(0,i-1);
            if (sum > 0) ans++;
        }
        printVar(ans);
        for (i = 1; i < n; i++) {
            LLI sum = -query(0,i);
            sum += query2(i+1,n-1);
            if (sum > 0) ans++;
        }
        printVar(ans);
        for (i = 2; i < n; i++) {
            LLI sum = -query(1,i);
            sum += a[0];
            sum += query2(i+1,n-1);
            if (sum > 0) ans++;
        }
        printVar(ans);
        int l,r;
        for (l = 0; l < 2; l++) {
            for (r = n-2; r < n; r++) {
                LLI sum = 0;
                if (l == 1) sum += a[0];
                if (r == n-2) sum -= a[n-1];
                if (r >= l+3) {
                    for (i = l+2; i <= r-1; i++) {
                        int s = i-2,e = r-1;
                        if ((e-s) & 1) e--;
                        while (s < e) {
                            int m = (s+e+1) / 2;
                            if ((m-s) & 1) m++;

                            LLI sum2 = sum;
                            sum2 -= query(l,i-1);
                            sum2 += query(m,r);
                            sum2 += query2(i,m-1);
                            if (sum2 > 0) s = m;
                            else e = m-2;
                        }
                        ans += (s-i+2)/2;
                    }
                }
            }
        }
        for (i = 1; i < n-2; i++) {
            LLI sum = query(0,i);
            sum -= query(i+1,n-1);
            if (sum > 0) ans++;
        }
        printf("%I64d\n",ans % MOD);

        /*
        for (i = 0; i < (1 << n); i++) {
            vi c,p;
            int j;
            for (j = 0; j < n; j++) {
                if (i & (1 << j)) c.pb(j);
                else p.pb(j);
            }
            int bad = 0;
            for (j = 2; j < c.size(); j++) {
                if (c[j]-c[j-1] < c[j-1]-c[j-2]) bad = 1;
            }
            int a = 0,b = 0;
            for (j = 1; j < p.size(); j++) {
                if (p[j] == p[j-1]+1) a = 1;
            }
            for (j = 1; j < c.size(); j++) {
                if (c[j] == c[j-1]+1) b = 1;
            }
            if (!(a && b)) bad = 1;
            for (j = 2; j < p.size(); j++) {
                if (p[j]-p[j-1] > p[j-1]-p[j-2]) bad = 1;
            }
            if (!bad) {
                for (j = 0; j < n; j++) {
                    if (i & (1 << j)) cout << 'C';
                    else cout << 'P';
                }
                cout << endl;
            }
        }*/
    }

    return 0;
}