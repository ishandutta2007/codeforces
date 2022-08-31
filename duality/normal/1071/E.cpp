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
#define point pair<double,double>

int t[100000],x[100000],y[100000];
int ccw(point a,point b,point c) {
    return (b.x-a.x)*(c.y-a.y) > (b.y-a.y)*(c.x-a.x);
}
bool comp(point a,point b) {
    if (abs(a.x-b.x) < 1e-9) return a.y < b.y;
    else return a.x < b.x;
}
bool comp2(point a,point b) {
    return (abs(a.x-b.x) < 1e-9) && (abs(a.y-b.y) < 1e-9);
}
vector<point> convexHull(vector<point> &vv) {
    int i;
    vector<point> hull;
    sort(vv.begin(),vv.end(),comp);
    vv.resize(unique(vv.begin(),vv.end(),comp2)-vv.begin());
    for (i = 0; i < vv.size(); i++) {
        while ((hull.size() >= 2) && ccw(hull[hull.size()-2],hull.back(),vv[i])) hull.pop_back();
        hull.pb(vv[i]);
    }
    int l = hull.size();
    for (i = vv.size()-2; i >= 0; i--) {
        while ((hull.size() > l) && ccw(hull[hull.size()-2],hull.back(),vv[i])) hull.pop_back();
        hull.pb(vv[i]);
    }
    return hull;
}
int main() {
    int i;
    int n,w,h,a,b;
    scanf("%d %d %d %d %d",&n,&w,&h,&a,&b);
    for (i = 0; i < n; i++) scanf("%d %d %d",&t[i],&x[i],&y[i]);

    int j;
    double l = 0,r = 1001;
    while (abs(l-r) > 1e-9) {
        double m = (l+r) / 2;

        point p1,p2;
        p1 = p2 = mp(a,b);
        for (i = 0; i < n; i++) {
            int tt = (i == 0) ? t[i]:t[i]-t[i-1];
            if (tt == 0) {
                double mm = (double) (y[i]-h)/y[i],bb = (double) h*x[i]/y[i];
                if ((abs(p1.x-p2.x) < 1e-9) && (abs(p1.y-p2.y) < 1e-9)) {
                    if (abs(mm*p1.x+bb-p1.y) > 1e-9) break;
                }
                else if (!((abs(mm*p1.x+bb-p1.y) < 1e-9) && (abs(mm*p2.x+bb-p2.y) < 1e-9))) {
                    double mm2 = (p1.y-p2.y)/(p1.x-p2.x),bb2 = p1.y-mm2*p1.x;
                    if (abs(mm-mm2) < 1e-9) break;
                    else {
                        double a2 = (bb2-bb)/(mm-mm2);
                        double b2 = mm*a2+bb;
                        if ((a2 < min(p1.x,p2.x)-1e-9) || (a2 > max(p1.x,p2.x)+1e-9)) break;
                        else p1 = p2 = mp(a2,b2);
                    }
                }
            }
            else {
                vector<point> vv;
                vv.pb(mp(p1.x-m*tt,p1.y-m*tt));
                vv.pb(mp(p1.x-m*tt,p1.y+m*tt));
                vv.pb(mp(p1.x+m*tt,p1.y-m*tt));
                vv.pb(mp(p1.x+m*tt,p1.y+m*tt));
                vv.pb(mp(p2.x-m*tt,p2.y-m*tt));
                vv.pb(mp(p2.x-m*tt,p2.y+m*tt));
                vv.pb(mp(p2.x+m*tt,p2.y-m*tt));
                vv.pb(mp(p2.x+m*tt,p2.y+m*tt));
                vv = convexHull(vv);
                double mm = (double) (y[i]-h)/y[i],bb = (double) h*x[i]/y[i];
                point q1,q2;
                q1 = q2 = mp(1e99,1e99);
                for (j = 1; j < vv.size(); j++) {
                    if (abs(vv[j-1].x-vv[j].x) < 1e-9) {
                        double b2 = mm*vv[j].x+bb;
                        if ((b2 > min(vv[j-1].y,vv[j].y)-1e-9) && (b2 < max(vv[j-1].y,vv[j].y)+1e-9)) {
                            point q = mp(vv[j].x,b2);
                            if (q1 == mp(1e99,1e99)) q1 = q;
                            else if ((abs(q.x-q1.x) > 1e-9) || (abs(q.y-q1.y) > 1e-9)) q2 = q;
                        }
                    }
                    else {
                        double mm2 = (vv[j-1].y-vv[j].y)/(vv[j-1].x-vv[j].x),bb2 = vv[j].y-mm2*vv[j].x;
                        if (abs(mm-mm2) > 1e-9) {
                            double a2 = (bb2-bb)/(mm-mm2);
                            double b2 = mm*a2+bb;
                            if ((a2 > min(vv[j-1].x,vv[j].x)-1e-9) && (a2 < max(vv[j-1].x,vv[j].x)+1e-9)) {
                                point q = mp(a2,b2);
                                if (q1 == mp(1e99,1e99)) q1 = q;
                                else if ((abs(q.x-q1.x) > 1e-9) || (abs(q.y-q1.y) > 1e-9)) q2 = q;
                            }
                        }
                    }
                }
                if (q2 == mp(1e99,1e99)) {
                    if ((q1.x > -1e-9) && (q1.x < w+1e-9) && (q1.y > -1e-9) && (q1.y < w+1e-9)) p1 = p2 = q1;
                    else break;
                }
                else {
                    vv.clear();
                    vv.pb(mp(0,0)),vv.pb(mp(w,0)),vv.pb(mp(w,w)),vv.pb(mp(0,w)),vv.pb(mp(0,0));
                    for (j = 1; j < vv.size(); j++) {
                        if (abs(vv[j-1].x-vv[j].x) < 1e-9) {
                            double b2 = mm*vv[j].x+bb;
                            if ((b2 > min(vv[j-1].y,vv[j].y)-1e-9) && (b2 < max(vv[j-1].y,vv[j].y)+1e-9)) {
                                point q = mp(vv[j].x,b2);
                                if (q1.x > q2.x) swap(q1,q2);
                                if (j == 2) {
                                    if (q.x < q2.x) q2 = mp(q.x,mm*q.x+bb);
                                }
                                else {
                                    if (q.x > q1.x) q1 = mp(q.x,mm*q.x+bb);
                                }
                                if (q1.x > q2.x+1e-9) break;
                            }
                        }
                        else {
                            double mm2 = (vv[j-1].y-vv[j].y)/(vv[j-1].x-vv[j].x),bb2 = vv[j].y-mm2*vv[j].x;
                            if (abs(mm-mm2) > 1e-9) {
                                double a2 = (bb2-bb)/(mm-mm2);
                                double b2 = mm*a2+bb;
                                if ((a2 > min(vv[j-1].x,vv[j].x)-1e-9) && (a2 < max(vv[j-1].x,vv[j].x)+1e-9)) {
                                    point q = mp(a2,b2);
                                    if (q1.y > q2.y) swap(q1,q2);
                                    if (j == 1) {
                                        if (q.y > q1.y) q1 = mp((q.y-bb)/mm,q.y);
                                    }
                                    else {
                                        if (q.y < q2.y) q2 = mp((q.y-bb)/mm,q.y);
                                    }
                                    if (q1.y > q2.y+1e-9) break;
                                }
                            }
                        }
                    }
                    if (j < vv.size()) break;
                    else p1 = q1,p2 = q2;
                }
            }
        }
        if (i == n) r = m;
        else l = m;
    }
    if (l > 1000) printf("-1\n");
    else printf("%.10lf\n",l);

    return 0;
}