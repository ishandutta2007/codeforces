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

pair<plli,int> queries[10000];
bitset<32000000> bs;
vi primes;
LLI dist[100000];
priority_queue<pair<LLI,int> > H;
int ans[10000];
int main() {
    int i;
    int t;
    LLI n,k;
    scanf("%d",&t);
    for (i = 0; i < t; i++) scanf("%I64d %I64d",&n,&k),queries[i] = mp(mp(k,n),i);
    sort(queries,queries+t);

    int j;
    bs.set();
    bs[0] = bs[1] = 0;
    for (i = 2; i < 32000000; i++) {
        if (bs[i]) {
            if (i < 6000) {
                for (j = i*i; j < 32000000; j += i) bs[j] = 0;
            }
            primes.pb(i);
        }
    }
    vlli f;
    for (i = 0; i < t; i++) {
        k = queries[i].first.first,n = queries[i].first.second;
        if ((i == 0) || (k != queries[i-1].first.first)) {
            int e = sqrt(k)+EPS;
            f.clear();
            for (j = 0; primes[j] <= e; j++) {
                if ((k % primes[j]) == 0) {
                    f.pb(primes[j]);
                    while ((k % primes[j]) == 0) k /= primes[j];
                }
            }
            if (k > 1) f.pb(k);
            if (f.size() > 2) {
                fill(dist,dist+f[0],-1);
                dist[0] = 0;
                H.push(mp(0,0));
                while (!H.empty()) {
                    int u = H.top().second;
                    int d = -H.top().first;
                    H.pop();

                    if (d > dist[u]) continue;
                    for (j = 1; j < f.size(); j++) {
                        int v = (u+f[j]) % f[0];
                        if ((dist[v] == -1) || (dist[u]+f[j] < dist[v])) {
                            dist[v] = dist[u]+f[j];
                            H.push(mp(-dist[v],v));
                        }
                    }
                }
            }
        }
        if (f.size() == 0) ans[queries[i].second] = 0;
        else if (f.size() == 1) ans[queries[i].second] = ((n % f[0]) == 0);
        else if (f.size() == 2) {
            int e = f[1]-2;
            LLI b = f[0],r = n % f[1];
            while (e > 0) {
                if (e & 1) r *= b,r %= f[1];
                e >>= 1;
                b *= b,b %= f[1];
            }
            ans[queries[i].second] = (n >= r*f[0]);
        }
        else ans[queries[i].second] = (dist[n % f[0]] != -1) && (dist[n % f[0]] <= n);
    }
    for (i = 0; i < t; i++) printf(ans[i] ? "YES\n":"NO\n");

    return 0;
}