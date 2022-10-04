#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (n == 4) {
        cout << -1 << endl;
        return 0;
    }
    if (k <= n) {
        cout << -1 << endl;
        return 0;
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> p1;
    p1.push_back(a);
    p1.push_back(c);
    for (int i = 1; i <= n; ++i) {
        if (i != a && i != b && i != c && i != d) p1.push_back(i);
    }
    p1.push_back(d);
    p1.push_back(b);
    for (int x : p1) cout << x << ' ';
    cout << endl;
    swap(p1[0], p1[1]), swap(p1[p1.size() - 2], p1[p1.size() - 1]);
    for (int x : p1) cout << x << ' ';
    cout << endl;
}