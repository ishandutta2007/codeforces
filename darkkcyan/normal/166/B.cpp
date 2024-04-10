#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    ll x, y;
    bool side;
};

ll cross(const Point& u, const Point& v) {
    return u.x * v.y - u.y * v.x;
}

Point operator-(const Point& u, const Point& v) {
    return {u.x - v.x, u.y - v.y, 0};
}

vector<Point> one_side_hull(const vector<Point>& pt) {
    vector<Point> ans;
    for (auto p: pt) {
        while (ans.size() > 1 and cross(ans.back() - ans.rbegin()[1], p - ans.rbegin()[1]) > 0) {
            ans.pop_back();
        }
        ans.push_back(p);
    }
    return ans;
}

vector<Point> convex_hull(vector<Point> a) {
    sort(a.begin(), a.end(), [](const Point& u, const Point& v) {
            return u.x == v.x ? u.y < v.y : u.x < v.x;
            });
    auto upper = one_side_hull(a);
    reverse(a.begin(), a.end());
    auto lower = one_side_hull(a);
    upper.pop_back();
    lower.pop_back();
    upper.insert(upper.end(), lower.begin(), lower.end());
    return upper;
}

int main() {
    vector<Point> a, b;
    int n, m;
    cin >> n;
    a.resize(n);
    for (auto& it: a) {
        cin >> it.x >> it.y;
        it.side = 0;
    }
    cin >> m;
    b.resize(m);
    for (auto& it: b) {
        cin >> it.x >> it.y;
        it.side = 1;
    }
    a.insert(a.end(), b.begin(), b.end());
    
    for (auto it: convex_hull(a)) {
        clog << it.x << ' ' << it.y << endl;
        if (it.side) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    
    return 0;
}