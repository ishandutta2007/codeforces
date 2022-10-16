#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x; --x;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x; --x;
        v[i] = x;
    }
    
    vector<int> l(n, 1);
    int X = 0;
    int y = x;
    while (y >= 0) {
        ++X;
        l[y] = 0;
        y = v[y];
    }
    //cerr << "X = " << X << endl;
    for (int i = 0; i < n; ++i) {
        int y = i;
        while (y != x && y >= 0) y = v[y];
        if (y == x) l[i] = 0;
    }
    
    for (int it = 0; it <= n + 10; ++it) {
        for (int i = 0; i < n; ++i) if (v[i] >= 0) {
            l[v[i]] += l[i];
            l[i] = 0;
        }
    }
    vector<int> s;
    for (int i = 0; i < n; ++i) if (l[i]) s.push_back(l[i]);
    
    vector<int> c(n + 1);
    c[0] = 1;
    for (int i = 0; i < s.size(); ++i) for (int j = n; j >= 0; j--)
    if (c[j]) c[j + s[i]] = 1;
    
    for (int i = 0; i <= n; ++i) if (c[i])
        cout << X + i << endl;
    return 0;
}