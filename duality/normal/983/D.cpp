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

int x1[100000],y1[100000],x2[100000],y2[100000];
vi lines;
struct event { int x,l,r,t; };
bool comp(event a,event b) {
    if (a.x == b.x) return a.t > b.t;
    else return a.x < b.x;
}
vector<event> events;
int ans[100000];
set<int,greater<int> > seen[1 << 19],rem[1 << 19];
int best[1 << 19],need[1 << 19];
int update(int s,int e,int as,int ae,int i,int num,int t) {
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        if (t == 1) rem[i].insert(num);
        else if (t == 0) rem[i].erase(num),seen[i].insert(num);
        else {
            if (seen[i].count(num)) seen[i].erase(num);
            else rem[i].erase(num);
        }
        best[i] = (s == e) ? 0:max(best[2*i+1],best[2*i+2]);
        need[i] = (s == e) ? 0:min(need[2*i+1],need[2*i+2]);
        if (!rem[i].empty()) best[i] = max(best[i],*rem[i].begin());
        if (!seen[i].empty()) need[i] = max(need[i],*seen[i].begin());
        if (need[i] > best[i]) best[i] = 0;
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,num,t),update(mid+1,e,as,ae,2*i+2,num,t);
    best[i] = max(best[2*i+1],best[2*i+2]),need[i] = min(need[2*i+1],need[2*i+2]);
    if (!rem[i].empty()) best[i] = max(best[i],*rem[i].begin());
    if (!seen[i].empty()) need[i] = max(need[i],*seen[i].begin());
    if (need[i] > best[i]) best[i] = 0;
    return 0;
}
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
        lines.pb(y1[i]),lines.pb(y2[i]);
    }
    sort(lines.begin(),lines.end());
    lines.resize(unique(lines.begin(),lines.end())-lines.begin());
    for (i = 0; i < n; i++) {
        y1[i] = lower_bound(lines.begin(),lines.end(),y1[i])-lines.begin();
        y2[i] = lower_bound(lines.begin(),lines.end(),y2[i])-lines.begin()-1;
        events.pb((event){x1[i],y1[i],y2[i],i+1});
        events.pb((event){x2[i],y1[i],y2[i],-(i+1)});
    }
    sort(events.begin(),events.end(),comp);

    int ans = 1;
    for (i = 0; i < events.size(); i++) {
        if (events[i].t > 0) update(0,lines.size()-2,events[i].l,events[i].r,0,events[i].t,1);
        else update(0,lines.size()-2,events[i].l,events[i].r,0,-events[i].t,-1);
        while (best[0] != 0) ans++,update(0,lines.size()-2,y1[best[0]-1],y2[best[0]-1],0,best[0],0);
    }
    printf("%d\n",ans);

    return 0;
}