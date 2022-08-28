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
#define x first
#define y second

int a[100000];
deque<pii> lower,upper,path;
int ccw(pii a,pii b,pii c) {
    return (LLI) (b.x-a.x)*(c.y-a.y) >= (LLI) (b.y-a.y)*(c.x-a.x);
}
int main() {
    int i;
    int L,n;
    scanf("%d %d",&L,&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);

    upper.pb(mp(0,0)),lower.pb(mp(0,0)),path.pb(mp(0,0));
    for (i = 1; i <= n; i++) {
        int l = (i == n) ? L:a[i-1],r = (i == n) ? L:a[i];
        while ((lower.size() >= 2) && !ccw(lower[0],lower[1],mp(i,r))) {
            path.pb(lower[1]);
            while (!upper.empty() && (upper[0].x <= lower[1].x)) upper.pop_front();
            upper.push_front(lower[1]),lower.pop_front();
            while ((upper.size() >= 3) && !ccw(upper[0],upper[1],upper[2])) upper[1] = upper[0],upper.pop_front();
        }
        while ((upper.size() >= 2) && ccw(upper[0],upper[1],mp(i,l))) {
            path.pb(upper[1]);
            while (!lower.empty() && (lower[0].x <= upper[1].x)) lower.pop_front();
            lower.push_front(upper[1]),upper.pop_front();
            while ((lower.size() >= 3) && ccw(lower[0],lower[1],lower[2])) lower[1] = lower[0],lower.pop_front();
        }
        lower.pb(mp(i,l)),upper.pb(mp(i,r));
        while ((upper.size() >= 3) && !ccw(upper[upper.size()-3],upper[upper.size()-2],upper.back()))
            upper[upper.size()-2] = upper.back(),upper.pop_back();
        while ((lower.size() >= 3) && ccw(lower[lower.size()-3],lower[lower.size()-2],lower.back()))
            lower[lower.size()-2] = lower.back(),lower.pop_back();
    }
    int j = 0;
    path.pb(mp(n,L));
    int p = 0;
    for (i = 0; i < n; i++) {
        while ((j+1 < path.size()) && (path[j+1].x <= i)) j++;
        LLI y = (LLI) (path[j+1].y-path[j].y)*(i+1-path[j].x)/(path[j+1].x-path[j].x)+path[j].y;
        printf("%d %lld\n",p,y),p = y;
    }

    return 0;
}