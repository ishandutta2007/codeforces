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

int l[1000],p[1000];
bitset<500001> poss[1001];
int main() {
    int i;
    int t,h,v;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&h);
        for (i = 0; i < h; i++) scanf("%d",&l[i]);
        scanf("%d",&v);
        for (i = 0; i < v; i++) scanf("%d",&p[i]);

        if (h != v) {
            printf("No\n");
            continue;
        }
        int sl = 0,sp = 0;
        for (i = 0; i < h; i++) sl += l[i],sp += p[i];
        if ((sl & 1) || (sp & 1)) {
            printf("No\n");
            continue;
        }
        poss[0][0] = 1;
        for (i = 0; i < h; i++) poss[i+1] = poss[i] | (poss[i] << l[i]);
        if (!poss[h][sl/2]) {
            printf("No\n");
            continue;
        }
        int u = sl/2;
        vi ll,pp;
        for (i = h-1; i >= 0; i--) {
            if ((u >= l[i]) && poss[i][u-l[i]]) ll.pb(l[i]),u -= l[i];
            else ll.pb(-l[i]);
        }
        poss[0][0] = 1;
        for (i = 0; i < h; i++) poss[i+1] = poss[i] | (poss[i] << p[i]);
        if (!poss[h][sp/2]) {
            printf("No\n");
            continue;
        }
        u = sp/2;
        for (i = h-1; i >= 0; i--) {
            if ((u >= p[i]) && poss[i][u-p[i]]) pp.pb(p[i]),u -= p[i];
            else pp.pb(-p[i]);
        }

        int pos1 = 0,pos2 = 0;
        for (i = 0; i < ll.size(); i++) {
            if (ll[i] > 0) pos1++;
        }
        for (i = 0; i < pp.size(); i++) {
            if (pp[i] > 0) pos2++;
        }
        int s = 0;
        if (pos1 > pos2) swap(ll,pp),s = 1;
        sort(pp.begin(),pp.end(),greater<int>());
        for (i = 0; i < pp.size(); i++) {
            if (pp[i] < 0) {
                reverse(pp.begin(),pp.begin()+i);
                break;
            }
        }
        sort(ll.begin(),ll.end(),greater<int>());
        for (i = 0; i < ll.size(); i++) {
            if (ll[i] < 0) {
                reverse(ll.begin()+i,ll.end());
                break;
            }
        }
        printf("Yes\n");
        int x = 0,y = 0;
        for (i = 0; i < h+v; i++) {
            if (i & 1) y += pp[i/2];
            else x += ll[i/2];
            if (s) printf("%d %d\n",y,x);
            else printf("%d %d\n",x,y);
        }
    }

    return 0;
}