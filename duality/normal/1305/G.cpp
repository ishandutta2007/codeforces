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

int a[200001];
int parent[200001];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
pii best[1 << 18][2];
pii pp[200001];
int main() {
    int i;
    int n;
    LLI ans = 0;
    scanf("%d",&n),n++;
    for (i = 1; i < n; i++) scanf("%d",&a[i]),ans -= a[i],parent[i] = i;

    int j,c = n;
    while (c > 1) {
        for (i = 0; i < (1 << 18); i++) best[i][0] = best[i][1] = mp(-1,-1);
        for (i = 0; i < n; i++) {
            pii p = mp(a[i],find(i));
            if (p.first >= best[a[i]][0].first) {
                if (p.second == best[a[i]][0].second) best[a[i]][0] = p;
                else best[a[i]][1] = best[a[i]][0],best[a[i]][0] = p;
            }
            else if (p.first >= best[a[i]][1].first) {
                if (p.second != best[a[i]][0].second) best[a[i]][1] = p;
            }
        }
        for (i = 0; i < 18; i++) {
            for (j = 0; j < (1 << 18); j++) {
                if (j & (1 << i)) {
                    pii p = best[j^(1 << i)][0];
                    if (p.first >= best[j][0].first) {
                        if (p.second == best[j][0].second) best[j][0] = p;
                        else best[j][1] = best[j][0],best[j][0] = p;
                    }
                    else if (p.first >= best[j][1].first) {
                        if (p.second != best[j][0].second) best[j][1] = p;
                    }
                    p = best[j^(1 << i)][1];
                    if (p.first >= best[j][0].first) {
                        if (p.second == best[j][0].second) best[j][0] = p;
                        else best[j][1] = best[j][0],best[j][0] = p;
                    }
                    else if (p.first >= best[j][1].first) {
                        if (p.second != best[j][0].second) best[j][1] = p;
                    }
                }
            }
        }
        for (i = 0; i < n; i++) pp[i] = mp(-1,-1);
        vi r;
        for (i = 0; i < n; i++) {
            pii p;
            if (best[((1 << 18)-1)^a[i]][0].second == find(i)) p = best[((1 << 18)-1)^a[i]][1];
            else p = best[((1 << 18)-1)^a[i]][0];
            if (p.second != -1) pp[find(i)] = max(pp[find(i)],mp(p.first+a[i],p.second));
            if (i == find(i)) r.pb(i);
        }
        for (i = 0; i < r.size(); i++) {
            if (find(pp[r[i]].second) != find(r[i])) {
                ans += pp[r[i]].first;
                parent[find(pp[r[i]].second)] = find(r[i]),c--;
            }
        }
    }
    printf("%I64d\n",ans);

    return 0;
}