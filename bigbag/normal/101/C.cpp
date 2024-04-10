#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

struct line {
    long long A, B, C;
    line() {
        A = B = C = 0;
    }
    line(long long A, long long B, long long C) : A(A), B(B), C(C) {
    }
};

bool p_line(line a, line b) {
    long long f = a.A * b.B - b.A * a.B;
    if (f == 0) {
        return false;
    }
    if ((b.A * a.C - a.A * b.C) % (a.A * b.B - b.A * a.B) != 0) return false;
    if ((b.C * a.B - b.B * a.C) % (a.A * b.B - b.A * a.B) != 0) return false;
    return true;
}

int ax, bx, cx, ay, by, cy;
int a[3], b[3];

bool ok2() {
    for (int i = 0; i < 3; ++i) {
        //cout << a[i] << " " << b[i] << endl;
    }
    return p_line(line(a[0], a[1], a[2]), line(b[0], b[1], b[2]));
}

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (a != 0 && b != 0) {
        int k = a;
        a = b;
        b = k % b;
    }
    return a + b;
}

bool ok() {
    int A = bx - ax;
    int B = by - ay;
    a[0] = cx;
    a[1] = cy;
    a[2] = -A;
    int ga = gcd(a[0], gcd(a[1], a[2]));
    b[0] = cy;
    b[1] = -cx;
    b[2] = -B;
    int gb = gcd(b[0], gcd(b[1], b[2]));
    if (ok2()) {
        return true;
    }
    //cout << ax << " " << ay << "   " << A << " " << B << "     gcd " << ga << " " << gb << endl;
    if (ga != 0) {
        a[0] /= ga;
        a[1] /= ga;
        a[2] /= ga;
    }
    if (gb != 0) {
        b[0] /= gb;
        b[1] /= gb;
        b[2] /= gb;
    }
    if ((a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2])) {
        if ((a[0] != 0 || a[1] != 0)) return true;
        if (a[0] == 0 && a[1] == 0 && a[2] == 0) return true;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    for (int i = 0; i < 4; ++i) {
        if (ok()) {
            cout << "YES" << endl;
            return 0;
        }
        swap(ax, ay);
        ay *= -1;
    }
    cout << "NO" << endl;
    return 0;
}