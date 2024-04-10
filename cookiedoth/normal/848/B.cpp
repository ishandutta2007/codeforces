#include <bits/stdc++.h>
#define ll long long
#define elif else if
#define MOD 1000000007

using namespace std;

struct point {
    int g, p, t;
    pair<int, int> coords;
};

bool operator < (point a, point b) {
    return a.p < b.p;
}

const int mx = 300000;
int n, w, h;
vector<int> min_x[mx], min_y[mx];
point a[mx], ans[mx];

bool cmp (int x, int y) {
    return a[x] < a[y];
}

int main()
{
    int g, p, t;
    cin >> n >> w >> h;
    for (int i = 0; i < n; ++i) {
        cin >> g >> p >> t;
        if (g == 1) {
            a[i] = {g, p, t, {p, h}};
            min_x[p - t + mx / 2].push_back(i);
        }
        else {
            a[i] = {g, p, t, {w, p}};
            min_y[p - t + mx / 2].push_back(i);
        }
    }
    for (int i = 0; i < mx; ++i) {
        sort(min_x[i].begin(), min_x[i].end(), cmp);
        sort(min_y[i].begin(), min_y[i].end(), cmp);
        vector<int> vx = min_x[i], vy = min_y[i];
        reverse(vx.begin(), vx.end());
        for (int j = 0; j < vx.size(); ++j) {
            if (j >= vy.size()) {
                ans[vx[j]].coords = a[vx[j - vy.size()]].coords;
            }
            else
                ans[vx[j]].coords = a[vy[j]].coords;
        }
        reverse(vx.begin(), vx.end());
        reverse(vy.begin(), vy.end());
        for (int j = 0; j < vy.size(); ++j) {
            if (j >= vx.size()) {
                ans[vy[j]].coords = a[vy[j - vx.size()]].coords;
            }
            else
                ans[vy[j]].coords = a[vx[j]].coords;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i].coords.first <<  " " << ans[i].coords.second << '\n';
    }
    return 0;
}