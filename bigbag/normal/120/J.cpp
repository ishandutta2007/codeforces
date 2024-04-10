#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

const int MAX_N = 1024000, MAX_X = 1000000000;
const bool READ_Z = false;

struct point {
    int x, y, z, id;

    point(): x(0), y(0), z(0), id(0) {
    }

    point(int x, int y, int z): x(x), y(y), z(z), id(-1) {
    }

    point operator - (const point &p) const {
        return {x - p.x, y - p.y, z - p.z};
    }

    bool operator < (const point &p) const {
        return x < p.x || (x == p.x && y < p.y) ||
        (x == p.x && y == p.y && z < p.z);
    }
};

bool in_range(int l, int r, int x) {
    return l <= x && x <= r;
}

void error(std::string message) {
    std::cout << message << std::endl;
    exit(0);
}

std::string line_error(int line, std::string error) {
    std::stringstream s;
    s << "Line " << line << ": " << error;
    return s.str();
}

std::string range_error(int l, int r, int x, std::string variable, int line) {
    std::stringstream error;
    error << "integer " << variable << " violates range constraint !(" << l << " <= " << x << " <= " << r << ")";
    return line_error(line, error.str());
}

std::vector<point> read_data() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int line = 1, n;
    if (!(std::cin >> n)) {
        error(line_error(line, "expected one integer n"));
    }
    if (!in_range(2, MAX_N, n)) {
        error(range_error(2, MAX_N, n, "n", line));
    }
    std::vector<point> p(n);
    for (int i = 0; i < n; ++i) {
        line += 1;
        if (!(std::cin >> p[i].x)) {
            error(line_error(line, "expected integer p[i].x"));
        }
        if (!(std::cin >> p[i].y)) {
            error(line_error(line, "expected integer p[i].y"));
        }
        if (READ_Z) {
            if (!(std::cin >> p[i].z)) {
                error(line_error(line, "expected integer p[i].z"));
            }
        }
        if (!in_range(-MAX_X, MAX_X, p[i].x)) {
            error(range_error(-MAX_X, MAX_X, p[i].x, "p[i].x", line));
        }
        if (!in_range(-MAX_X, MAX_X, p[i].y)) {
            error(range_error(-MAX_X, MAX_X, p[i].y, "p[i].y", line));
        }
        if (!in_range(-MAX_X, MAX_X, p[i].z)) {
            error(range_error(-MAX_X, MAX_X, p[i].z, "p[i].z", line));
        }
        p[i].id = i;
    }
    return p;
}


long double dist(const point &p) {
    return sqrt(1LL * p.x * p.x + 1LL * p.y * p.y +
                1LL * p.z * p.z);
}

long double dist(const point &a, const point &b) {
    return dist(a - b);
}

std::vector<point> p, tmp;
long double ans;
int a_id, b_id;

void upd(const point &a, const point &b) {
    long double d = dist(a, b);
    if (d < ans) {
        ans = d;
        a_id = a.id;
        b_id = b.id;
    }
}

void solve(int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    const int X = p[mid].x;
    solve(l, mid);
    solve(mid + 1, r);
    auto cmp = [](const point &a, const point &b) { return a.z < b.z;
    };
    std::multiset<point, decltype(cmp)> q(cmp);
    int p1 = mid + 1, p2 = mid + 1;
    const long double kAns = ans;
    for (int i = l; i <= mid; ++i) {
        if (abs(p[i].x - X) <= ans) {
            while (p2 <= r && p[p2].y <= p[i].y + ans) {
                if (abs(p[p2].x - X) <= kAns) {
                    q.insert(p[p2]);
                }
                ++p2;
            }
            while (p1 < p2 && p[p1].y < p[i].y - ans) {
                if (abs(p[p1].x - X) <= kAns) {
                    q.erase(q.find(p[p1]));
                }
                ++p1;
            }
            auto it = q.lower_bound(point(0, 0, p[i].z - ans));
            while (it != q.end() && it->z <= p[i].z + ans) {
                upd(p[i], *it);
                ++it;
            }
        }
    }
    std::merge(p.begin() + l, p.begin() + mid + 1, p.begin() + mid + 1, p.begin() + r + 1, tmp.begin(),
               [](const point &a, const point &b) { return a.y < b.y;
               });
    std::copy(tmp.begin(), tmp.begin() + r - l + 1, p.begin() + l);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    p = read_data();
    const auto cp = p;
    for (int i = 0; i < p.size(); ++i) {
        p[i].x = abs(p[i].x);
        p[i].y = abs(p[i].y);
    }
    tmp.resize(p.size());
    std::sort(p.begin(), p.end());
    ans = 1e18;
    solve(0, p.size() - 1);
    int tp1 = 1, tp2 = 1;
    if (cp[a_id].x < 0) {
        tp1 += 1;
    }
    if (cp[a_id].y < 0) {
        tp1 += 2;
    }
    if (cp[b_id].x > 0) {
        tp2 += 1;
    }
    if (cp[b_id].y > 0) {
        tp2 += 2;
    }
    std::cout << a_id + 1 << " " << tp1 << " " << b_id + 1 << " " << tp2 << std::endl;
    return 0;
}