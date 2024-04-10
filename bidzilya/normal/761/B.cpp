#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, l;
vector<int> a, b;
vector<int> poses;

void Solve() {
    poses.resize(n);
    for (int s = 0; s < l; ++s) {
        for (int i = 0; i < n; ++i) {
            poses[i] = (s + b[i]) % l;
        }
        for (int itr = 0; itr < n; ++itr) {
            if (poses == a) {
                cout << "YES" << endl;
                return;
            }
            int value = poses[0];
            poses.erase(poses.begin());
            poses.push_back(value);
        }
    }
    cout << "NO" << endl;
}

bool Read() {
    if (!(cin >> n >> l)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}