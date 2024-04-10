#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Point {
    int x, y;
} p[5];
int dis(int a, int b) {
    return abs(p[a].x - p[b].x) + abs(p[a].y - p[b].y);
}
int cmp(const Point &a, const Point &b) {
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
struct Line {
    int a, b, c, d;
};
vector<Line> v;
signed main()
{
//    for(int i = 1; i <= 3; i++) {
//        cin >> x[i] >> y[i];
//    }
//    int ans = 1ll << 60;
//    for(int i = 1; i <= 3; i++) {
//        for(int j = 1; j <= 3; j++) if(i != j) {
//            int k = 1 + 2 + 3 - i - j;
//            int ndis = dis(i, j) + dis(j, k);
//            if(ndis < ans) {
//                ans = ndis;
//                v.clear();
//                if(x[i] != x[j]) v.push_back({x[i], y[i], x[j], y[i]});
//                if(y[i] != y[j]) v.push_back({x[j], y[i], x[j], y[j]});
//                if(x[k] != x[j]) v.push_back({x[j], y[j], x[k], y[j]});
//                if(y[k] != y[j]) v.push_back({x[k], y[j], x[k], y[k]});
//            }
//        }
//    }
//    cout << v.size() << endl;
//    for(auto x : v) {
//        cout << x.a << " " << x.b << " " << x.c << " " << x.d << endl;
//    }
    int ans = 1ll << 60;
    for(int i = 1; i <= 3; i++) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p + 1, p + 1 + 3, cmp);
    if(p[1].y > p[3].y) swap(p[1], p[3]);
    if(p[1].y <= p[2].y && p[2].y <= p[3].y) {
        v.push_back({p[1].x, p[1].y, p[2].x, p[1].y});
        v.push_back({p[2].x, p[1].y, p[2].x, p[2].y});
        v.push_back({p[2].x, p[2].y, p[3].x, p[2].y});
        v.push_back({p[3].x, p[2].y, p[3].x, p[3].y});
    } else {
        if(p[2].y < p[3].y) {
            v.push_back({p[1].x, p[1].y, p[3].x, p[1].y});
            v.push_back({p[3].x, p[1].y, p[3].x, p[3].y});
            v.push_back({p[2].x, p[2].y, p[2].x, p[1].y});
        } else {
            v.push_back({p[1].x, p[1].y, p[1].x, p[3].y});
            v.push_back({p[1].x, p[3].y, p[3].x, p[3].y});
            v.push_back({p[2].x, p[2].y, p[2].x, p[3].y});
        }
    }
    cout << v.size() << endl;
    for(auto x : v) {
        cout << x.a << " " << x.b << " " << x.c << " " << x.d << endl;
    }
    return 0;
}