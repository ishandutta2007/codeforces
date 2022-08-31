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

int v[100000];
bitset<500> poss;
int nim[100000];
priority_queue<int> pos[500];
vpii events[100000];
int main() {
    int i,j;
    int n,m,x = 0;
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&m);
        for (i = 0; i < m; i++) scanf("%d",&v[i]);

        poss[0] = 1,nim[m-1] = 0,pos[0].push(m-1);
        for (i = m-2; i >= 0; i--) {
            for (j = 0; j < events[i].size(); j++) {
                if (events[i][j].second < nim[events[i][j].first]) {
                    nim[events[i][j].first] = events[i][j].second;
                    pos[nim[events[i][j].first]].push(events[i][j].first);
                }
            }
            int xx = 0;
            while (1) {
                while (!pos[xx].empty() && (nim[pos[xx].top()] != xx)) pos[xx].pop();
                if (pos[xx].empty()) break;
                else xx++;
            }
            poss[xx] = 1,nim[i] = xx,pos[xx].push(i);
            for (j = 0; j < xx; j++) {
                int k = pos[j].top();
                int p = upper_bound(v,v+i,2*v[i]-v[k])-v-1;
                if (p >= 0) events[p].pb(mp(i,j));
            }
        }
        int xx = 0;
        while (poss[xx]) xx++;
        x ^= xx,poss.reset();
        for (i = 0; i < 500; i++) {
            while (!pos[i].empty()) pos[i].pop();
        }
        for (i = 0; i < m; i++) events[i].clear();
    }
    printf((x > 0) ? "YES\n":"NO\n");

    return 0;
}