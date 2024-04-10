#define DEBUG 1

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
#define MOD 1000000007

int p[200000];
int f[2000001];
int num[2000001],yes[2000001],type[200000];
int ways[2000001];
vpii factor(int x) {
    vpii v;
    while (x > 1) {
        int ff = f[x],c = 0;
        while ((x % ff) == 0) c++,x /= ff;
        v.pb(mp(ff,c));
    }
    return v;
}
queue<int> Q;
int done[2000001];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    memset(yes,-1,sizeof(yes));
    for (i = 0; i < n; i++) scanf("%d",&p[i]);//,yes[p[i]] = i; wow i'm dumb
    sort(p,p+n);
    for (i = 0; i < n; i++) yes[p[i]] = i;

    int j;
    vi pp;
    for (i = 2; i <= 2000000; i++) {
        if (f[i] == 0) {
            for (j = i; j <= 2000000; j += i) f[j] = i;
            pp.pb(i);
        }
    }
    //for (i = 0; i < n; i++) p[i] = pp[rand() % pp.size()];//,yes[p[i]] = i;
    //sort(p,p+n);
    //for (i = 0; i < n; i++) yes[p[i]] = i;
    for (i = 1; i < n; i++) {
        if (p[i-1] == p[i]) {
            num[p[i]] = max(num[p[i]],1);
            vpii v = factor(p[i]-1);
            for (j = 0; j < v.size(); j++) num[v[j].first] = max(num[v[j].first],v[j].second),Q.push(v[j].first);
            type[i-1] = 1,type[i] = 2,yes[p[i]] = -1,done[p[i]] = 1;
            //cout<<p[i]<<endl;
        }
    }
    //printArr(p,n);
    //cout<<"!!!!!!"<<type[0]<<endl;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        if (yes[u] == -1) done[u] = 1;
        if (done[u]) continue;
        //cout<<"popped "<<u<<endl;
        done[u] = 1;
        vpii v = factor(u-1);
        for (i = 0; i < v.size(); i++) num[v[i].first] = max(num[v[i].first],v[i].second),Q.push(v[i].first);
        //cout<<"set "<<yes[u]<<" to 2"<<endl;
        type[yes[u]] = 2;
    }
    for (i = 0; i < n; i++) {
        if (!done[p[i]]) {
            //cout<<"i:"<<p[i]<<endl;
            assert(num[p[i]] == 0);
            //cout<<type[i]<<endl;
            assert(type[i] == 0);
            num[p[i]] = max(num[p[i]],1),type[i] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        vpii v = factor((type[i] == 2) ? (p[i]-1):p[i]);
        for (j = 0; j < v.size(); j++) {
            if (num[v[j].first] == v[j].second) ways[v[j].first]++;
        }
    }
    int t = 0;
    for (i = 0; i < n; i++) {
        vpii v = factor((type[i] == 2) ? (p[i]-1):p[i]);
        int useful = 0;
        for (j = 0; j < v.size(); j++) {
            if ((num[v[j].first] == v[j].second) && (ways[v[j].first] == 1)) useful = 1;
        }
        if (!useful) {
            t = 1;
            break;
        }
    }
    LLI ans = 1;
    for (i = 2; i <= 2000000; i++) {
        if (num[i] > 0) {
            for (j = 0; j < num[i]; j++) ans *= i,ans %= MOD;
        }
    }
    if (t) ans++,ans %= MOD;
    printf("%I64d\n",ans);

    return 0;
}