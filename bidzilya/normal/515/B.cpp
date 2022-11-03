#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

int GetGCD(int a, int b)
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
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0);
    vector<int> b(m, 0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    cin >> t;
    for (int i = 0; i < t; ++i) {
        int x;
        cin >> x;
        b[x] = 1;
    }

    int g = GetGCD(n, m);
    vector<int> c(g, 0);

    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            c[i % g] = 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        if (b[i]) {
            c[i % g] = 1;
        }
    }

    for (int i = 0; i < g; ++i) {
        if (!c[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}