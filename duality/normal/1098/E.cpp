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
// from atcoder library
long long floor_sum(long long n, long long m, long long a, long long b) {
    long long ans = 0;
    if (a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }

    long long y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}
LLI getNum(int a,int b,LLI c) {
    if (c < 0) return 0;
    else return floor_sum(c/a+1,b,a,c % a)+c/a+1;
}
int a[50000],num[100001],p[100001];
vpii v,v2;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);

    int j;
    for (i = 0; i < n; i++) {
        v.pb(mp(a[i],1));
        for (j = 0; j < v.size(); j++) v[j].first = gcd(v[j].first,a[i]),num[v[j].first] += v[j].second;
        sort(v.begin(),v.end());
        for (j = 0; j < v.size(); j++) {
            if (!v2.empty() && (v2.back().first == v[j].first)) v2.back().second += v[j].second;
            else v2.pb(v[j]);
        }
        v = v2,v2.clear();
    }
    for (i = 1; i <= 100000; i++) {
        if (num[i] > 0) p[i] = i;
        else p[i] = p[i-1];
    }
    LLI n2 = (LLI) n*(n+1)/2;
    LLI n3 = n2*(n2+1)/2;
    LLI l = 1,r = 1e15;
    while (l < r) {
        LLI m = (l+r) / 2;

        LLI ans = 0,s = 0,s2 = 0;
        j = 1;
        for (i = 1; i <= 100000; i++) {
            if (num[i] > 0) {
                while ((s >= 0) && (s+(LLI) num[i]*i > m)) {
                    s -= (LLI) num[j]*j,s2 -= num[j];
                    if ((num[j] > 0) && (s >= 0)) ans += getNum(j,i,m-s-j-i)-getNum(j,i,m-s-j-i-(LLI) num[j]*j)-getNum(j,i,m-s-j-i-(LLI) num[i]*i);
                    j++;
                }
                if (s2 >= 0) ans += num[i]*s2;
                s += (LLI) num[i]*i,s2 += num[i];
                LLI a = min((LLI) num[i],m/i);
                ans += a*(2LL*num[i]-a+1)/2;
                if (p[j-1] > 0) j = p[j-1],s += (LLI) num[j]*j,s2 += num[j];
            }
        }
        if (ans < (n3+1)/2) l = m+1;
        else r = m;
    }
    printf("%I64d\n",l);

    return 0;
}