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

int same(int x1,int y1,int x2,int y2) {
    if (x1 == x2) {
        if (x1 == 0) return 1;
        else if ((1 << __builtin_ctz(x1)) > (y1^y2)) return 1;
    }
    if (y1 == y2) {
        if (y1 == 0) return 1;
        else if ((1 << __builtin_ctz(y1)) > (x1^x2)) return 1;
    }
    return 0;
}
struct event { int x,y,t; };
bool comp(event a,event b) {
    if (a.x+a.y == b.x+b.y) return a.t < b.t;
    else return a.x+a.y < b.x+b.y;
}
vector<event> events;
map<int,int> x,y;
vi S;
int add(int d) {
    if (d < 0) return 0;
    S.pb(d);
    return 0;
}
int main() {
    int i;
    int m,x1,y1,x2,y2;
    scanf("%d",&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        while (!same(x1,y1,x2,y2)) {
            int n1,n2;
            if (x1 == 0) n1 = y1-1;
            else if (y1 == 0) n1 = x1-1;
            else n1 = 1 << min(__builtin_ctz(x1),__builtin_ctz(y1));
            if (x2 == 0) n2 = y2-1;
            else if (y2 == 0) n2 = x2-1;
            else n2 = 1 << min(__builtin_ctz(x2),__builtin_ctz(y2));

            if (x1+y1-n1 < x2+y2-n2) swap(x1,x2),swap(y1,y2);
            if (x1 == 0) {
                events.pb((event){x1,1,2});
                events.pb((event){x1,y1+1,-2});
                y1 = 0;
            }
            else if (y1 == 0) {
                events.pb((event){1,y1,1});
                events.pb((event){x1+1,y1,-1});
                x1 = 0;
            }
            else {
                if (__builtin_ctz(x1) < __builtin_ctz(y1)) {
                    events.pb((event){x1-(1 << __builtin_ctz(x1))+1,y1,1});
                    events.pb((event){x1+1,y1,-1});
                    x1 -= (1 << __builtin_ctz(x1));
                }
                else {
                    events.pb((event){x1,y1-(1 << __builtin_ctz(y1))+1,2});
                    events.pb((event){x1,y1+1,-2});
                    y1 -= (1 << __builtin_ctz(y1));
                }
            }
        }
        if (x1+y1 > x2+y2) swap(x1,x2),swap(y1,y2);
        if (x1 == x2) events.pb((event){x1,y1,2}),events.pb((event){x2,y2+1,-2});
        else events.pb((event){x1,y1,1}),events.pb((event){x2+1,y2,-1});
    }
    sort(events.begin(),events.end(),comp);
    events.pb((event){(int) 1e9+5,(int) 1e9+5,0});

    int ans = 0,num = 0;
    for (i = 0; i < events.size()-1; i++) {
        if (events[i].t > 0) {
            if (events[i].t == 1) {
                y[events[i].y]++;
                if ((y[events[i].y] == 1) && x.count(events[i].x)) num++;
            }
            else {
                x[events[i].x]++;
                if ((x[events[i].x] == 1) && y.count(events[i].y)) num++;
            }
        }
        else {
            if (events[i].t == -1) {
                if (y[events[i].y] == 1) y.erase(events[i].y);
                else y[events[i].y]--;
            }
            else {
                if (x[events[i].x] == 1) x.erase(events[i].x);
                else x[events[i].x]--;
            }
        }
        if (events[i+1].x+events[i+1].y != events[i].x+events[i].y) {
            if ((x.size()+y.size()+num) & 1) add(events[i].x+events[i].y),add(events[i].x+events[i].y-1);
            if ((x.size()+y.size()) & 1) add(events[i+1].x+events[i+1].y-1),add(events[i].x+events[i].y);
            num = 0;
        }
    }
    sort(S.begin(),S.end());
    for (i = 0; i < S.size(); i++) {
        if ((i < S.size()-1) && (S[i] == S[i+1])) i++;
        else ans++;
    }
    printf("%d\n",ans);

    return 0;
}