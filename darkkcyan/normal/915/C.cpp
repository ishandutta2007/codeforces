#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    if (a.size() < b.size()) {
        sort(a.rbegin(), a.rend());
        cout << a;
        return 0;
    }
    for (int i = 0; i < (int)a.size(); ++i) {
        pair<int, int> max_dig = {'0', -1};
        for (int f = i; f < (int)a.size(); ++f) {
            string c = a;
            swap(c[f], c[i]);
            sort(c.begin() + i + 1, c.end());
            if (c <= b) {
                max_dig = max(max_dig, {a[f], f});
            }
        }
        swap(a[i], a[max_dig.second]);
    }
    cout << a;
}