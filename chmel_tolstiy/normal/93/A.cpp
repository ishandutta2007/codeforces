#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (b == n) {
        int k = (n+m-1) / m;
        n = b = k * m;
    }
    a--; b--;
    set<int> x;
    int r1 = a / m;
    int c1 = a % m;
    int r2 = b / m;
    int c2 = b % m;

    x.insert(0);
    x.insert(c1);
    x.insert(c2+1);
    x.insert(m);

    int res = x.size() - 1;
    res = min(res, r2 - r1 + 1);
    cout << res << endl;

    return 0;
}