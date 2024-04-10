#include <iostream>
using namespace std;

bool solve()
{
    int u, v;
    cin >> u >> v;
    for (int i = 29; i >= 0; i--) {
        if ((u >> i) % 2 == 1 && (v >> i) % 2 == 1) {
            u -= 1 << i;
            v -= 1 << i;
        }
        if (v < u)
            return false;
    }
    while (v) {
        if (u == 0)
            return false;
        int uu = u & -u;
        int vv = v & -v;
        if (vv < uu)
            return false;
        v -= vv;
        u -= uu;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
        cout << (solve() ? "Yes" : "No") << endl;
    return 0;
}