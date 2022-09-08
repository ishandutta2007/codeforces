#include <bits/stdc++.h>

using namespace std;

int n, x;
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int last = -1;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x == 1) {
            if (last != -1) {
                v.push_back(i - last);
            }
            last = i;
        }
    }
    v.push_back(n - last);
    cout << v.size() << endl;
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}