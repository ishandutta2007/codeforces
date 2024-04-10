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

struct point { int x,y,t; };
bool comp(point a,point b) {
    if (a.x == b.x) {
        if (a.y == b.y) return a.t < b.t;
        else return a.y < b.y;
    }
    else return a.x < b.x;
}
vector<point> vv;
vi xx;
int ans[100000];
set<pii> win;
int main() {
    int i;
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d %d",&x,&y),vv.pb((point){x,y,-1}),xx.pb(x);
    vv.pb((point){0,0,-1}),xx.pb(0);
    for (i = 0; i < m; i++) scanf("%d %d",&x,&y),vv.pb((point){x,y,i}),xx.pb(x);
    sort(vv.begin(),vv.end(),comp);
    sort(xx.begin(),xx.end());
    xx.resize(unique(xx.begin(),xx.end())-xx.begin());

    int j = 0,k,c = -1;
    win.insert(mp(0,1.1e9));
    for (i = 0; i < xx.size(); i++) {
        int d = xx[i]-c-1;
        while (d > 0) {
            pii p = *win.begin();
            win.erase(win.begin());
            if (d < p.second-p.first+1) {
                p.first += d,d = 0;
                win.insert(p);
            }
            else d -= p.second-p.first+1;
        }
        vi lose;
        vpii qq;
        while ((j < vv.size()) && (vv[j].x == xx[i])) {
            if (vv[j].t == -1) lose.pb(vv[j].y);
            else qq.pb(mp(vv[j].y,vv[j].t));
            j++;
        }
        if (lose.empty() || (lose[0] > win.begin()->first)) lose.insert(lose.begin(),win.begin()->first);
        for (k = 0; k < qq.size(); k++) {
            if (binary_search(lose.begin(),lose.end(),qq[k].first)) ans[qq[k].second] = 0;
            else ans[qq[k].second] = 1;
        }
        for (k = 0; k < lose.size(); k++) {
            auto it = win.upper_bound(mp(lose[k],2e9));
            if (it != win.begin()) {
                it--;
                if ((it->first <= lose[k]) && (lose[k] <= it->second)) {
                    if (it->first <= lose[k]-1) win.insert(mp(it->first,lose[k]-1));
                    if (lose[k]+1 <= it->second) win.insert(mp(lose[k]+1,it->second));
                    win.erase(it);
                }
            }
        }
        c = xx[i];
    }
    for (i = 0; i < m; i++) printf(ans[i] ? "WIN\n":"LOSE\n");

    return 0;
}