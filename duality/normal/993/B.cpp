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

pii a[12],b[12];
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        scanf("%d %d",&a[i].first,&a[i].second);
        if (a[i].first > a[i].second) swap(a[i].first,a[i].second);
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d",&b[i].first,&b[i].second);
        if (b[i].first > b[i].second) swap(b[i].first,b[i].second);
    }

    int j;
    int f = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((b[j].first == a[i].first) && (b[j].second == a[i].second)) continue;
            if ((b[j].first == a[i].first) || (b[j].first == a[i].second)) {
                if (f == 0) f = b[j].first;
                else if (f != b[j].first) f = -1;
            }
            if ((b[j].second == a[i].first) || (b[j].second == a[i].second)) {
                if (f == 0) f = b[j].second;
                else if (f != b[j].second) f = -1;
            }
        }
    }
    if (f != -1) {
        printf("%d\n",f);
        return 0;
    }
    for (i = 0; i < n; i++) {
        f = 0;
        for (j = 0; j < m; j++) {
            if ((b[j].first == a[i].first) && (b[j].second == a[i].second)) continue;
            if ((b[j].first == a[i].first) || (b[j].first == a[i].second)) {
                if (f == 0) f = b[j].first;
                else if (f != b[j].first) f = -1;
            }
            if ((b[j].second == a[i].first) || (b[j].second == a[i].second)) {
                if (f == 0) f = b[j].second;
                else if (f != b[j].second) f = -1;
            }
        }
        if (f == -1) {
            printf("-1\n");
            return 0;
        }
    }
    for (i = 0; i < m; i++) {
        f = 0;
        for (j = 0; j < n; j++) {
            if ((b[i].first == a[j].first) && (b[i].second == a[j].second)) continue;
            if ((b[i].first == a[j].first) || (b[i].first == a[j].second)) {
                if (f == 0) f = b[i].first;
                else if (f != b[i].first) f = -1;
            }
            if ((b[i].second == a[j].first) || (b[i].second == a[j].second)) {
                if (f == 0) f = b[i].second;
                else if (f != b[i].second) f = -1;
            }
        }
        if (f == -1) {
            printf("-1\n");
            return 0;
        }
    }
    printf("0\n");

    return 0;
}