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

int a[200000],b[200000],x[200000],n,k;
struct data {
    vi arr,lazy;
    vector<unordered_map<int,int> > M;
    vector<array<int,1 << 14> > M2;
    int N,B,zeros = 0;
    int init(int n) {
        int i;
        N = n,arr.resize(n),B = 450;
        lazy.resize((n+B-1)/B,0);
        if (n > 450) {
            M2.resize((n+B-1)/B);
            for (i = 0; i < n; i++) M2[i/B][0]++;
        }
        zeros = n;
        return 0;
    }
    int update(int i,int x) {
        int b = i/B,c = (b+1)*B;
        for (; i < arr.size(); i++) {
            if (i == c) break;
            zeros -= (arr[i] == lazy[b]);
            if (N > 450) M2[b][arr[i]]--;
            arr[i] ^= x;
            zeros += (arr[i] == lazy[b]);
            if (N > 450) M2[b][arr[i]]++;
        }
        if (i == arr.size()) return 0;
        i /= B;
        int e = (arr.size()-1)/B;
        for (; i <= e; i++) {
            if (N > 450) zeros -= M2[i][lazy[i]];
            lazy[i] ^= x;
            if (N > 450) zeros += M2[i][lazy[i]];
        }
        return 0;
    }
    int getVal(int i) {
        return arr[i]^lazy[i/B];
    }
    int getBack() {
        return getVal(arr.size()-1);
    }
};
data d[200000];
int ans = 0,no = 0;
int update(int p,int xx) {
    if (k == 1) {
        ans -= (d[0].arr[p] == 0);
        if (p == n-1) no -= (d[0].arr[p] == 0);
        d[0].arr[p] ^= xx,ans += (d[0].arr[p] == 0);
        if (p == n-1) no += (d[0].arr[p] == 0);
    }
    else if (k == 2) {
        ans -= d[0].zeros,no -= (d[0].getBack() != 0);
        d[0].update(p,xx);
        ans += d[0].zeros,no += (d[0].getBack() != 0);
    }
    else {
        ans -= d[p % k].zeros;
        if ((p % k) != (n % k)) no -= (d[p % k].getBack() != 0);
        d[p % k].update(p/k,xx);
        ans += d[p % k].zeros;
        if ((p % k) != (n % k)) no += (d[p % k].getBack() != 0);
        if (p+1 < n) {
            p++;
            ans -= d[p % k].zeros;
            if ((p % k) != (n % k)) no -= (d[p % k].getBack() != 0);
            d[p % k].update(p/k,xx);
            ans += d[p % k].zeros;
            if ((p % k) != (n % k)) no += (d[p % k].getBack() != 0);
        }
    }
    return 0;
}
int main() {
    int i;
    int q,p,v;
    char s;
    scanf("%d %d %d",&n,&k,&q);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    for (i = 0; i < n; i++) scanf("%d",&b[i]),x[i] = a[i]^b[i];
    if (k == 2) d[0].init(n);
    else {
        for (i = 0; i < k; i++) d[i].init((n-i+k-1)/k);
    }
    ans = n;
    if (k <= 2) {
        for (i = 0; i < n; i++) update(i,x[i]);
    }
    else {
        for (i = 0; i < n; i++) {
            int p = i,xx = x[i]^((i == 0) ? 0:x[i-1]);
            ans -= d[p % k].zeros;
            if ((p % k) != (n % k)) no -= (d[p % k].getBack() != 0);
            d[p % k].update(p/k,xx);
            ans += d[p % k].zeros;
            if ((p % k) != (n % k)) no += (d[p % k].getBack() != 0);
        }
    }
    if (no > 0) printf("-1\n");
    else printf("%d\n",n-ans);
    for (i = 0; i < q; i++) {
        scanf(" %c %d %d",&s,&p,&v),p--;
        int xx;
        if (s == 'a') xx = a[p]^v,a[p] = v,x[p] ^= xx;
        else xx = b[p]^v,b[p] = v,x[p] ^= xx;
        update(p,xx);
        if (no > 0) printf("-1\n");
        else printf("%d\n",n-ans);
    }

    return 0;
}