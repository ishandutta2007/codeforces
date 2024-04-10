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

int poss[1000][10],diff[1000][10];
pair<pii,int> parent[1000][20000];
queue<pii> Q;
int main() {
    int a;
    cin >> a;

    int i,j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < 10; j++) {
            int l = (a*j+i) % 10,c = (a*j+i) / 10;
            poss[i][j] = c,diff[i][j] = a*l-j;
        }
    }
    for (i = 0; i < a; i++) {
        for (j = 0; j < 20000; j++) parent[i][j] = mp(mp(-1,-1),-1);
    }
    for (i = 1; i < 10; i++) {
        parent[poss[0][i]][diff[0][i]+2000] = mp(mp(-1,-1),i);
        Q.push(mp(poss[0][i],diff[0][i]));
    }
    while (!Q.empty()) {
        pii u = Q.front();
        Q.pop();

        if (u == mp(0,0)) break;
        for (i = 0; i < 10; i++) {
            int c = poss[u.first][i];
            int d = u.second+diff[u.first][i];
            if ((d >= -2000) && (d < 4000) && (parent[c][d+2000].second == -1)) {
                parent[c][d+2000] = mp(u,i);
                Q.push(mp(c,d));
            }
        }
    }
    if (parent[0][2000].second == -1) printf("-1\n");
    else {
        vi ans;
        pii u = mp(0,0);
        while (parent[u.first][u.second+2000].first.first != -1) {
            int d = parent[u.first][u.second+2000].second;
            if (!ans.empty() || (d > 0)) ans.pb(d);
            u = parent[u.first][u.second+2000].first;
        }
        ans.pb(parent[u.first][u.second+2000].second);
        for (i = 0; i < ans.size(); i++) printf("%d",ans[i]);
        printf("\n");
    }
    while (!Q.empty()) Q.pop();


    return 0;
}