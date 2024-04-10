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

pii a[100000],b[100000];
struct event { int x,t; pii p; };
bool comp(event a,event b) {
    return a.x < b.x;
}
vector<event> events;
multiset<int> S1,S2;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d %d %d",&a[i].first,&a[i].second,&b[i].first,&b[i].second);
    if (n == 1) {
        printf("YES\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        events.pb((event){a[i].first,1,b[i]});
        events.pb((event){a[i].second+1,-1,b[i]});
    }
    sort(events.begin(),events.end(),comp);
    int c = 0;
    for (i = 0; i < events.size(); i++) {
        if (events[i].t == 1) {
            S1.insert(events[i].p.first);
            S2.insert(events[i].p.second);
            c++;
        }
        else if (events[i].t == -1) {
            S1.erase(S1.find(events[i].p.first));
            S2.erase(S2.find(events[i].p.second));
            c--;
        }
        if ((i == events.size()-1) || (events[i].x < events[i+1].x)) {
            if ((c >= 2) && (*S2.begin() < *(--S1.end()))) {
                printf("NO\n");
                return 0;
            }
        }
    }
    events.clear(),S1.clear(),S2.clear();
    for (i = 0; i < n; i++) {
        events.pb((event){b[i].first,1,a[i]});
        events.pb((event){b[i].second+1,-1,a[i]});
    }
    sort(events.begin(),events.end(),comp);
    c = 0;
    for (i = 0; i < events.size(); i++) {
        if (events[i].t == 1) {
            S1.insert(events[i].p.first);
            S2.insert(events[i].p.second);
            c++;
        }
        else if (events[i].t == -1) {
            S1.erase(S1.find(events[i].p.first));
            S2.erase(S2.find(events[i].p.second));
            c--;
        }
        if ((i == events.size()-1) || (events[i].x < events[i+1].x)) {
            if ((c >= 2) && (*S2.begin() < *(--S1.end()))) {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");

    return 0;
}