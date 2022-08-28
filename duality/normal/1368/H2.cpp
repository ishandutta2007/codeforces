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

int l[100000],r[100000],u[100000],d[100000];
struct data {
    int n;
    int *u,*d;
    int tree[1 << 18][2][2][2][2],sum[1 << 18][2],lazy[1 << 18][2];
    int prop(int s,int e,int i) {
        int a,b;
        if (lazy[i][0] && lazy[i][1]) {
            for (a = 0; a < 2; a++) {
                for (b = 0; b < 2; b++) {
                    swap(tree[i][0][0][a][b],tree[i][1][1][a][b]);
                    swap(tree[i][0][1][a][b],tree[i][1][0][a][b]);
                }
            }
        }
        else if (lazy[i][0]) {
            for (a = 0; a < 2; a++) {
                for (b = 0; b < 2; b++) {
                    swap(tree[i][0][0][a][b],tree[i][1][0][a][b]);
                    swap(tree[i][0][1][a][b],tree[i][1][1][a][b]);
                }
            }
        }
        else if (lazy[i][1]) {
            for (a = 0; a < 2; a++) {
                for (b = 0; b < 2; b++) {
                    swap(tree[i][0][0][a][b],tree[i][0][1][a][b]);
                    swap(tree[i][1][0][a][b],tree[i][1][1][a][b]);
                }
            }
        }
        if (lazy[i][0]) sum[i][0] = e-s+1-sum[i][0];
        if (lazy[i][1]) sum[i][1] = e-s+1-sum[i][1];
        if (s != e) {
            lazy[2*i+1][0] ^= lazy[i][0],lazy[2*i+1][1] ^= lazy[i][1];
            lazy[2*i+2][0] ^= lazy[i][0],lazy[2*i+2][1] ^= lazy[i][1];
        }
        lazy[i][0] = lazy[i][1] = 0;
        return 0;
    }
    int com(int s,int e,int i) {
        int a,b,c,d,p,q;
        for (a = 0; a < 2; a++) {
            for (b = 0; b < 2; b++) {
                for (c = 0; c < 2; c++) {
                    for (d = 0; d < 2; d++) {
                        int x = 1e9;
                        for (p = 0; p < 2; p++) {
                            for (q = 0; q < 2; q++) x = min(x,tree[2*i+1][a][b][c][p]+tree[2*i+2][a][b][q][d]+n*(p != q));
                        }
                        tree[i][a][b][c][d] = x;
                    }
                }
            }
        }
        sum[i][0] = sum[2*i+1][0]+sum[2*i+2][0];
        sum[i][1] = sum[2*i+1][1]+sum[2*i+2][1];
        return 0;
    }
    int build(int s,int e,int i) {
        if (s == e) {
            int a,b,c;
            for (a = 0; a < 2; a++) {
                for (b = 0; b < 2; b++) {
                    for (c = 0; c < 2; c++) {
                        tree[i][a][b][c][c] = ((u[s]^a) != c)+((d[s]^b) != c);
                        tree[i][a][b][c][!c] = 1e9;
                    }
                }
            }
            sum[i][0] = u[s],sum[i][1] = d[s];
            return 0;
        }

        int mid = (s+e) / 2;
        build(s,mid,2*i+1),build(mid+1,e,2*i+2);
        com(s,e,i);
        return 0;
    }
    int update(int s,int e,int as,int ae,int i,int t) {
        prop(s,e,i);
        if ((s > ae) || (e < as)) return 0;
        else if ((s >= as) && (e <= ae)) {
            lazy[i][t] ^= 1;
            prop(s,e,i);
            return 0;
        }

        int mid = (s+e) / 2;
        update(s,mid,as,ae,2*i+1,t),update(mid+1,e,as,ae,2*i+2,t);
        com(s,e,i);
        return 0;
    }
};
data a,b;
int main() {
    int i,j,k;
    int n,m,q,s,e;
    char c;
    scanf("%d %d %d",&n,&m,&q);
    for (i = 0; i < n; i++) scanf(" %c",&c),l[i] = (c == 'B');
    for (i = 0; i < n; i++) scanf(" %c",&c),r[i] = (c == 'B');
    for (i = 0; i < m; i++) scanf(" %c",&c),u[i] = (c == 'B');
    for (i = 0; i < m; i++) scanf(" %c",&c),d[i] = (c == 'B');
    a.n = n,a.u = u,a.d = d,a.build(0,m-1,0);
    b.n = m,b.u = l,b.d = r,b.build(0,n-1,0);
    int ans = 1e9;
    for (j = 0; j < 2; j++) {
        for (k = 0; k < 2; k++) {
            ans = min(ans,a.tree[0][0][0][j][k]+(j ? n-b.sum[0][0]:b.sum[0][0])+(k ? n-b.sum[0][1]:b.sum[0][1]));
            ans = min(ans,b.tree[0][0][0][j][k]+(j ? m-a.sum[0][0]:a.sum[0][0])+(k ? m-a.sum[0][1]:a.sum[0][1]));
        }
    }
    printf("%d\n",ans);
    for (i = 0; i < q; i++) {
        scanf(" %c %d %d",&c,&s,&e),s--,e--;
        if (c == 'L') b.update(0,n-1,s,e,0,0);
        else if (c == 'R') b.update(0,n-1,s,e,0,1);
        else if (c == 'U') a.update(0,m-1,s,e,0,0);
        else a.update(0,m-1,s,e,0,1);
        int ans = 1e9;
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                ans = min(ans,a.tree[0][0][0][j][k]+(j ? n-b.sum[0][0]:b.sum[0][0])+(k ? n-b.sum[0][1]:b.sum[0][1]));
                ans = min(ans,b.tree[0][0][0][j][k]+(j ? m-a.sum[0][0]:a.sum[0][0])+(k ? m-a.sum[0][1]:a.sum[0][1]));
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}