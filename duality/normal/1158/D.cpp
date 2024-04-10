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

int x[2000],y[2000];
char s[2000];
int ccw(int a,int b,int c) {
    return (LLI) (x[b]-x[a])*(y[c]-y[a]) > (LLI) (y[b]-y[a])*(x[c]-x[a]);
}
int yes[2000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&x[i],&y[i]);
    scanf("%s",s);

    int j;
    int a = 0,b = 0;
    for (i = 0; i < n; i++) {
        if (y[i] < y[a]) a = i;
    }
    for (i = 0; i < n; i++) {
        if (i != a) {
            b = i;
            for (j = 0; j < n; j++) {
                if ((j != a) && (j != b)) {
                    if (ccw(a,b,j) && (s[0] == 'R')) break;
                    else if (!ccw(a,b,j) && (s[0] == 'L')) break;
                }
            }
            if (j == n) break;
        }
    }
    fill(yes,yes+n,1);
    yes[a] = yes[b] = 0;
    printf("%d %d",a+1,b+1);
    for (i = 0; i < n-2; i++) {
        vi v;
        for (j = 0; j < n; j++) {
            if (yes[j]) v.pb(j);
        }
        if (v.size() == 1) printf(" %d\n",v[0]+1);
        else {
            char c = s[i+1];
            if (c == 'L') {
                int d = v[0];
                for (j = 1; j < v.size(); j++) {
                    if (!ccw(b,d,v[j])) d = v[j];
                }
                printf(" %d",d+1),yes[d] = 0;
                a = b,b = d;
            }
            else {
                int d = v[0];
                for (j = 1; j < v.size(); j++) {
                    if (ccw(b,d,v[j])) d = v[j];
                }
                printf(" %d",d+1),yes[d] = 0;
                a = b,b = d;
            }
        }
    }

    return 0;
}