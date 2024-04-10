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

pii p[2000];
int pos[2000];
bool comp(pii a,pii b) {
    if (a.y == b.y) return a.x > b.x;
    else return a.y < b.y;
}
vpii v;
bool comp2(pii a,pii b) {
    pii c = mp(p[a.first].x-p[a.second].x,p[a.first].y-p[a.second].y);
    pii d = mp(p[b.first].x-p[b.second].x,p[b.first].y-p[b.second].y);
    return (LLI) c.x*d.y > (LLI) c.y*d.x;
}
LLI area(pii a,pii b,pii c) {
    return abs((LLI) (b.x-a.x)*(c.y-a.y)-(LLI) (b.y-a.y)*(c.x-a.x));
}
int main() {
    int i;
    int n;
    LLI S;
    scanf("%d %I64d",&n,&S);
    for (i = 0; i < n; i++) scanf("%d %d",&p[i].x,&p[i].y);
    sort(p,p+n,comp);

    int j;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) v.pb(mp(i,j));
        pos[i] = i;
    }
    sort(v.begin(),v.end(),comp2);
    for (i = 0; i < v.size(); i++) {
        swap(p[pos[v[i].first]],p[pos[v[i].second]]);
        swap(pos[v[i].first],pos[v[i].second]);
        int a = pos[v[i].first],b = pos[v[i].second];
        if (a > b) swap(a,b);
        int l = 0,r = a-1;
        while (l <= r) {
            int m = (l+r) / 2;
            LLI A = area(p[m],p[a],p[b]);
            if (A == 2*S) {
                printf("Yes\n");
                printf("%d %d\n%d %d\n%d %d\n",p[m].x,p[m].y,p[a].x,p[a].y,p[b].x,p[b].y);
                return 0;
            }
            if (A < 2*S) r = m-1;
            else l = m+1;
        }
        l = b+1,r = n-1;
        while (l <= r) {
            int m = (l+r) / 2;
            LLI A = area(p[m],p[a],p[b]);
            if (A == 2*S) {
                printf("Yes\n");
                printf("%d %d\n%d %d\n%d %d\n",p[m].x,p[m].y,p[a].x,p[a].y,p[b].x,p[b].y);
                return 0;
            }
            if (A > 2*S) r = m-1;
            else l = m+1;
        }
    }
    printf("No\n");

    return 0;
}