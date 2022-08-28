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
const double PI = acos(-1.0);

pii P[100000];
double d[100000],a[100000];
pair<double,double> in[100000];
vector<pair<double,double> > vv;
int nn[200000][18];
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d %d",&P[i].x,&P[i].y);

    double l = 0,r = 1e99;
    for (i = 0; i < n; i++) a[i] = atan2(P[i].y,P[i].x),d[i] = sqrt((LLI) P[i].x*P[i].x+(LLI) P[i].y*P[i].y),r = min(r,d[i]);
    while (abs(l-r) > 1e-7) {
        double mm = (l+r) / 2;

        for (i = 0; i < n; i++) {
            double t = acos(mm/d[i]);
            double s = a[i]-t;
            if (s < -PI) s += 2*PI;
            double e = a[i]+t;
            if (e > PI) e -= 2*PI;
            if (e < s) e += 2*PI;
            in[i] = mp(s,e);
        }
        sort(in,in+n),vv.clear();
        for (i = 0; i < n; i++) {
            while (!vv.empty() && (vv.back().second > in[i].second)) vv.pop_back();
            vv.pb(in[i]);
        }
        for (i = 0; i < vv.size(); i++) {
            in[i] = vv[i];
            if (in[i].second > PI) in[i].first -= 2*PI,in[i].second -= 2*PI;
        }
        int k = vv.size();
        sort(in,in+k),vv.clear();
        for (i = 0; i < k; i++) {
            while (!vv.empty() && (vv.back().second > in[i].second)) vv.pop_back();
            vv.pb(in[i]);
        }
        k = vv.size();
        for (i = 0; i < k; i++) vv.pb(mp(vv[i].first+2*PI,vv[i].second+2*PI));
        int j = 0;
        for (i = 0; i < 2*k; i++) {
            while ((j < 2*k) && (vv[j].first < vv[i].second)) j++;
            nn[i][0] = j;
        }
        for (i = 1; (1 << i) < 2*k; i++) {
            for (j = 0; j < 2*k; j++) {
                if (nn[j][i-1] != 2*k) nn[j][i] = nn[nn[j][i-1]][i-1];
                else nn[j][i] = 2*k;
            }
        }
        int logn = i;
        int ans = k;
        for (i = 0; i < k; i++) {
            int u = i,c = 0;
            for (j = logn-1; j >= 0; j--) {
                if (nn[u][j] < i+k) u = nn[u][j],c += (1 << j);
            }
            ans = min(ans,c+1);
        }
        if (ans <= m) l = mm;
        else r = mm;
    }
    printf("%.10lf\n",l);

    return 0;
}