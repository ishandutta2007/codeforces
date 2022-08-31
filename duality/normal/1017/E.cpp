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

pii a[100000],b[100000];
int cw(pii a,pii b,pii c) {
    return ((LLI) (b.x-a.x) * (c.y-a.y)) < ((LLI) (b.y-a.y) * (c.x-a.x));
}
vpii ha,hb;
vector<pair<LLI,long double> > A,B;
int eq(pair<LLI,long double> a,pair<LLI,long double> b) {
    return (a.x == b.x) && (abs(a.y-b.y) < 1e-9);
}
int le(pair<LLI,long double> a,pair<LLI,long double> b) {
    return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y-1e-9));
}
int duval(vector<pair<LLI,long double> > &v) {
    int i,j,k;
    int n = v.size(),ans;
    for (i = 0; i < n; i++) v.pb(v[i]);
    i = 0;
    while (i < n) {
        ans = k = i,j = i+1;
        while ((j < v.size()) && !le(v[j],v[k])) {
            if (le(v[k],v[j])) k = i;
            else k++;
            j++;
        }
        while (i <= k) i += j-k;
    }
    return ans;
}
int main() {
    int i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d %d",&a[i].x,&a[i].y);
    for (i = 0; i < m; i++) scanf("%d %d",&b[i].x,&b[i].y);

    sort(a,a+n);
    for (i = 0; i < n; i++) {
        while ((ha.size() >= 2) && !cw(ha[ha.size()-2],ha.back(),a[i])) ha.pop_back();
        ha.pb(a[i]);
    }
    int l = ha.size();
    for (i = n-2; i >= 0; i--) {
        while ((ha.size() > l) && !cw(ha[ha.size()-2],ha.back(),a[i])) ha.pop_back();
        ha.pb(a[i]);
    }
    ha.pop_back();
    sort(b,b+m);
    for (i = 0; i < m; i++) {
        while ((hb.size() >= 2) && !cw(hb[hb.size()-2],hb.back(),b[i])) hb.pop_back();
        hb.pb(b[i]);
    }
    l = hb.size();
    for (i = m-2; i >= 0; i--) {
        while ((hb.size() > l) && !cw(hb[hb.size()-2],hb.back(),b[i])) hb.pop_back();
        hb.pb(b[i]);
    }
    hb.pop_back();
    if (ha.size() != hb.size()) {
        printf("NO\n");
        return 0;
    }

    for (i = 0; i < ha.size(); i++) {
        int j = (i+1) % ha.size();
        int k = (i+2) % ha.size();
        LLI d = (LLI) (ha[i].x-ha[j].x)*(ha[i].x-ha[j].x) + (LLI) (ha[i].y-ha[j].y)*(ha[i].y-ha[j].y);
        LLI d2 = (LLI) (ha[j].x-ha[k].x)*(ha[j].x-ha[k].x) + (LLI) (ha[j].y-ha[k].y)*(ha[j].y-ha[k].y);
        LLI d3 = (LLI) (ha[i].x-ha[k].x)*(ha[i].x-ha[k].x) + (LLI) (ha[i].y-ha[k].y)*(ha[i].y-ha[k].y);
        long double t = (long double) (d+d2-d3)/(2*sqrt(d)*sqrt(d2));
        A.pb(mp(d,t));
    }
    for (i = 0; i < hb.size(); i++) {
        int j = (i+1) % hb.size();
        int k = (i+2) % hb.size();
        LLI d = (LLI) (hb[i].x-hb[j].x)*(hb[i].x-hb[j].x) + (LLI) (hb[i].y-hb[j].y)*(hb[i].y-hb[j].y);
        LLI d2 = (LLI) (hb[j].x-hb[k].x)*(hb[j].x-hb[k].x) + (LLI) (hb[j].y-hb[k].y)*(hb[j].y-hb[k].y);
        LLI d3 = (LLI) (hb[i].x-hb[k].x)*(hb[i].x-hb[k].x) + (LLI) (hb[i].y-hb[k].y)*(hb[i].y-hb[k].y);
        long double t = (long double) (d+d2-d3)/(2*sqrt(d)*sqrt(d2));
        B.pb(mp(d,t));
    }

    int k1 = duval(A);
    int k2 = duval(B);
    for (i = 0; i < ha.size(); i++) {
        if (!eq(A[k1],B[k2])) break;
        k1++,k2++;
    }
    if (i < ha.size()) printf("NO\n");
    else printf("YES\n");

    return 0;
}