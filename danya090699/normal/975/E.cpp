#include <bits/stdc++.h>

using namespace std;

#define double long double
#define int long long

struct pt{
    double x, y;
};

double dist(pt a, pt b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double s(pt a, pt b, pt c){
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
}

const double pi = atan2(0, -1);

double toDegrees(double a){
    return a*180/pi;
}

int n, q;
pt a[10010];
pt c;
double di[10010];
double phi[10010];

main()
{
    //freopen("input.txt", "r", stdin);
    cout << fixed << setprecision(12);
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    double S = 0;
    for(int i = 0; i < n; i++){
        int next = (i+1 == n) ? 0 : i + 1;
        S += s(a[i], a[next], {0, 0});
    }
    for(int i = 2; i < n; i++){
        c.x += (a[i-1].x + a[i].x + a[0].x) / 3 * abs(s(a[0], a[i-1], a[i]));
        c.y += (a[i-1].y + a[i].y + a[0].y) / 3 * abs(s(a[0], a[i-1], a[i]));
    }
    c.x /= S;
    c.y /= S;
    for(int i = 0; i < n; i++){
        di[i] = dist(c, a[i]);
        phi[i] = atan2(a[i].y - c.y, a[i].x - c.x);
    }
    int i1 = 0, i2 = 1;
    //pt p1 = a[0], p2 = a[1];
    double angle=0;
    for(int i = 0; i < q; i++){
        int type;
        cin >> type;
        if(type == 1){
            int f, t;
            cin >> f >> t;
            f--, t--;
            if(i1 == f) swap(i1, i2);
            i2 = t;

            double angle1=phi[i1]+angle;
            if(angle1>pi) angle1-=2*pi;
            if(angle1<-pi) angle1+=2*pi;

            pt nc;
            nc.x=c.x+cos(angle1)*di[i1];
            nc.y=c.y+sin(angle1)*di[i1]-di[i1];
            c=nc;

            angle += (pi/2-angle1);
            while(angle>pi) angle-=2*pi;
            while(angle<-pi) angle+=2*pi;
        }
        else{
            int v;
            cin >> v;
            v--;
            double angle1 = phi[v]+angle;
            if(angle1>pi) angle1-=2*pi;
            if(angle1<-pi) angle1+=2*pi;

            pt res;
            res.x = c.x + cos(angle1)*di[v];
            res.y = c.y + sin(angle1)*di[v];
            cout << res.x << ' ' << res.y << endl;
        }
    }
}