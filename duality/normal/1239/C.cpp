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

int t[100000];
set<pair<LLI,int> > events;
set<int> inQueue,wait;
queue<int> Q;
LLI ans[100000];
int main() {
    int i;
    int n,pp;
    scanf("%d %d",&n,&pp);
    for (i = 0; i < n; i++) scanf("%d",&t[i]),events.insert(mp(t[i],i));

    while (!events.empty()) {
        pair<LLI,int> p = *events.begin();
        events.erase(events.begin());

        if (p.second < 1e9) {
            if (!inQueue.empty() && (*inQueue.begin() < p.second)) wait.insert(p.second);
            else {
                if (Q.empty()) events.insert(mp(p.first+pp,1e9));
                inQueue.insert(p.second),Q.push(p.second);
            }
        }
        else {
            ans[Q.front()] = p.first;
            inQueue.erase(Q.front()),Q.pop();
            if (!Q.empty()) events.insert(mp(p.first+pp,1e9));
            if (!wait.empty()) {
                int u = *wait.begin();
                if (inQueue.empty() || (*inQueue.begin() > u)) {
                    wait.erase(wait.begin());
                    if (Q.empty()) events.insert(mp(p.first+pp,1e9));
                    inQueue.insert(u),Q.push(u);
                }
            }
        }
    }
    for (i = 0; i < n; i++) printf("%I64d ",ans[i]);
    printf("\n");

    return 0;
}