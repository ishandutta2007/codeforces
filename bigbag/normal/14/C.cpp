#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111;

struct point {
    int x, y;
    void operator = (point a) {
        x = a.x;
        y = a.y;
    }
    bool operator == (point a) {
        return x == a.x && y == a.y;
    }
};

point a[4], b[4];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 4; ++i) {
        cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
        int f = 0;
        if (a[i].x == b[i].x) {
            f = 1;
            if (a[i].y > b[i].y) {
                swap(a[i], b[i]);
            }
        }
        if (a[i].y == b[i].y) {
            f = 1;
            if (a[i].x > b[i].x) {
                swap(a[i], b[i]);
            }
        }
        if (f == 0) {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int i1 = 0; i1 < 4; ++i1) {
                for (int j1 = 0; j1 < 4; ++j1) {
                    point c[4], d[4];
                    c[0] = a[i];
                    d[0] = b[i];
                    c[1] = a[j];
                    d[1] = b[j];
                    c[2] = a[i1];
                    d[2] = b[i1];
                    c[3] = a[j1];
                    d[3] = b[j1];
                    if (c[0] == d[2] && d[0] == d[3] && d[1] == c[3] && c[1] == c[2]) {
                        if (c[0].x == c[1].x && c[0].x == c[2].x  &&  d[0].x == d[1].x && d[0].x == c[3].x) {
                            if (c[0].y == d[0].y && c[0].y == d[3].y  &&  c[1].y == d[1].y && c[1].y == c[3].y) {
                                if (d[0].x - c[0].x == 0 || c[0].y - c[1].y == 0);
                                else {
                                    cout << "YES";
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "NO";
    return 0;
}