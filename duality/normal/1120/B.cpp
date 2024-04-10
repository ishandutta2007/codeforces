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

string a,b;
int n;
int need[100000];
queue<int> Q;
vpii sol;
int check(int u) {
    if ((u < 0) || (u >= n-1)) return 0;
    int i = u;
    int x = a[i]-'0';
    int y = a[i+1]-'0';
    //cout<<x+need[i]<<","<<y+need[i]<<endl;
    if (need[i] == 0) return 0;
    int d = (need[i] > 0) ? 1:-1;
    if (i == 0) {
        if (((x+d) > 0) && ((x+d) <= 9) \
            && ((y+d) >= 0) && ((y+d) <= 9)) Q.push(i);
    }
    else {
        if (((x+d) >= 0) && ((x+d) <= 9) \
            && ((y+d) >= 0) && ((y+d) <= 9)) Q.push(i);
    }
    return 0;
}
int check2(int u) {
    if ((u < 0) || (u >= n-1)) return 0;
    int i = u;
    int x = a[i]-'0';
    int y = a[i+1]-'0';
    //cout<<x+need[i]<<","<<y+need[i]<<endl;
    if (need[i] == 0) return 0;
    int d = (need[i] > 0) ? 1:-1;
    if (i == 0) {
        if (((x+d) > 0) && ((x+d) <= 9) \
            && ((y+d) >= 0) && ((y+d) <= 9)) return 1;
    }
    else {
        if (((x+d) >= 0) && ((x+d) <= 9) \
            && ((y+d) >= 0) && ((y+d) <= 9)) return 1;
    }
    return 0;
}
int main() {
    int i;
    cin >> n;
    cin >> a >> b;

    int c = 0;
    for (i = 0; i < n-1; i++) {
        int x = a[i]-'0'+c;
        int y = b[i]-'0';
        need[i] = y-x,c = y-x;
        //cout<<need[i]<<endl;
    }
    int x = a[i]-'0'+c;
    int y = b[i]-'0';
    if (y-x != 0) {
        printf("-1\n");
        return 0;
    }

    LLI ans = 0;
    for (i = 0; i < n-1; i++) ans += abs(need[i]);
    for (i = 0; i < n-1; i++) check(i);
    while (!Q.empty()) {
        int u = Q.front();
        //cout<<"u:"<<u<<endl;
        Q.pop();

        if (!check2(u)) continue;
        if (need[u] > 0) {
            a[u]++,a[u+1]++,need[u]--;
            sol.pb(mp(u,1));
            check(u-1),check(u),check(u+1);
        }
        else if (need[u] < 0) {
            a[u]--,a[u+1]--,need[u]++;
            sol.pb(mp(u,-1));
            check(u-1),check(u),check(u+1);
        }
        if (sol.size() > 100005) break;
    }
    printf("%I64d\n",ans);
    for (i = 0; i < min((int) sol.size(),100000); i++) printf("%d %d\n",sol[i].first+1,sol[i].second);

    return 0;
}