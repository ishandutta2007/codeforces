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

vi primes;
vector<vi> poss;
vi divs,pdivs;
int findPoss(vi v,int c,int d) {
    poss.pb(v),divs.pb(d);
    v.pb(0);
    while (((LLI) c*primes[v.size()-1] < 1e8) && ((v.size() == 1) || (v.back() < v[v.size()-2]))) {
        c *= primes[v.size()-1];
        v.back()++;
        findPoss(v,c,d*(v.back()+1));
    }
    return 0;
}
int dist[1000][1000];
int da[1000],db[1000];
int ans[1000][1000];
int main() {
    int i,j,k;
    for (i = 2; i < 1000; i++) {
        int f = 0;
        for (j = 2; j*j <= i; j++) {
            if ((i % j) == 0) {
                f = 1;
                break;
            }
        }
        if (!f) primes.pb(i);
    }
    vi v;
    findPoss(v,1,1);
    for (i = 0; i < poss.size(); i++) {
        for (j = 0; j < poss.size(); j++) {
            for (k = 0; k < max(poss[i].size(),poss[j].size()); k++) {
                int a = (k < poss[i].size()) ? poss[i][k]:0;
                int b = (k < poss[j].size()) ? poss[j][k]:0;
                dist[i][j] += abs(a-b);
            }
            ans[i][j] = -1;
        }
    }
    pdivs = divs;
    sort(pdivs.begin(),pdivs.end());
    pdivs.resize(unique(pdivs.begin(),pdivs.end())-pdivs.begin());

    int t,a,b;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&a,&b);

        vi x,y;
        for (i = 0; i < primes.size(); i++) {
            if ((a % primes[i]) == 0) {
                int c = 0;
                while ((a % primes[i]) == 0) a /= primes[i],c++;
                x.pb(c);
            }
            if ((b % primes[i]) == 0) {
                int c = 0;
                while ((b % primes[i]) == 0) b /= primes[i],c++;
                y.pb(c);
            }
        }
        if (a > 1) x.pb(1);
        if (b > 1) y.pb(1);
        sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end(),greater<int>());
        int pa = find(poss.begin(),poss.end(),x)-poss.begin();
        int pb = find(poss.begin(),poss.end(),y)-poss.begin();
        if (ans[pa][pb] != -1) printf("%d\n",ans[pa][pb]);
        else {
            for (i = 0; i < pdivs.size(); i++) da[pdivs[i]] = db[pdivs[i]] = 1e9;
            for (i = 0; i < poss.size(); i++) {
                da[divs[i]] = min(da[divs[i]],dist[pa][i]);
                db[divs[i]] = min(db[divs[i]],dist[pb][i]);
            }
            int aa = 1e9;
            for (i = 0; i < pdivs.size(); i++) aa = min(aa,da[pdivs[i]]+db[pdivs[i]]);
            ans[pa][pb] = ans[pb][pa] = aa;
            printf("%d\n",aa);
        }
    }

    return 0;
}