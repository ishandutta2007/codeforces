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

pii p[500000];
int quad(pii p) {
    if ((p.x > 0) && (p.y >= 0)) return 0;
    else if ((p.y > 0) && (p.x <= 0)) return 1;
    else if ((p.x < 0) && (p.y <= 0)) return 2;
    else return 3;
}
bool comp(pii a,pii b) {
    if (a == mp(0,0)) return (b == mp(0,0)) ? 0:1;
    else if (b == mp(0,0)) return 0;
    int qa = quad(a),qb = quad(b);
    if (qa != qb) return qa < qb;
    else return (LLI) a.x*b.y > (LLI) a.y*b.x;
}
vector<double> vv[500000];
vector<pair<double,pii> > vvv;
int num[500000];
int main() {
    int i;
    int n,k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) {
        scanf("%d %d",&p[i].x,&p[i].y);
        //p[i].x = rand(),p[i].y = rand();
        //p[i].x = 0,p[i].y = i;
        //if ((i > 0) && ((rand() % 100) == 0)) p[i].x = rand(),p[i].y = rand();
    }
    sort(p,p+n,comp);
    //for(i=0;i<n;i++)cout<<p[i].x<<","<<p[i].y<<endl;

    int j,c = 0;
    for (i = 1; i < n; i++) {
        vv[c].pb(sqrt((LLI) p[i].x*p[i].x+(LLI) p[i].y*p[i].y));
        if ((i == n-1) || comp(p[i],p[i+1])) c++;
    }
    double ans = 0;
    for (i = 0; i < c; i++) sort(vv[i].begin(),vv[i].end(),greater<double>());
    if (k == n) {
        for (i = 0; i < c; i++) {
            for (j = 0; j < vv[i].size(); j++) {
                double d = vv[i][j]-((j == vv[i].size()-1) ? 0:vv[i][j+1]);
                int e = j+1;
                ans += d*e*(k-e);
            }
        }
        printf("%.8lf\n",ans);
        return 0;
    }
    for (i = 0; i < c; i++) {
        printArr(vv[i],vv[i].size());
        for (j = 0; j < vv[i].size(); j++) vvv.pb(mp(vv[i][j]*(k-1-2*j),mp(i,j)));
    }
    sort(vvv.begin(),vvv.end()),reverse(vvv.begin(),vvv.end());
    for (i = 0; i < k; i++) num[vvv[i].second.first]++;
    for (i = 0; i < c; i++) {
        for (j = 0; j < vv[i].size(); j++) {
            double d = vv[i][j]-((j == vv[i].size()-1) ? 0:vv[i][j+1]);
            int e = min(j+1,num[i]);
            ans += d*e*(k-e);
        }
    }
    double sum = 0;
    for (i = 0; i < c; i++) {
        for (j = 0; j < vv[i].size(); j++) {
            double d = vv[i][j]-((j == vv[i].size()-1) ? 0:vv[i][j+1]);
            int e = min(j+1,k);
            sum += (d*e)*(k-e);
        }
    }
    for (i = 0; i < c; i++) {
        if ((n-vv[i].size() <= k/2) && (vv[i].size() >= (k+1)/2)) {
            double sum2 = sum;
            for (j = 0; j < vv[i].size(); j++) {
                double d = vv[i][j]-((j == vv[i].size()-1) ? 0:vv[i][j+1]);
                int e = min(j+1,k);
                sum2 -= (d*e)*(k-e);
                if (j >= (k+1)/2) {
                    e = (k+1)/2;
                    int f = k/2-(n-vv[i].size());
                    if (j >= vv[i].size()-f) e += j-(vv[i].size()-f)+1;
                }
                sum2 += (d*e)*(k-e);
            }
            ans = max(ans,sum2);
        }
    }
    printf("%.8lf\n",ans);

    return 0;
}