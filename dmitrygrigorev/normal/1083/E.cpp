#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
double INF = 2e18;
struct Line{double k; double b; double l; double r;};
vector<Line> cht;
struct Rect{int x; int y; int a;};
bool cmp(Rect &a, Rect &b){
    return (a.x < b.x);
}
int u = 0, old;
double inter(Line &a, Line &b){
    double x = (b.b - a.b) / (a.k - b.k);
    if (x < -INF) x = -INF;
    if (x > INF) x = INF;
    return x;
}
void add(double k, double b){
    Line nl = {k, b, -INF, INF};
    while (cht.size()){
        double X = inter(nl, cht.back());
        if (X > cht.back().r) cht.pop_back();
        else{
            cht.back().l = X;
            nl.r = X;
            cht.push_back(nl);
            break;
        }
    }
    if (!cht.size()) cht.push_back(nl);
    if (old >= cht.back().l && old <= cht.back().r) u = cht.size() - 1;
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    vector<Rect> v;
    for (int i=0; i < n; i++){
        int x, y, a;
        cin >> x >> y >> a;
        v.push_back({x, y, a});
    }
    sort(v.begin(), v.end(), cmp);
    int ans = max((int) 0, v[0].x*v[0].y - v[0].a);
    cht.push_back({v[0].x, -ans, -INF, INF});
    //cout << ans << endl;
    for (int i = 1; i < n; i++){
        while (cht[u].l > v[i].y) u++;
        int rs = -(cht[u].k * v[i].y + cht[u].b);
        //cout << cht[u].k << " " << cht[u].b << endl;
        rs += v[i].x * v[i].y - v[i].a;
        rs = max(rs, v[i].x * v[i].y - v[i].a);
        rs = max(rs, (int) 0);
      //  cout << rs << endl;
        ans = max(ans, rs);
        old = v[i].y;
        add(v[i].x, -rs);
    }
    cout << ans;
}