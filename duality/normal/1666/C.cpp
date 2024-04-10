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

pii p[3];
vi x,y;
int parent[9];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
int merge(int a,int b) {
    a = find(a),b = find(b);
    if (a != b) parent[a] = b;
    return 0;
}
int main() {
    int i;
    for (i = 0; i < 3; i++) cin >> p[i].x >> p[i].y,x.pb(p[i].x),y.pb(p[i].y);
    sort(x.begin(),x.end()),sort(y.begin(),y.end());
    x.resize(unique(x.begin(),x.end())-x.begin());
    y.resize(unique(y.begin(),y.end())-y.begin());
    while (x.size() < 3) x.pb(x.back()+1);
    while (y.size() < 3) y.pb(y.back()+1);

    int j;
    int b = -1;
    LLI m = 1e18;
    for (i = 0; i < (1 << 12); i++) {
        LLI s = 0;
        for (j = 0; j < 9; j++) parent[j] = j;
        for (j = 0; j < 12; j++) {
            if (i & (1 << j)) {
                if (j == 0) merge(0,1),s += x[1]-x[0];
                else if (j == 1) merge(1,2),s += x[2]-x[1];
                else if (j == 2) merge(3,4),s += x[1]-x[0];
                else if (j == 3) merge(4,5),s += x[2]-x[1];
                else if (j == 4) merge(6,7),s += x[1]-x[0];
                else if (j == 5) merge(7,8),s += x[2]-x[1];
                else if (j == 6) merge(0,3),s += y[1]-y[0];
                else if (j == 7) merge(3,6),s += y[2]-y[1];
                else if (j == 8) merge(1,4),s += y[1]-y[0];
                else if (j == 9) merge(4,7),s += y[2]-y[1];
                else if (j == 10) merge(2,5),s += y[1]-y[0];
                else if (j == 11) merge(5,8),s += y[2]-y[1];
            }
        }
        vi w;
        for (j = 0; j < 3; j++) {
            int u = lower_bound(x.begin(),x.end(),p[j].x)-x.begin();
            int v = lower_bound(y.begin(),y.end(),p[j].y)-y.begin();
            w.pb(3*v+u);
        }
        for (j = 0; j < 2; j++) {
            if (find(w[j]) != find(w[j+1])) break;
        }
        if (j == 2) {
            if (s < m) m = s,b = i;
        }
    }
    printf("%d\n",__builtin_popcount(b));
    for (i = 0; i < 12; i++) {
        if (b & (1 << i)) {
            if (i == 0) printf("%d %d %d %d\n",x[0],y[0],x[1],y[0]);
            else if (i == 1) printf("%d %d %d %d\n",x[1],y[0],x[2],y[0]);
            else if (i == 2) printf("%d %d %d %d\n",x[0],y[1],x[1],y[1]);
            else if (i == 3) printf("%d %d %d %d\n",x[1],y[1],x[2],y[1]);
            else if (i == 4) printf("%d %d %d %d\n",x[0],y[2],x[1],y[2]);
            else if (i == 5) printf("%d %d %d %d\n",x[1],y[2],x[2],y[2]);
            else if (i == 6) printf("%d %d %d %d\n",x[0],y[0],x[0],y[1]);
            else if (i == 7) printf("%d %d %d %d\n",x[0],y[1],x[0],y[2]);
            else if (i == 8) printf("%d %d %d %d\n",x[1],y[0],x[1],y[1]);
            else if (i == 9) printf("%d %d %d %d\n",x[1],y[1],x[1],y[2]);
            else if (i == 10) printf("%d %d %d %d\n",x[2],y[0],x[2],y[1]);
            else if (i == 11) printf("%d %d %d %d\n",x[2],y[1],x[2],y[2]);
        }
    }

    return 0;
}