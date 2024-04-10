#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

llong ask_area(int a, int b, int c) {
    cout << 1 << ' ' << a << ' ' << b << ' ' << c << endl;
    llong ans; cin >> ans;
    return ans;
}

bool ask_ccw(int org, int a, int b) {
    cout << 2 << ' ' << org << ' ' << a << ' ' << b << endl;
    int ans; cin >> ans;
    return ans > 0;
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int root1 = 1;
    int root2 = 2;
    for (int i = 3; i <= n; ++i) {
        if (ask_ccw(root1, root2, i)) root2 = i;
    }

    vector<pair<llong, int>> areas;
    for (int i = 2; i <= n; ++i) {
        if (i == root2) continue;
        areas.emplace_back(ask_area(root1, root2, i), i);
    }

    sort(areas.begin(), areas.end());

    list<int> points;
    points.push_back(areas.back().yy);
    areas.pop_back();
    for(; areas.size(); areas.pop_back()) {
        int u = areas.back().yy;
        if (ask_ccw(root1, points.front(), u)) points.push_front(u);
        else points.push_back(u);
    }

    points.push_front(root2);
    points.push_back(root1);

    cout << 0 << ' ';
    reverse(points.begin(), points.end());
    for (auto i: points) cout << i << ' ';
    cout << endl;

    return 0;
}