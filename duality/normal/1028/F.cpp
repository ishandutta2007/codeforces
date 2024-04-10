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
int t[200000],x[200000],y[200000];
vlli poss;
vpii points[200000];
map<pii,int> M;
int main() {
    int i;
    int q;
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d %d %d",&t[i],&x[i],&y[i]);
        if (t[i] == 1) poss.pb((LLI) x[i]*x[i]+(LLI) y[i]*y[i]);
    }
    sort(poss.begin(),poss.end());
    poss.resize(unique(poss.begin(),poss.end())-poss.begin());

    int j,num = 0;
    for (i = 0; i < q; i++) {
        if (t[i] == 1) {
            int p = lower_bound(poss.begin(),poss.end(),(LLI) x[i]*x[i]+(LLI) y[i]*y[i])-poss.begin();
            points[p].pb(mp(x[i],y[i]));
            for (j = 0; j < points[p].size(); j++) {
                int xx = points[p][j].first+x[i];
                int yy = points[p][j].second+y[i];
                int g = gcd(xx,yy);
                xx /= g,yy /= g;
                M[mp(xx,yy)] += (j == points[p].size()-1) ? 1:2;
            }
            num++;
        }
        else if (t[i] == 2) {
            int p = lower_bound(poss.begin(),poss.end(),(LLI) x[i]*x[i]+(LLI) y[i]*y[i])-poss.begin();
            int q = find(points[p].begin(),points[p].end(),mp(x[i],y[i]))-points[p].begin();
            swap(points[p].back(),points[p][q]);
            for (j = 0; j < points[p].size(); j++) {
                int xx = points[p][j].first+x[i];
                int yy = points[p][j].second+y[i];
                int g = gcd(xx,yy);
                xx /= g,yy /= g;
                M[mp(xx,yy)] -= (j == points[p].size()-1) ? 1:2;
                if (M[mp(xx,yy)] == 0) M.erase(mp(xx,yy));
            }
            points[p].pop_back();
            num--;
        }
        else {
            int g = gcd(x[i],y[i]);
            x[i] /= g,y[i] /= g;
            printf("%d\n",num-M[mp(x[i],y[i])]);
        }
    }

    return 0;
}