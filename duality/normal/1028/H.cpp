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

int aaa[200000];
vi v[200000];
bitset<5100000> bs;
vi primes;
struct query { int l,r,i; };
bool comp(query a,query b) {
    return a.r < b.r;
}
vector<query> queries;
vector<vi> sub;
int ans[1100000];
int M[8][10000000];
int bit[200000],arr[200000];
int last[5100000];
vi pos[5100000];
int main() {
    int i,j,k;
    bs.set();
    for (i = 2; i < 5100000; i++) {
        if (bs[i]) {
            for (j = i; j < 5100000; j += i) bs[j] = 0;
            primes.pb(i);
        }
    }
    int n,q,a,l,r;
    scanf("%d %d",&n,&q);
    bs.reset();
    for (i = 0; i < n; i++) {
        scanf("%d",&a);
        for (j = 0; primes[j]*primes[j] <= a; j++) {
            if ((a % primes[j]) == 0) {
                int c = 0;
                while ((a % primes[j]) == 0) a /= primes[j],c++;
                if (c & 1) v[i].pb(primes[j]);
            }
        }
        if (a > 1) v[i].pb(a);
        aaa[i] = 1;
        for (j = 0; j < v[i].size(); j++) aaa[i] *= v[i][j];
        if (!bs[aaa[i]]) {
            bs[aaa[i]] = 1;
            for (j = 0; j < (1 << v[i].size()); j++) {
                vi vv;
                for (k = 0; k < v[i].size(); k++) {
                    if (j & (1 << k)) vv.pb(v[i][k]);
                }
                sub.pb(vv);
            }
        }
    }
    for (i = 0; i < q; i++) scanf("%d %d",&l,&r),queries.pb((query){l-1,r-1,i});
    sort(queries.begin(),queries.end(),comp);
    sort(sub.begin(),sub.end());
    sub.resize(unique(sub.begin(),sub.end())-sub.begin());

    int qq = 0,ll = -1;
    fill(bit,bit+n+1,50),fill(arr,arr+n+1,50);
    memset(last,-1,sizeof(last));
    memset(M,-1,sizeof(M));
    for (i = 0; i < n; i++) {
        if (last[aaa[i]] != -1) {
            if (last[aaa[i]] > ll) {
                ll = last[aaa[i]];
                for (j = n-ll; j <= n; j += j & (-j)) bit[j] = 0;
            }
        }
        last[aaa[i]] = i;
        vpii events;
        for (j = 0; j < (1 << v[i].size()); j++) {
            int s = __builtin_popcount(j);
            if (j >= pos[aaa[i]].size()) {
                vi vv;
                for (k = 0; k < v[i].size(); k++) {
                    if (j & (1 << k)) vv.pb(v[i][k]);
                }
                pos[aaa[i]].pb(lower_bound(sub.begin(),sub.end(),vv)-sub.begin());
            }
            for (k = 0; k <= 7; k++) {
                if (M[k][pos[aaa[i]][j]] != -1) {
                    if (M[k][pos[aaa[i]][j]] <= ll) M[k][pos[aaa[i]][j]] = -1;
                    else events.pb(mp(v[i].size()+k-2*s,M[k][pos[aaa[i]][j]]));
                }
            }
        }
        for (j = 0; j < (1 << v[i].size()); j++) M[v[i].size()][pos[aaa[i]][j]] = i;
        for (j = 0; j < events.size(); j++) {
            if (events[j].first < arr[events[j].second]) {
                arr[events[j].second] = events[j].first;
                for (k = n-events[j].second; k <= n; k += k & (-k)) bit[k] = min(bit[k],events[j].first);
            }
        }
        while ((qq < q) && (queries[qq].r == i)) {
            int aa = 50;
            for (j = n-queries[qq].l; j > 0; j -= j & (-j)) aa = min(aa,bit[j]);
            ans[queries[qq].i] = aa;
            qq++;
        }
    }
    for (i = 0; i < q; i++) printf("%d\n",ans[i]);

    return 0;
}