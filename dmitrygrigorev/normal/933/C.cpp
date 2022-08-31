#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
double EPS = 0.0000001;
vector<pair<double, double> > ms;
vector<pair<double, double> > g;
double Xx, Yy;
int V;
int Ch(double r, double a, double b, double c, double xa, double ya){
    double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
    if (c*c > r*r*(a*a+b*b)+EPS)
        return 0;
    else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
        Xx = x0;
        Yy = y0;
        return 1;
    }
    else {
        double d = r*r - c*c/(a*a+b*b);
        double mult = sqrt (d / (a*a+b*b));
        double ax,ay,bx,by;
        ax = x0 + b * mult+xa;
        bx = x0 - b * mult+xa;
        ay = y0 - a * mult+ya;
        by = y0 + a * mult+ya;
        g.push_back(make_pair(ax, ay));
        g.push_back(make_pair(bx, by));
        return 2;
    }
}
bool check(int xa, int ya, int ra, int xb, int yb, int rb){
    if (xa==xb && ya==yb) return false;
    xb -= xa;
    yb -= ya;
    double A = -2*xb;
    double B = -2*yb;
    double C = xb*xb + yb*yb + ra*ra - rb*rb;
    int res = Ch(ra, A, B, C, xa, ya);
    if (res == 1){
        V++;
        Xx += (double) xa;
        Yy += (double) ya;
        ms.push_back(make_pair(Xx, Yy));
        g.push_back(make_pair(Xx, Yy));
    }
    if (res == 2) return true;
    return false;
}
bool X(int xa, int ya, int ra, int xb, int yb, int rb){
    if (xa == xb&&ya==yb&&ra==rb) return true;
    return false;
}
void solt(int xa, int ya, int ra, int xb, int yb, int rb){
    if (X(xa, ya, ra, xb, yb, rb)){
        cout << 2 << endl;
        exit(0);
    }
    if (check(xa, ya, ra, xb, yb, rb)) cout << 4 << endl;
    else cout << 3 << endl;
    exit(0);
}
bool rav(pair<double, double> a, pair<double, double> b){
    if (abs(a.first - b.first) < EPS && abs(a.second - b.second) < EPS) return true;
    return false;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 1){
        int x, y, r;
        cin >> x >> y >> r;
        cout << 2 << endl;
        return 0;
    }
    if (n==2){
        int xa, ya, ra;
        int xb, yb, rb;
        cin >> xa >> ya >> ra;
        cin >> xb >> yb >> rb;
        solt(xa, ya, ra, xb, yb, rb);
    }
    if (n==3){
        V = 0;
        int xa, ya, ra;
        int xb, yb, rb;
        int xc, yc, rc;
        cin >> xa >> ya >> ra;
        cin >> xb >> yb >> rb;
        cin >> xc >> yc >> rc;
        int Z = 0;
        if (X(xa, ya, ra, xb, yb, rb)){
            solt(xa, ya, ra, xc, yc, rc);
        }
        if (X(xa, ya, ra, xc, yc, rc)){
            solt(xa, ya, ra, xb, yb, rb);
        }
        if (X(xc, yc, rc, xb, yb, rb)){
            solt(xa, ya, ra, xc, yc, rc);
        }
        Z += check(xa, ya, ra, xb, yb, rb);
        Z += check(xc, yc, rc, xb, yb, rb);
        Z += check(xa, ya, ra, xc, yc, rc);
        int M = 0;
        sort(g.begin(), g.end());
        sort(ms.begin(), ms.end());
       // for (int i=0; i < g.size(); i++) cout << g[i].first << " " << g[i].second << endl;
        int huj = 1;
        for (int i=1; i < g.size(); i++){
            if (rav(g[i], g[i-1])) huj++;
            else{
                if (huj==3) M++;
                huj = 1;
            }
        }
       // cout << V << " " << Z << endl;
        if (huj==3) M++;
        if (V==2 && Z==1){
            cout << 6 << endl;
            return 0;
        }
        if (V==1 && Z==2){
            cout << 7-M << endl;
            return 0;
        }
        if (V==3 && !rav(ms[0], ms.back())){
            cout << 5 << endl;
            return 0;
        }
        if (Z==3) cout << 8-M << endl;
        else cout << 4+Z << endl;
    }
}