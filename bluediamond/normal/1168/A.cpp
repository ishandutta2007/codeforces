#include <bits/stdc++.h>

using namespace std;

int dist(int i, int j, int m) {
        if (i <= j) {
                return (j - i);
        } else {
                return (m - i + j);
        }
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n, m;
        cin >> n >> m;
        vector <int> v(n);

        for (int i = 0; i < n; i++) {
                cin >> v[i];
        }

        int l = 0, r = m, last = -1;
        while (l <= r) {
                bool check = 1;
                int mid = (l + r) / 2;
                int ant_element = 0;
                for (auto &x : v) {
                        if (dist(x, ant_element, m) > mid) {
                                if (x > ant_element) {
                                        ant_element = x;
                                } else {
                                        check = 0;
                                        break;
                                }
                        }
                }
                if (check) {
                        r = mid - 1;
                        last = mid;
                } else {
                        l = mid + 1;
                }
        }
        cout << last << "\n";
}