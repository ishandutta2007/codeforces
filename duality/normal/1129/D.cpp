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
#define MOD 998244353
#define bs 300

int n,k;
int a[100000],p[100000];
int last[100000];
int dp[100001];
int num[100001];
int sum[350][100100],shift[350];
int sumall = 0;
int prop(int b) {
    if (shift[b] == 0) return 0;
    int i;
    for (i = b*bs; i < min((b+1)*bs,n); i++) {
        sum[b][num[i]] += MOD-dp[i];
        if (sum[b][num[i]] >= MOD) sum[b][num[i]] -= MOD;
        num[i] += shift[b];
        sum[b][num[i]] += dp[i];
        if (sum[b][num[i]] >= MOD) sum[b][num[i]] -= MOD;
    }
    shift[b] = 0;
    return 0;
}
int add(int i,int d) {
    int b = i/bs;
    sum[b][num[i]] += MOD-dp[i];
    if (sum[b][num[i]] >= MOD) sum[b][num[i]] -= MOD;
    if (num[i] <= k) sumall += MOD-dp[i];
    if (sumall >= MOD) sumall -= MOD;
    num[i] += d;
    sum[b][num[i]] += dp[i];
    if (sum[b][num[i]] >= MOD) sum[b][num[i]] -= MOD;
    if (num[i] <= k) sumall += dp[i];
    if (sumall >= MOD) sumall -= MOD;
    return 0;
}
int update(int s,int e,int d) {
    int i;
    if (s/bs == e/bs) {
        int b = s/bs;
        prop(b);
        for (i = s; i <= e; i++) add(i,d);
    }
    else {
        int b = s/bs;
        prop(b);
        for (i = s; i < (b+1)*bs; i++) add(i,d);
        for (i = b+1; i < e/bs; i++) {
            if ((d == 1) && (k >= shift[i])) sumall += MOD-sum[i][k-shift[i]];
            else if ((d == -1) && (k+1 >= shift[i])) sumall += sum[i][k+1-shift[i]];
            if (sumall >= MOD) sumall -= MOD;
            shift[i] += d;
        }
        b = e/bs;
        prop(b);
        for (i = b*bs; i <= e; i++) add(i,d);
    }
    return 0;
}
int main() {
    int i;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),a[i]--;

    for (i = 0; i < n; i++) last[i] = -1;
    for (i = 0; i < n; i++) {
        p[i] = last[a[i]];
        last[a[i]] = i;
    }
    dp[0] = 1;
    sum[0][shift[0]] = 1,sumall = 1;
    for (i = 0; i < n; i++) {
        update(p[i]+1,i,1);
        if (p[i] != -1) update(p[p[i]]+1,p[i],-1);
        int b = (i+1)/bs;
        prop(b);
        dp[i+1] = sumall;
        sum[b][num[i+1]] += dp[i+1];
        sumall += dp[i+1];
        if (sum[b][num[i+1]] >= MOD) sum[b][num[i+1]] -= MOD;
        if (sumall >= MOD) sumall -= MOD;
    }
    printf("%d\n",dp[n]);

    return 0;
}