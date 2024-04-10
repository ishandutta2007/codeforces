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

int s[22],len[22],t[22],vv[44],vv2[44],order[22];
int s2[22],len2[22],t2[22];
bool comp(int a,int b) {
    return s[a] < s[b];
}
int dp[1 << 22],parent[1 << 22],tt[1 << 22];
int inter(int a,int b,int c,int d) {
    return (c <= b) && (a <= d);
}
int ans[22];
int main() {
    int i;
    int N,P;
    scanf("%d %d",&N,&P);
    for (i = 0; i < N; i++) scanf("%d %d %d",&s[i],&len[i],&t[i]),order[i] = i;
    sort(order,order+N,comp);
    for (i = 0; i < N; i++) s2[i] = s[order[i]],len2[i] = len[order[i]],t2[i] = t[order[i]];
    for (i = 0; i < N; i++) s[i] = s2[i],len[i] = len2[i],t[i] = t2[i],vv[2*i] = s[i],vv[2*i+1] = s[i]+len[i];

    int j,k;
    dp[0] = 1,parent[0] = -1;
    for (i = 1; i < (1 << N); i++) {
        dp[i] = 2e9,parent[i] = -1;
        int c = 0;
        for (j = 0; j < N; j++) {
            if (i & (1 << j)) vv2[2*c] = s[j],vv2[2*c+1] = s[j]+len[j],c++;
        }
        for (j = 0; j < N; j++) {
            if (i & (1 << j)) {
                int x = dp[i^(1 << j)];
                if (x+t[j] >= s[j]) continue;
                if (x+t[j] >= dp[i]) continue;
                int p = upper_bound(vv,vv+2*N,x)-vv;
                if (!(p & 1)) {
                    int q = upper_bound(vv2,vv2+2*c,x)-vv2;
                    if (!(q & 1)) {
                        int r = upper_bound(vv2,vv2+2*c,x+t[j])-vv2;
                        if (q == r) dp[i] = x+t[j],parent[i] = j,tt[i] = x;
                    }
                }
                if (x+t[j] < dp[i]) {
                    for (k = 0; k < N; k++) {
                        int y = s[k]+len[k];
                        if ((y >= x) && (y+t[j] < s[j]) && (y+t[j] < dp[i])) {
                            int p = upper_bound(vv,vv+2*N,y)-vv;
                            if (!(p & 1)) {
                                int q = upper_bound(vv2,vv2+2*c,y)-vv2;
                                if (!(q & 1)) {
                                    int r = upper_bound(vv2,vv2+2*c,y+t[j])-vv2;
                                    if (q == r) {
                                        dp[i] = y+t[j],parent[i] = j,tt[i] = y;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (P == 1) {
        if (dp[(1 << N)-1] < 2e9) {
            int u = (1 << N)-1;
            while (parent[u] != -1) ans[parent[u]] = tt[u],u ^= (1 << parent[u]);
            printf("YES\n");
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    if (order[j] == i) printf("1 %d\n",ans[j]);
                }
            }
        }
        else printf("NO\n");
    }
    else {
        for (i = 0; i < (1 << N); i++) {
            if ((dp[i] < 2e9) && (dp[((1 << N)-1)^i] < 2e9)) break;
        }
        if (i == (1 << N)) printf("NO\n");
        else {
            int u = i,v = ((1 << N)-1)^i;
            while (parent[u] != -1) ans[parent[u]] = tt[u],u ^= (1 << parent[u]);
            while (parent[v] != -1) ans[parent[v]] = tt[v],v ^= (1 << parent[v]);
            u = i;
            printf("YES\n");
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    if (order[j] == i) printf("%d %d\n",(u & (1 << j)) ? 1:2,ans[j]);
                }
            }
        }
    }

    return 0;
}