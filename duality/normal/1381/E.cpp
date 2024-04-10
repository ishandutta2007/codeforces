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

pii p[100000],queries[100000];
vpii L,R;
vi Y;
pair<double,double> query(int y) {
    double a,b;
    int p = upper_bound(L.begin(),L.end(),mp(y,(int) 1e9))-L.begin();
    if (p == L.size()) a = L.back().y;
    else a = ((double) L[p-1].y*(L[p].x-y)+(double) L[p].y*(y-L[p-1].x))/(L[p].x-L[p-1].x);
    p = upper_bound(R.begin(),R.end(),mp(y,(int) 1e9))-R.begin();
    if (p == R.size()) b = R.back().y;
    else b = ((double) R[p-1].y*(R[p].x-y)+(double) R[p].y*(y-R[p-1].x))/(R[p].x-R[p-1].x);
    if (a > b) swap(a,b);
    return mp(a,b);
}
double query2(pair<double,double> &l,pair<double,double> &r,double x,double dy) {
    double s = 0,e = dy;
    if (abs(l.first-r.first) > 1e-9) {
        double m = dy/(r.first-l.first),b = -m*l.first,y = m*x+b;
        if (r.first > l.first) e = min(e,y);
        else s = max(s,y);
    }
    if (abs(l.second-r.second) > 1e-9) {
        double m = dy/(r.second-l.second),b = -m*l.second,y = m*x+b;
        if (r.second < l.second) e = min(e,y);
        else s = max(s,y);
    }
    double m1 = (l.first-r.first)/dy,b1 = x-l.first;
    double m2 = (r.second-l.second)/dy,b2 = l.second-x;
    double u1 = m1*s+b1,v1 = m2*s+b2;
    double u2 = m1*e+b1,v2 = m2*e+b2;
    if ((abs(u1-v1) > 1e-9) && (abs(u2-v2) > 1e-9) && ((u1 > v1) != (u2 > v2))) {
        double x = (b2-b1)/(m1-m2),y = m1*x+b1;
        return 0.5*((y+min(u1,v1))*(x-s)+(y+min(u2,v2))*(e-x));
    }
    else return 0.5*(min(u1,v1)+min(u2,v2))*(e-s);
}
bool comp2(double a,double b) {
    return abs(a-b) < 1e-9;
}
struct event { double x,a,b,c; };
vector<event> events;
bool comp(event a,event b) {
    return a.x < b.x;
}
double ans[100000];
int main() {
    int i;
    int n,q;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d %d",&p[i].x,&p[i].y),Y.pb(p[i].y);
    for (i = 0; i < q; i++) scanf("%d",&queries[i].first),queries[i].second = i;
    sort(queries,queries+q);

    int j,u = 0,v = 0;
    for (i = 0; i < n; i++) {
        if (p[i].y < p[u].y) u = i;
        if (p[i].y > p[v].y) v = i;
    }
    i = u,L.pb(mp(p[i].y,p[i].x));
    while (i != v) i = (i+1) % n,L.pb(mp(p[i].y,p[i].x));
    i = u,R.pb(mp(p[i].y,p[i].x));
    while (i != v) i = (i+n-1) % n,R.pb(mp(p[i].y,p[i].x));
    sort(Y.begin(),Y.end());
    Y.resize(unique(Y.begin(),Y.end())-Y.begin());
    for (i = 1; i < Y.size(); i++) {
        pair<double,double> l = query(Y[i-1]),r = query(Y[i]);
        vector<double> vv;
        vv.pb(l.first),vv.pb(l.second),vv.pb(r.first),vv.pb(r.second);
        vv.pb((l.first+l.second)/2),vv.pb((r.first+r.second)/2);
        sort(vv.begin(),vv.end());
        vv.resize(unique(vv.begin(),vv.end(),comp2)-vv.begin());
        double a = 0,b = 0,c = 0;
        for (j = 1; j < vv.size(); j++) {
            double ll = query2(l,r,vv[j-1],Y[i]-Y[i-1]);
            double mm = query2(l,r,(vv[j-1]+vv[j])/2,Y[i]-Y[i-1]);
            double rr = query2(l,r,vv[j],Y[i]-Y[i-1]);
            double dx = vv[j]-vv[j-1];
            double a2 = 2*(ll-2*mm+rr)/(dx*dx);
            double b2 = (rr-a2*vv[j]*vv[j]-ll+a2*vv[j-1]*vv[j-1])/dx;
            double c2 = rr-a2*vv[j]*vv[j]-b2*vv[j];
            events.pb((event){vv[j-1],a2-a,b2-b,c2-c});
            a = a2,b = b2,c = c2;
        }
        events.pb((event){vv.back(),-a,-b,-c});
    }
    j = 0;
    double a = 0,b = 0,c = 0;
    sort(events.begin(),events.end(),comp);
    for (i = 0; i < q; i++) {
        while ((j < events.size()) && (events[j].x < queries[i].first))
            a += events[j].a,b += events[j].b,c += events[j].c,j++;
        ans[queries[i].second] = a*queries[i].first*queries[i].first+b*queries[i].first+c;
    }
    LLI A = 0;
    for (i = 0; i < n; i++) {
        A += (LLI) p[(i+1) % n].x*p[i].y;
        A -= (LLI) p[i].x*p[(i+1) % n].y;
    }
    A = abs(A);
    for (i = 0; i < q; i++) printf("%.9lf\n",(double) A/2-ans[i]);

    return 0;
}