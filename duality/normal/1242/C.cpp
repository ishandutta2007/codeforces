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

int n[15];
LLI diff[15];
map<LLI,pii> M;
vi a[15];
pii poss[1 << 15];
int dp[1 << 15],pre[1 << 15];
pii ans[15];
int findSol(int m,int k) {
    if (pre[m] != -1) {
        findSol(pre[m],k),findSol(m^pre[m],k);
        return 0;
    }
    //cout<<"findSol"<<m<<endl;

    int u = poss[m].first;
    LLI need = diff[u]+a[u][poss[m].second];
    //cout<<u<<","<<need<<endl;
    while (1) {
        ans[M[need].first] = mp(need,u);
        u = M[need].first;
        need = diff[M[need].first]+need;
        if (u == poss[m].first) break;
    }
    return 0;
}
int main() {
    int i,j;
    int k;
    LLI sum = 0;
    scanf("%d",&k);
    for (i = 0; i < k; i++) {
        scanf("%d",&n[i]);
        a[i].resize(n[i]);
        for (j = 0; j < n[i]; j++) scanf("%d",&a[i][j]),diff[i] += a[i][j],M[a[i][j]] = mp(i,j);
        sum += diff[i];
    }
    if ((abs(sum) % k) != 0) {
        printf("No\n");
        return 0;
    }
    for (i = 0; i < k; i++) diff[i] = sum/k-diff[i];
    //printArr(diff,k);

    for (i = 0; i < (1 << k); i++) poss[i] = mp(-1,-1);
    for (i = 0; i < k; i++) {
        for (j = 0; j < n[i]; j++) {
            int m = 0,no = 0;
            LLI need = diff[i]+a[i][j];
            //cout<<need<<endl;
            while (1) {
                //cout<<"n:"<<need<<endl;
                if (!M.count(need)) {
                    no = 1;
                    break;
                }
                if (m & (1 << M[need].first)) {
                    no = 1;
                    break;
                }
                m |= (1 << M[need].first);
                if (M[need].first == i) {
                    if (need != a[i][j]) {
                        no = 1;
                        break;
                    }
                    else break;
                }
                else need = diff[M[need].first]+need;
            }
            if (!no) poss[m] = mp(i,j),dp[m] = 1,pre[m] = -1;
        }
    }
    for (i = 1; i < (1 << k); i++) {
        if (dp[i]) continue;
        for (j = (i-1) & i; j > 0; j = (j-1) & i) {
            if (dp[j] && dp[i^j]) {
                dp[i] = 1,pre[i] = j;
                break;
            }
        }
    }
    if (dp[(1 << k)-1]) {
        printf("Yes\n");
        findSol((1 << k)-1,k);
        for (i = 0; i < k; i++) printf("%d %d\n",ans[i].first,ans[i].second+1);
    }
    else printf("No\n");

    return 0;
}