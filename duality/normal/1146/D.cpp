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

int gcd(int a,int b) {
    int t;
    while (a > 0) t = b % a,b = a,a = t;
    return b;
}
int dist[300000],c[300000];
priority_queue<pii> H;
int main() {
    int m,a,b;
    cin >> m >> a >> b;

    int g = gcd(a,b);

    int i;
    for (i = 0; i < a+b; i++) dist[i] = -1;
    dist[0] = 0;
    H.push(mp(0,0));
    while (!H.empty()) {
        int u = H.top().second;
        int d = -H.top().first;
        H.pop();

        if (d > dist[u]) continue;
        if (u+a < a+b) {
            if ((dist[u+a] == -1) || (max(d,u+a) < dist[u+a])) {
                dist[u+a] = max(d,u+a);
                H.push(mp(-dist[u+a],u+a));
            }
        }
        if (u-b >= 0) {
            if ((dist[u-b] == -1) || (max(d,u-b) < dist[u-b])) {
                dist[u-b] = max(d,u-b);
                H.push(mp(-dist[u-b],u-b));
            }
        }
    }
    LLI ans = 0;
    for (i = 0; i < a+b; i++) {
            debug dist[i];
        if (dist[i] != -1) c[dist[i]]++;
    }
    int curr = 0;
    for (i = 0; i <= min(m,a+b-1); i++) {
        curr += c[i];
        ans += curr;
        printVar(ans);
    }
    printVar(ans);
    int mm = a+b;
    if (m >= a+b) {
        ans += (LLI) curr*(m-mm+1);
        int x = m/g-mm/g;
        ans += (LLI) (m-mm+1)*(x+1);
        ans -= ((LLI) x*(x+1)/2)*g;
    }
    cout << ans << endl;

    return 0;
}