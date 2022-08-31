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
#define MOD 1000000007

int x[2000],y[2000],c[2000];
vi poss;
multiset<int> xx[2000];
vpii events;
map<pii,int> M;
LLI sum = 0,ans = 0;
int update(int e,int m) {
    if (e < 0) return 0;
    auto it = M.upper_bound(mp(e,2e9));
    it--;
    if (it->first.second != e) {
        pii p = it->first;
        int v = it->second;
        M.erase(it);
        M[mp(p.first,e)] = v;
        M[mp(e+1,p.second)] = v;
    }
    it = M.upper_bound(mp(e,2e9));
    it--;
    if (it->second < m) return 0;
    pii p = mp(e,e);
    while (it->second >= m) {
        p.first = it->first.first;
        sum -= (LLI) (it->first.second-it->first.first+1)*it->second;
        it = M.erase(it);
        if (it == M.begin()) break;
        else it--;
    }
    M[p] = m;
    sum += (LLI) (p.second-p.first+1)*m;
    /*cout<<"update "<<e<<":"<<m<<endl;
    for (auto it = M.begin(); it != M.end(); it++) {
        cout << it->first.first<<","<<it->first.second<<": "<<it->second<<" ";
    }
    cout<<endl;*/
    return 0;
}
int main() {
    int i;
    int n,k,L;
    scanf("%d %d %d",&n,&k,&L);
    poss.pb(-1),poss.pb(L);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d",&x[i],&y[i],&c[i]),c[i]--;
        poss.pb(y[i]);
    }
    sort(poss.begin(),poss.end());
    poss.resize(unique(poss.begin(),poss.end())-poss.begin());

    int j;
    for (i = 1; i < poss.size(); i++) {
        int yy = poss[i]-poss[i-1];
        for (j = 0; j < n; j++) {
            if (y[j] > poss[i-1]) {
                events.pb(mp(y[j],j));
                xx[c[j]].insert(x[j]);
            }
        }
        M.clear();
        M[mp(0,L-1)] = L,sum = (LLI) L*L;
        for (j = 0; j < k; j++) {
            if (xx[j].empty()) break;
            int p = -1;
            for (auto it = xx[j].begin(); it != xx[j].end(); it++) update(*it-1,p+1),p = *it;
            update(L-1,p+1);
        }
        if (j < k) break;
        sort(events.begin(),events.end(),greater<pii>());
        int l = L;
        for (j = 0; j < events.size(); j++) {
            int u = events[j].second;
            LLI nn = (LLI) yy*(l-events[j].first);
            nn %= MOD;
            ans += nn*(sum % MOD),ans %= MOD;
            auto it = xx[c[u]].lower_bound(x[u]);
            it = xx[c[u]].erase(it);
            int a = (it == xx[c[u]].end()) ? L-1:*it-1;
            int b = (it == xx[c[u]].begin()) ? 0:*(--it)+1;
            update(a,b);
            if (xx[c[u]].empty()) break;
            l = events[j].first;
        }
        for (j = 0; j < k; j++) xx[j].clear();
        events.clear();
    }
    printf("%I64d\n",ans);

    return 0;
}