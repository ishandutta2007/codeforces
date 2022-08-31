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

int gcd(int a,int b) {
    int t;
    while (a > 0) t = b % a,b = a,a = t;
    return b;
}
int factor[10000001];
vi primes;
int occ[10000001],occ2[10000001];
int a[100000];
vi fact[100000];
vi ans,ans2,ans3;
int taken[100000];
int getNum(int i,int *occ) {
    int j,k,c = 0;
    for (j = 0; j < (1 << fact[i].size()); j++) {
        int p = 1,b = 0;
        for (k = 0; k < fact[i].size(); k++) {
            if (j & (1 << k)) p *= fact[i][k],b++;
        }
        if (b & 1) c -= occ[p];
        else c += occ[p];
    }
    return c;
}
vi order;
int main() {
    int i;
    int n,kk;
    scanf("%d %d",&n,&kk);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);

    int j,k;
    memset(factor,-1,sizeof(factor));
    for (i = 2; i < 10000000; i++) {
        if (factor[i] == -1) {
            for (j = i; j < 10000000; j += i) factor[j] = i;
            primes.pb(i);
        }
    }
    for (i = 0; i < n; i++) {
        int t = a[i];
        while (t > 1) {
            int f = factor[t];
            while ((t % f) == 0) t /= f;
            fact[i].pb(f);
        }
        for (j = 0; j < (1 << fact[i].size()); j++) {
            int p = 1;
            for (k = 0; k < fact[i].size(); k++) {
                if (j & (1 << k)) p *= fact[i][k];
            }
            occ[p]++;
        }
    }
    for (i = 0; i < n; i++) {
        if (getNum(i,occ2) == 0) {
            ans2.pb(i);
            for (j = 0; j < (1 << fact[i].size()); j++) {
                int p = 1;
                for (k = 0; k < fact[i].size(); k++) {
                    if (j & (1 << k)) p *= fact[i][k];
                }
                occ2[p]++;
            }
        }
        if (ans2.size() == kk) {
            for (j = 0; j < kk; j++) printf("%d ",ans2[j]+1);
            printf("\n");
            return 0;
        }
        if (ans.empty() && (getNum(i,occ) >= 2)) {
            ans.pb(i),taken[i] = 1;
            for (j = 0; j < n; j++) {
                if ((i != j) && (ans.size() < 3) && (gcd(a[i],a[j]) == 1)) ans.pb(j),taken[j] = 1;
            }
        }
    }
    int l;
    ans2.clear(),memset(occ2,0,sizeof(occ2));
    for (i = 0; i < n; i++) {
        if (taken[i]) {
            for (j = 0; j < (1 << fact[i].size()); j++) {
                int p = 1;
                for (k = 0; k < fact[i].size(); k++) {
                    if (j & (1 << k)) p *= fact[i][k];
                }
                occ[p]--;
            }
        }
        else order.pb(i);
    }
    random_shuffle(order.begin(),order.end());
    for (i = 0; i < order.size(); i++) {
        int u = order[i];
        if (getNum(u,occ2) == 0) {
            if (getNum(u,occ) == 0) ans3.pb(u);
            else ans2.pb(u);
            for (j = 0; j < (1 << fact[u].size()); j++) {
                int p = 1;
                for (k = 0; k < fact[u].size(); k++) {
                    if (j & (1 << k)) p *= fact[u][k];
                }
                occ2[p]++;
            }
        }
        else {
            ans.pb(u);
            int f = 0;
            vi temp;
            for (j = 0; j < ans2.size(); j++) {
                if (((ans.size() <= kk) || !f) && (gcd(a[ans2[j]],a[u]) == 1)) {
                    ans.pb(ans2[j]),f = 1;
                    int v = ans2[j];
                    for (k = 0; k < (1 << fact[v].size()); k++) {
                        int p = 1;
                        for (l = 0; l < fact[v].size(); l++) {
                            if (k & (1 << l)) p *= fact[v][l];
                        }
                        occ2[p]--;
                    }
                }
                else temp.pb(ans2[j]);
            }
            ans2 = temp;
        }
        if (ans.size() >= kk) {
            for (j = 0; j < ans.size(); j++) {
                if ((j == 2) && (ans.size() > kk)) continue;
                printf("%d ",ans[j]+1);
            }
            printf("\n");
            return 0;
        }
        if (ans2.size()+ans3.size() == kk) {
            for (j = 0; j < ans2.size(); j++) printf("%d ",ans2[j]+1);
            for (j = 0; j < ans3.size(); j++) printf("%d ",ans3[j]+1);
            printf("\n");
            return 0;
        }
        for (j = 0; j < (1 << fact[u].size()); j++) {
            int p = 1;
            for (k = 0; k < fact[u].size(); k++) {
                if (j & (1 << k)) p *= fact[u][k];
            }
            occ[p]--;
        }
    }

    return 0;
}