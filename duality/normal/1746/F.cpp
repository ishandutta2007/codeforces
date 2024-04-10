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

int a[500000];
int t[500000],p[500000],x[500000],l[500000],r[500000],K[500000];
vi all;
int num[600000][50];
int bit[50][600001];
int main() {
    int i;
    int n,q;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),all.pb(a[i]);
    for (i = 0; i < q; i++) {
        scanf("%d",&t[i]);
        if (t[i] == 1) scanf("%d %d",&p[i],&x[i]),p[i]--,all.pb(x[i]);
        else scanf("%d %d %d",&l[i],&r[i],&K[i]),l[i]--,r[i]--;
    }

    sort(all.begin(),all.end());
    all.resize(unique(all.begin(),all.end())-all.begin());
    for (i = 0; i < n; i++) a[i] = lower_bound(all.begin(),all.end(),a[i])-all.begin();
    for (i = 0; i < q; i++) {
        if (t[i] == 1) x[i] = lower_bound(all.begin(),all.end(),x[i])-all.begin();
    }
    int j,k;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (i = 0; i < all.size(); i++) {
        for (j = 0; j < 50; j++) num[i][j] = uniform_int_distribution<int>(0,5000)(rng);
    }
    for (i = 0; i < 50; i++) {
        for (j = 0; j < n; j++) {
            int x = num[a[j]][i];
            for (k = j+1; k <= n; k += k & (-k)) bit[i][k] += x;
        }
    }
    for (i = 0; i < q; i++) {
        if (t[i] == 1) {
            for (j = 0; j < 50; j++) {
                int z = num[x[i]][j]-num[a[p[i]]][j];
                for (k = p[i]+1; k <= n; k += k & (-k)) bit[j][k] += z;
            }
            a[p[i]] = x[i];
        }
        else {
            if (K[i] == 1) printf("YES\n");
            else {
                for (j = 0; j < 50; j++) {
                    int sum = 0;
                    for (k = r[i]+1; k > 0; k -= k & (-k)) sum += bit[j][k];
                    for (k = l[i]; k > 0; k -= k & (-k)) sum -= bit[j][k];
                    if ((sum % K[i]) != 0) break;
                }
                if (j == 50) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    
    return 0;
}