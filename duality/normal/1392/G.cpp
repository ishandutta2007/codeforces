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

int k;
char s1[20],s2[20];
int a[1000000],b[1000000];
int p[1000001][20],m1[1000001],m2[1000001];
int dist[1 << 20],rr[1 << 20];
int doDFS(int l,int m,int r,int d) {
    if (d >= dist[m]) return 0;

    int i;
    dist[m] = d,rr[m] = r;
    for (i = l; i < k; i++) doDFS(i+1,m^(1 << i),r,d+1);
    return 0;
}
int main() {
    int i;
    int n,m;
    int c = 0,d = 0;
    scanf("%d %d %d",&n,&m,&k);
    for (i = 0; i < k; i++) scanf(" %c",&s1[i]),c += (s1[i] == '1');
    for (i = 0; i < k; i++) scanf(" %c",&s2[i]),d += (s2[i] == '1');
    for (i = 0; i < n; i++) scanf("%d %d",&a[i],&b[i]),a[i]--,b[i]--;

    int j;
    for (i = 0; i < k; i++) {
        p[n][i] = i;
        if (s1[i] == '1') m1[n] |= (1 << i);
        if (s2[i] == '1') m2[n] |= (1 << i);
    }
    for (i = n-1; i >= 0; i--) {
        copy(p[i+1],p[i+1]+k,p[i]);
        swap(p[i][a[i]],p[i][b[i]]);
        int mm = 0,mm2 = 0;
        for (j = 0; j < k; j++) {
            if (m1[n] & (1 << j)) mm |= (1 << p[i][j]);
            if (m2[n] & (1 << j)) mm2 |= (1 << p[i][j]);
        }
        m1[i] = mm,m2[i] = mm2;
    }
    int ans = 50;
    pii sol;
    for (i = 0; i < (1 << k); i++) dist[i] = 50;
    for (i = n-m; i >= 0; i--) {
        doDFS(0,m2[i+m],i+m,0);
        if (dist[m1[i]] < ans) ans = dist[m1[i]],sol = mp(i,rr[m1[i]]);
    }
    printf("%d\n%d %d\n",k-ans,sol.first+1,sol.second);

    return 0;
}