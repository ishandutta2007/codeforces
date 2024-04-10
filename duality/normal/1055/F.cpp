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

LLI x[1000000];
struct inter { int l1,r1,l2,r2; };
vector<inter> vv,vv2;
int main() {
    int i;
    int n,p;
    LLI kk,w;
    scanf("%d %I64d",&n,&kk);
    for (i = 1; i < n; i++) scanf("%d %I64d",&p,&w),x[i] = x[p-1]^w;
    sort(x,x+n);

    int j;
    LLI ans = 0;
    for (i = 61; i >= 0; i--) {
        LLI c = 0,cc = 0;
        for (j = 0; j < n; j++) {
            if (j == 0) cc = 1;
            else {
                if ((x[j-1] >> i) == (x[j] >> i)) cc++;
                else c += cc*cc,cc = 1;
            }
        }
        c += cc*cc;
        if (c < kk) {
            kk -= c,ans |= (1LL << i);
            break;
        }
    }
    if (i == -1) {
        printf("0\n");
        return 0;
    }
    int b = i;
    vpii v;
    for (i = 0; i < n; i++) {
        LLI m = x[i] >> b;
        if (v.empty()) v.pb(mp(i,i));
        else {
            if ((x[i-1] >> b) == m) v.back().second++;
            else v.pb(mp(i,i));
        }
    }
    for (i = 1; i < v.size(); i++) {
        if ((x[v[i-1].first] >> b) == ((x[v[i].first] >> b)^1)) vv.pb((inter){v[i-1].first,v[i-1].second,v[i].first,v[i].second});
    }
    int k;
    for (i = b-1; i >= 0; i--) {
        LLI c = 0;
        for (j = 0; j < vv.size(); j++) {
            int a = 0,b = 0,a2 = 0,b2 = 0;
            for (k = vv[j].l1; k <= vv[j].r1; k++) {
                if ((x[k] >> i) & 1) b++;
                else a++;
            }
            for (k = vv[j].l2; k <= vv[j].r2; k++) {
                if ((x[k] >> i) & 1) b2++;
                else a2++;
            }
            c += (LLI) a*a2+(LLI) b*b2;
        }
        c *= 2;
        for (j = 0; j < vv.size(); j++) {
            for (k = vv[j].l1; k <= vv[j].r1; k++) {
                if ((x[k] >> i) & 1) break;
            }
            int p = k;
            for (k = vv[j].l2; k <= vv[j].r2; k++) {
                if ((x[k] >> i) & 1) break;
            }
            if (c < kk) {
                vv2.pb((inter){vv[j].l1,p-1,k,vv[j].r2});
                vv2.pb((inter){p,vv[j].r1,vv[j].l2,k-1});
            }
            else {
                vv2.pb((inter){vv[j].l1,p-1,vv[j].l2,k-1});
                vv2.pb((inter){p,vv[j].r1,k,vv[j].r2});
            }
        }
        vv.clear();
        for (j = 0; j < vv2.size(); j++) {
            if ((vv2[j].r1 >= vv2[j].l1) && (vv2[j].r2 >= vv2[j].l2)) vv.pb(vv2[j]);
        }
        vv2.clear();
        if (c < kk) kk -= c,ans |= (1LL << i);
    }
    printf("%I64d\n",ans);


    return 0;
}