#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> Point;
#define x first
#define y second

Point toPolar(Point P) {
    return {sqrt(P.x*P.x + P.y*P.y), atan2(P.y, P.x)};
}
Point toCart(Point P) {
    return {P.first * cos(P.second), P.first * sin(P.second)};
}

int main() {
    double x1, y1, vmax, t;
    Point D, V, U;

    cin>>x1>>y1>>D.x>>D.y;
    D.x -= x1; D.y -= y1;

    cin>>vmax>>t;
    cin>>V.x>>V.y>>U.x>>U.y;


    D = toPolar(D); V = toPolar(V); U = toPolar(U);
    V.y -= D.y; U.y -= D.y; D.y = 0;
    D = toCart(D); V = toCart(V); U = toCart(U);

    double r1x = sqrt(vmax*vmax - V.y*V.y) + V.x;
    double r2x = sqrt(vmax*vmax - U.y*U.y) + U.x;

    cout<<fixed<<setprecision(18);
    if(r1x * t > D.x) cout<<D.x / r1x;
    else {
        double l = t, r = 1e18;
        for(int it=1; it<=500; it++) {
            double m = (l + r) / 2;

            Point R(V.x * t + U.x *(m - t), V.y * t + U.y * (m - t));

            Point Need(R.y / m, (D.x - R.x) / m);
            if(Need.x*Need.x + Need.y*Need.y <= vmax*vmax) r = m;
            else l = m;

        }

        cout<<(l+r)/2;
    }


    return 0;
}