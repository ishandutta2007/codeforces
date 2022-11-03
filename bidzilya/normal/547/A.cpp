#include <bits/stdc++.h>
using namespace std;

void GetPF(long long x, long long y, long long h, long long a, long long m, long long& p, long long& f)
{
    vector<bool> used(m, false);
    p = 0;
    while (h != a) {
        if (used[h]) {
            p = -1;
            return;
        }
        used[h] = true;
        ++p;
        h = (x * h + y) % m;
    }
    used.assign(m, false);
    f = 1;
    h = (x * h + y) % m;
    while (h != a) {
        if (used[h]) {
            f = -1;
            return;
        }
        used[h] = true;
        ++f;
        h = (x * h + y) % m;
    }
}

long long GetGcd(long long a, long long b)
{
    while (a > 0 && b > 0) {
        if (a >= b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long m;
    long long x1, y1, x2, y2, h1, h2, a1, a2;
    cin >> m;
    cin >> h1 >> a1;
    cin >> x1 >> y1;
    cin >> h2 >> a2;
    cin >> x2 >> y2;
    
    long long p1, f1;
    GetPF(x1, y1, h1, a1, m, p1, f1);
    
    long long p2, f2;
    GetPF(x2, y2, h2, a2, m, p2, f2);
    
    if (p1 == -1 || p2 == -1) {
        cout << -1 << endl;
        return 0;
    }
    
    if (f1 == -1 && f2 == -1) {
        if (p1 == p2) {
            cout << p1 << endl;
            return 0;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    
    if (f1 == -1) {
        if ((p1 - p2) % f2 == 0 && p1 - p2 >= 0) {
            cout << p1 << endl;
            return 0;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    
    if (f2 == -1) {
        if ((p2 - p1) % f1 == 0 && p2 - p1 >= 0) {
            cout << p2 << endl;
            return 0;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    
    if (f1 == f2) {
        if ((p2 - p1) % f1 == 0) {
            cout << max(p1, p2) << endl;
            return 0;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    
    if (f2 > f1) {
        swap(p1, p2);
        swap(f1, f2);
        swap(x1, x2);
        swap(y1, y2);
        swap(h1, h2);
        swap(a1, a2);
    }
    
    long long a = f2;
    long long b = (p1 - p2) % f1;
    if (b < 0) {
        b += f1;
    }
    long long c = f1;
    
    long long g = GetGcd(a, c);
    
    if (g != 1) {
        if (b % g != 0) {
            cout << -1 << endl;
            return 0;
        }
        a /= g;
        b /= g;
        c /= g;
    }
    
    long long inv = -1;
    for (long long i = 1; i < c; ++i) {
        if ((i * a) % c == 1) {
            inv = i;
            break;
        }
    }
    assert(inv != -1);
    long long k2 = (b * inv) % c;
    long long k1 = (p2 - p1 + f2 * k2) / f1;
    
    if (k1 < 0) {
        k1 = 0;
        k2 += abs(k1) * f1;
    }
    
    cout << p2 + f2 * k2 << endl;
    
    return 0;
}