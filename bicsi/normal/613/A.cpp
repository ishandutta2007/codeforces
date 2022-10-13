#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;


double pDistance(int x, int y, int x1, int y1, int x2, int y2) {

  double A = x - x1;
  double B = y - y1;
  double C = x2 - x1;
  double D = y2 - y1;

  double dot = A * C + B * D;
  double len_sq = C * C + D * D;
  double param = -1;
  if (len_sq != 0) //in case of 0 length line
      param = dot / len_sq;

  double xx, yy;

  if (param < 0) {
    xx = x1;
    yy = y1;
  }
  else if (param > 1) {
    xx = x2;
    yy = y2;
  }
  else {
    xx = x1 + param * C;
    yy = y1 + param * D;
  }

  double dx = x - xx;
  double dy = y - yy;
  return dx * dx + dy * dy;
}

int det(int x, int y, int x1, int y1, int x2, int y2) {
    x1 -= x;
    y1 -= y;
    x2 -= x;
    y2 -= y;

    long long xxx = 1LL * x1 * y2 - 1LL * x2 * y1;
    if(xxx == 0) return 0;
    if(xxx > 0) return 1;
    return -1;
}

double dist(int x1, int y1, int x2, int y2) {
    x1 -= x2;
    y1 -= y2;

    return 1LL * x1 * x1 + 1LL * y1 * y1;
}

int X[500000], Y[500000];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, xi, yi;
    cin >> n >> xi >> yi;

    double dmin = 1e18, dmax = 0;

    int dos;
    for(int i=1; i<=n; i++) {
        cin >> X[i] >> Y[i];
        dmax = max(dmax, dist(xi, yi, X[i], Y[i]));
    }




    X[0] = X[n]; Y[0] = Y[n];

    int cnt = 0;

    int xm = 3918721, ym = 13928713;

    for(int i=1; i<=n; i++) {
        Pair A = {X[i-1], Y[i-1]};
        Pair B = {X[i], Y[i]};

        dmin = min(dmin, pDistance(xi, yi, X[i-1], Y[i-1], X[i], Y[i]));


//        if(xi == B.first) continue;
        if(A.first > B.first) swap(A, B);

        if(A.first > xi || B.first < xi) continue;


        int d = det(xi, yi, A.first, A.second, B.first, B.second);
        if(d == 0) dmin = 0;

        if(d > 0) cnt += 1;

    }

    if(cnt % 2 == 1) dmin = 0;

    double PI = 4.0 * atan(1.0);
    //cerr << PI << '\n';
    cout << fixed << setprecision(20) << PI * (dmax - dmin);

    cerr << '\n' << dmax << " " << dmin;

    return 0;
}