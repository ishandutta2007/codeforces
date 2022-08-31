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

int xx[20][20],must[20][20],n,m;
vector<vi> sol;
int swap2(int a,int b,int c,int d,int e,int f) {
    vi v;
    v.pb(a),v.pb(b),v.pb(c),v.pb(f),v.pb(e),v.pb(d);
    sol.pb(v),v.clear();
    v.pb(a),v.pb(d),v.pb(e),v.pb(f);
    sol.pb(v),v.clear();
    v.pb(b),v.pb(f),v.pb(e),v.pb(c);
    sol.pb(v),v.clear();
    return 0;
}
int myswap(pii a,pii b) {
    if (a.second == b.second) {
        int f = 0;
        if (a.first > b.first) swap(a,b),f = 1;
        int x = a.second,y = a.first;
        if ((x-1 >= 0) && !must[y][x] && !must[y+1][x] && !must[y][x-1] && !must[y+1][x-1]) {
            vi v;
            vpii pos;
            v.pb(xx[y][x]),v.pb(xx[y+1][x]),v.pb(xx[y+1][x-1]),v.pb(xx[y][x-1]);
            pos.pb(mp(x,y)),pos.pb(mp(x,y+1)),pos.pb(mp(x-1,y+1)),pos.pb(mp(x-1,y));
            if (f) reverse(v.begin(),v.end()),reverse(pos.begin(),pos.end());
            sol.pb(v);
            int i;
            for (i = 0; i < 4; i++) xx[pos[i].second][pos[i].first] = v[(i+3) % 4];
            return 0;
        }

        if ((y >= 0) && (y+2 < n) && (x >= 0) && (x+1 < m))
            swap2(xx[y+2][x+1],xx[y+1][x+1],xx[y][x+1],xx[y+2][x],xx[y+1][x],xx[y][x]);
        else if ((y >= 0) && (y+2 < n) && (x-1 >= 0) && (x < m))
            swap2(xx[y+2][x-1],xx[y+1][x-1],xx[y][x-1],xx[y+2][x],xx[y+1][x],xx[y][x]);
        else if ((y-1 >= 0) && (y+1 < n) && (x >= 0) && (x+1 < m))
            swap2(xx[y-1][x+1],xx[y][x+1],xx[y+1][x+1],xx[y-1][x],xx[y][x],xx[y+1][x]);
        else if ((y-1 >= 0) && (y+1 < n) && (x-1 >= 0) && (x < m))
            swap2(xx[y-1][x-1],xx[y][x-1],xx[y+1][x-1],xx[y-1][x],xx[y][x],xx[y+1][x]);
    }
    else {
        if (a.second > b.second) swap(a,b);
        int x = a.second,y = a.first;
        if ((x >= 0) && (x+2 < m) && (y >= 0) && (y+1 < n))
            swap2(xx[y+1][x+2],xx[y+1][x+1],xx[y+1][x],xx[y][x+2],xx[y][x+1],xx[y][x]);
        else if ((x >= 0) && (x+2 < m) && (y-1 >= 0) && (y < n))
            swap2(xx[y-1][x+2],xx[y-1][x+1],xx[y-1][x],xx[y][x+2],xx[y][x+1],xx[y][x]);
        else if ((x-1 >= 0) && (x+1 < m) && (y >= 0) && (y+1 < n))
            swap2(xx[y+1][x-1],xx[y+1][x],xx[y+1][x+1],xx[y][x-1],xx[y][x],xx[y][x+1]);
        else if ((x-1 >= 0) && (x+1 < m) && (y-1 >= 0) && (y < n))
            swap2(xx[y-1][x-1],xx[y-1][x],xx[y-1][x+1],xx[y][x-1],xx[y][x],xx[y][x+1]);
    }
    swap(xx[a.first][a.second],xx[b.first][b.second]);
    return 0;
}
int main() {
    int i,j;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) scanf("%d",&xx[i][j]);
    }

    int k,l;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            int y = i*m+j+1;
            for (k = 0; k < n; k++) {
                for (l = 0; l < m; l++) {
                    if (xx[k][l] == y) break;
                }
                if (l < m) break;
            }
            while (l < j) myswap(mp(k,l),mp(k,l+1)),l++;
            while (l > j) myswap(mp(k,l),mp(k,l-1)),l--;
            while (k > i) myswap(mp(k,l),mp(k-1,l)),k--;
            must[i][j] = 1;
        }
    }
    printf("%d\n",sol.size());
    for (i = 0; i < sol.size(); i++) {
        printf("%d",sol[i].size());
        for (j = 0; j < sol[i].size(); j++) printf(" %d",sol[i][j]);
        printf("\n");
    }

    return 0;
}