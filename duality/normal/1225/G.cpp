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

int a[16];
bitset<2001> dp[1 << 16];
int ans[16];
int findAns(int m,int num,int n,int k) {
    if (m == 0) return 0;
    else if (((num*k) <= 2000) && dp[m][num*k]) {
        int i;
        for (i = 0; i < n; i++) {
            if (m & (1 << i)) ans[i]++;
        }
        findAns(m,num*k,n,k);
        return 0;
    }

    int i;
    for (i = 0; i < n; i++) {
        if ((m & (1 << i)) && (num >= a[i]) && dp[m^(1 << i)][num-a[i]]) {
            findAns(m^(1 << i),num-a[i],n,k);
            return 0;
        }
    }
    return 0;
}
priority_queue<pii> H;
int main() {
    int i;
    int n,k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);

    int j;
    dp[0][0] = 1;
    for (i = 1; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) dp[i] |= dp[i^(1 << j)] << a[j];
        }
        for (j = 2000/k; j >= 0; j--) {
            if (dp[i][j*k]) dp[i][j] = 1;
        }
    }
    if (dp[(1 << n)-1][1]) {
        printf("YES\n");
        findAns((1 << n)-1,1,n,k);
        for (i = 0; i < n; i++) H.push(mp(ans[i],a[i]));
        for (i = 0; i < n-1; i++) {
            pii a = H.top();
            H.pop();
            pii b = H.top();
            H.pop();
            printf("%d %d\n",a.second,b.second);
            int s = a.second+b.second;
            while ((s % k) == 0) s /= k,a.first--;
            H.push(mp(a.first,s));
        }
    }
    else printf("NO\n");

    return 0;
}