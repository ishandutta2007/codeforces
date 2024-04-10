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

int A[250][250],r[250],c[250],B[250][250];
priority_queue<pair<int,pii> > H1,H2;
int main() {
    int i,j;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf("%d",&A[i][j]),r[i] = max(r[i],--A[i][j]),c[j] = max(c[j],A[i][j]);
        fill(B[i],B[i]+m,-1);
    }
    sort(r,r+n),sort(c,c+m);

    j = n-1;
    int k = m-1,l,x = -1,y = -1;
    for (i = n*m-1; i >= 0; i--) {
        if ((j >= 0) && (r[j] == i) && (k >= 0) && (c[k] == i)) {
            B[++y][++x] = i,j--,k--;
            for (l = 0; l < y; l++) H1.push(mp(l-x,mp(x,l)));
            for (l = 0; l < x; l++) H2.push(mp(l-y,mp(l,y)));
        }
        else if ((j >= 0) && (r[j] == i)) {
            B[++y][x] = i,j--;
            for (l = 0; l < x; l++) H2.push(mp(l-y,mp(l,y)));
        }
        else if ((k >= 0) && (c[k] == i)) {
            B[y][++x] = i,k--;
            for (l = 0; l < y; l++) H1.push(mp(l-x,mp(x,l)));
        }
        else {
            if (!H1.empty()) B[H1.top().second.second][H1.top().second.first] = i,H1.pop();
            else B[H2.top().second.second][H2.top().second.first] = i,H2.pop();
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) printf("%d ",B[i][j]+1);
        printf("\n");
    }

    return 0;
}