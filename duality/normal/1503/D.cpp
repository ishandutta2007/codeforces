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

int a[400000],b[400000];
pii parent[200000];
pii find(int n) {
    if (parent[n].first != n) {
        pii p = find(parent[n].first);
        parent[n] = mp(p.first,parent[n].second^p.second);
    }
    return parent[n];
}
int merge(int a,int b,int w) {
    pii pa = find(a),pb = find(b);
    w ^= pa.second^pb.second;
    if (pa.first == pb.first) {
        if (w == 1) {
            printf("-1\n");
            exit(0);
        }
        else return 0;
    }
    else {
        parent[pa.first] = mp(pb.first,w);
        return 0;
    }
}
bool comp(int x,int y) {
    return mp(a[x],b[x]) < mp(a[y],b[y]);
}
vi com[200000];
int order[400000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&a[i],&b[i]);

    for (i = 0; i < n; i++) parent[i] = mp(i,0);
    for (i = 0; i < n; i++) a[i+n] = b[i],b[i+n] = a[i];
    for (i = 0; i < 2*n; i++) order[i] = i;
    sort(order,order+2*n,comp);
    vi Q;
    for (i = 0; i < 2*n; i++) {
        int u = order[i];
        int v = -1;
        while (!Q.empty() && (b[Q.back()] <= b[u])) {
            merge(Q.back() % n,u % n,(u >= n)^(Q.back() >= n)^1);
            if (v == -1) v = Q.back();
            Q.pop_back();
        }
        if (v == -1) Q.pb(u);
        else Q.pb(v);
    }
    int j,ans = 0;
    for (i = 0; i < n; i++) com[find(i).first].pb(i);
    for (i = 0; i < n; i++) {
        if (!com[i].empty()) {
            int x = 0,y = 0;
            for (j = 0; j < com[i].size(); j++) {
                if (find(com[i][j]).second) y++;
                else x++;
            }
            ans += min(x,y);
            for (j = 0; j < com[i].size(); j++) {
                if (find(com[i][j]).second == (y <= x)) swap(a[com[i][j]],b[com[i][j]]);
            }
        }
    }
    for (i = 0; i < n; i++) order[i] = i;
    sort(order,order+n,comp);
    for (i = 1; i < n; i++) {
        if ((a[order[i-1]] >= a[order[i]]) || (b[order[i-1]] <= b[order[i]])) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",ans);

    return 0;
}