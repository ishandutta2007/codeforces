#include <bits/stdc++.h>

using namespace std;

const int max_n = 3, inf = 1000111222;

struct point {
    int x, y;

    void read() {
        cin >> x >> y;
    }

    bool operator < (const point &p) const {
        return x < p.x || x == p.x && y < p.y;
    }
};

point p[3];

int dist(int x, int y, const point &p) {
    return abs(x - p.x) + abs(y - p.y);
}

void write(int x, int y, point p) {
    while (x != p.x || y != p.y) {
        cout << p.x << " " << p.y << endl;
        if (p.x < x) {
            p.x += 1;
        } else if (p.x > x) {
            p.x -= 1;
        } else if (p.y < y) {
            p.y += 1;
        } else if (p.y > y) {
            p.y -= 1;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    p[0].read();
    p[1].read();
    p[2].read();
    int ans = inf;
    for (int x = 0; x < 1111; ++x) {
        for (int y = 0; y < 1111; ++y) {
            int res = 1;
            for (int i = 0; i < 3; ++i) {
                res += dist(x, y, p[i]);
            }
            ans = min(ans, res);
        }
    }
    for (int x = 0; x < 1111; ++x) {
        for (int y = 0; y < 1111; ++y) {
            int res = 1;
            for (int i = 0; i < 3; ++i) {
                res += dist(x, y, p[i]);
            }
            if (ans == res) {
                cout << ans << endl;
                cout << x << " " << y << endl;
                for (int i = 0; i < 3; ++i) {
                    write(x, y, p[i]);
                }
            }
        }
    }
    return 0;
}