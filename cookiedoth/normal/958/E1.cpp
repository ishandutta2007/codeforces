#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#define ll long long
#define mp make_pair
#define MOD 1000000007

using namespace std;

struct vect {
    ll x, y;
    vect(ll _x, ll _y): x(_x), y(_y) {}
    vect(): x(0), y(0) {}
};

vect make_point(ll x, ll y) {
    vect res;
    res.x = x;
    res.y = y;
    return res;
}

vect make_vector(vect p1, vect p2) {
    vect res;
    res.x = p2.x - p1.x;
    res.y = p2.y - p1.y;
    return res;
}

ll p_scal(vect v1, vect v2) {
    return v1.x*v2.x + v1.y*v2.y;
}

ll p_vect(vect v1, vect v2) {
    return v1.x*v2.y - v1.y*v2.x;
}

double dist_to_sun(vect p0, vect p1, vect p2) {
    if (p_scal(make_vector(p1, p2), make_vector(p1, p0)) < 0) {
        ll dist = p_scal(make_vector(p0, p1), make_vector(p0, p1));
        return sqrt((double)dist);
    }
    else {
        ll S = abs(p_vect(make_vector(p0, p1), make_vector(p0, p2)));
        ll dist = p_scal(make_vector(p1, p2), make_vector(p1, p2));
        return (double)S / sqrt((double)dist);
    }
}

bool on_sun(vect p0, vect p1, vect p2) {
    if ((p_scal(make_vector(p1, p0), make_vector(p1, p2)) >= 0) && (p_vect(make_vector(p1, p0), make_vector(p1, p2)) == 0))
        return 1;
    else
        return 0;
}

double dist_to_segment(vect p0, vect p1, vect p2) {
    return max(dist_to_sun(p0, p1, p2), dist_to_sun(p0, p2, p1));
}

bool half_plane(vect p0, vect p1, vect p2, vect p3) {
    ll s1 = p_vect(make_vector(p0, p1), make_vector(p0, p2));
    ll s2 = p_vect(make_vector(p0, p1), make_vector(p0, p3));
    if (((s1 > 0) && (s2 > 0)) || ((s1 < 0) && (s2 < 0)))
        return 1;
    else
        return 0;
}

bool segments(vect p0, vect p1, vect p2, vect p3) {
    vect v1 = make_vector(p0, p1), v2 = make_vector(p2, p3);
    if (p_vect(v1, v2) == 0) {
        if (p_vect(make_vector(p2, p0), make_vector(p2, p1)) != 0) {
            return 0;
        }
        else {
            bool b = 0;
            if (p_scal(make_vector(p0, p2), make_vector(p0, p3)) <= 0)
                b = 1;
            if (p_scal(make_vector(p1, p2), make_vector(p1, p3)) <= 0)
                b = 1;
            if (p_scal(make_vector(p2, p0), make_vector(p2, p1)) <= 0)
                b = 1;
            if (p_scal(make_vector(p3, p0), make_vector(p3, p1)) <= 0)
                b = 1;
            if (b == 1)
                return 1;
            else
                return 0;
        }
    }
    else {
        if ((!half_plane(p0, p1, p2, p3)) && (!half_plane(p2, p3, p0, p1)))
            return 1;
        else
            return 0;
    }
}

const int mx = 10;
int n, m;
bool t[mx * mx][mx * mx];
vector<vect> a, b;

int main()
{
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].x >> b[i].y;
    }
    if (n != m) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) {
                    int t1 = n * i + j;
                    int t2 = n * x + y;
                    if (segments(a[i], b[j], a[x], b[y]))
                        t[t1][t2] = 1;
                    else
                        t[t1][t2] = 0;
                }
            }
        }
    }
    vector<int> q;
    for (int i = 0; i < n; ++i) {
        q.push_back(i);
    }
    while (true) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = (i * n + q[i]);
        }
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (t[v[i]][v[j]] == 1) {
                    ok = 0;
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        if (ok == 1) {
            cout << "Yes" << endl;
            return 0;
        }
        if (!next_permutation(q.begin(), q.end()))
            break;
    }
    cout << "No" << endl;
    return 0;
}