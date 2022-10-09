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

const int max_val = (int)1e8 + 10;
struct point {
    int x, y, z, id;
    bool removed;

    llong xy_key() {
        return (1ll * x) << 32ll | y;
    }
};

#define maxn 50101
int n;
point a[maxn];
map<llong, vector<point*>> group;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].x += max_val;
        a[i].y += max_val;
        a[i].z += max_val;
        a[i].id = i + 1;
        a[i].removed = false;
    }

    rep(i, n) {
        group[a[i].xy_key()].push_back(a + i);
    }

    auto do_remove = [](vector<point*>& container) {
        sort(container.begin(), container.end(), [](point* u, point* v) {
                if (u->x == v->x) {
                    if (u->y == v->y) return u->z < v->z;
                    return u->y < v->y;
                }
                return u->x < v->x;
        });
        while (len(container) > 1) {
            auto u = container.back(); container.pop_back();
            auto v = container.back(); container.pop_back();
            cout << u->id << ' ' << v->id << '\n';
            u->removed = true;
            v->removed = true;
        }
    };

    for (auto& [key, val]: group) {
        do_remove(val);
    }

    group.clear();
    rep(i, n) {
        if (!a[i].removed)
            group[a[i].x].push_back(a + i);
    }

    for (auto& [key, val]: group) {
        do_remove(val);
    }

    vector<point*> rest;
    rep(i, n) if (!a[i].removed)
        rest.push_back(a + i);
    do_remove(rest);

    return 0;
}