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

int n,m;
int a[1501][1501],b[1501][1501];
int order[1500],used[1500];
bool comp(int x,int y) {
    int i;
    for (i = 0; i <= m; i++) {
        if (a[x][i] != a[y][i]) return a[x][i] < a[y][i];
    }
    return 0;
}
int bad[1500];
int del[1500];
vi vv;
int main() {
    int i,j;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf("%d",&a[i][j]);
        a[i][m] = i;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf("%d",&b[i][j]);
    }

    for (i = 0; i < n; i++) order[i] = i;
    sort(order,order+n,comp);
    printArr(order,n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) a[n][j] = b[i][j];
        a[n][m] = -1;
        int p = lower_bound(order,order+n,n,comp)-order;
        while ((p < n) && used[p]) p++;
        if (p == n) {
            printf("-1\n");
            return 0;
        }
        for (j = 0; j < m; j++) {
            if (a[order[p]][j] != b[i][j]) {
                printf("-1\n");
                return 0;
            }
        }
        b[i][m] = order[p];
        used[p] = 1;
    }
    print2dArr(b,n,m+1);
    for (i = 0; i <= m; i++) {
        for (j = 1; j < n; j++) {
            if (b[j-1][i] > b[j][i]) bad[i]++;
        }
    }
    while (1) {
        for (i = 0; i <= m; i++) {
            if (bad[i] == 0) break;
        }
        if (i > m) break;
        int x = i;
        for (i = 1; i < n; i++) {
            if (b[i-1][x] < b[i][x]) {
                if (!del[i]) {
                    del[i] = 1;
                    for (j = 0; j <= m; j++) {
                        if (b[i-1][j] > b[i][j]) bad[j]--;
                    }
                }
            }
        }
        bad[x] = -1e9;
        vv.pb(x);
    }
    for (i = 1; i < n; i++) {
        if (!del[i]) {
            printf("-1\n");
            return 0;
        }
    }
    reverse(vv.begin(),vv.end());
    for (i = 0; i < vv.size(); i++) {
        if (vv[i] == m) break;
    }
    printf("%d\n",vv.size()-i-1);
    for (i++; i < vv.size(); i++) printf("%d ",vv[i]+1);
    printf("\n");

    return 0;
}