#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int n;
string a, b;
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        int pos = a.find(b[i], i);
        if (pos == -1) {
            cout << -1 << endl;
            return 0;
        }
        while (pos > i) {
            swap(a[pos - 1], a[pos]);
            ans.push_back(pos);
            --pos;
        }
    }
    cout << ans.size() << "\n";
    for (int pos : ans) {
        cout << pos << " ";
    }
    cout << "\n";
    return 0;
}