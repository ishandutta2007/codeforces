#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;
const double pi = 3.14159265358979323846, eps = 1e-9;

struct point
{
    double x, y;
    void read() {
        cin >> x >> y;
    }
    bool operator != (point a) {
        return x != a.x || y != a.y;
    }
    point operator - (point a)
    {
        point b;
        b.x = x - a.x;
        b.y = y - a.y;
        return b;
    }
};

double cross_pr(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

point a[3];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 3; ++i) {
        a[i].read();
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                 if (i != j && i != k && j != k) {
                    if (cross_pr(a[i] - a[j], a[k] - a[j]) == 0) {
                        cout << "RIGHT";
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (i != j && i != k && j != k) {
                    for (int sd = 0; sd < 3; ++sd) {
                        a[sd].x--;
                        if (a[i] != a[j] && a[i] != a[k] && a[j] != a[k] && fabs(cross_pr(a[i] - a[j], a[k] - a[j])) <= eps) {
                            cout << "ALMOST";
                            return 0;
                        }
                        a[sd].x++;
                        a[sd].y--;
                        if (a[i] != a[j] && a[i] != a[k] && a[j] != a[k] && fabs(cross_pr(a[i] - a[j], a[k] - a[j])) <= eps) {
                            cout << "ALMOST";
                            return 0;
                        }
                        a[sd].y++;

                        a[sd].x++;
                        if (a[i] != a[j] && a[i] != a[k] && a[j] != a[k] && fabs(cross_pr(a[i] - a[j], a[k] - a[j])) <= eps) {
                            cout << "ALMOST";
                            return 0;
                        }
                        a[sd].x--;
                        a[sd].y++;
                        if (a[i] != a[j] && a[i] != a[k] && a[j] != a[k] && fabs(cross_pr(a[i] - a[j], a[k] - a[j])) <= eps) {
                            cout << "ALMOST";
                            return 0;
                        }
                        a[sd].y--;
                    }
                }
            }
        }
    }
    cout << "NEITHER";
    return 0;
}