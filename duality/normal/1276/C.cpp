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

int a[400000];
vi s;
int occ[400000];
priority_queue<pii> H;
int ans[400000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),s.pb(a[i]);
    sort(s.begin(),s.end());
    s.resize(unique(s.begin(),s.end())-s.begin());
    for (i = 0; i < n; i++) a[i] = lower_bound(s.begin(),s.end(),a[i])-s.begin(),occ[a[i]]++;
    for (i = 0; i < s.size(); i++) H.push(mp(occ[i],i));

    int j,k;
    for (i = n; i >= 1; i--) {
        pii u = H.top();
        int f = 0;
        for (j = u.first; (LLI) /* stupid overflow */ j*j <= i; j++) {
            if ((i % j) == 0) {
                f = 1;
                break;
            }
        }
        if (f) {
            printf("%d\n",i);
            printf("%d %d\n",j,i/j);
            int p = j,q = i/j;
            vpii order;
            for (j = 0; j < q; j++) {
                for (k = 0; k < p; k++) order.pb(mp(k,(j+k) % q));
            }
            int c = 0;
            for (j = 0; j < s.size(); j++) {
                if (occ[j] == p) {
                    for (k = 0; k < occ[j]; k++) ans[order[c].first*q+order[c].second] = s[j],c++;
                }
            }
            for (j = 0; j < s.size(); j++) {
                if (occ[j] != p) {
                    for (k = 0; k < occ[j]; k++) ans[order[c].first*q+order[c].second] = s[j],c++;
                }
            }
            for (j = 0; j < p; j++) {
                for (k = 0; k < q; k++) printf("%d ",ans[j*q+k]);
                printf("\n");
            }
            return 0;
        }
        H.pop();
        H.push(mp(u.first-1,u.second));
        occ[u.second]--;
    }

    return 0;
}