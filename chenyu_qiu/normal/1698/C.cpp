#include<iostream>
#include<vector>
using namespace std;
void solve() {
    int n, i, j, k, m, a;
    vector<int>v;
    int num = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a;
        if ((a != 0) || (a == 0 && num < 1)) {
            v.push_back(a);
            if (a == 0)num++;
        }
    }
    if (v.size() > 5) {
        cout << "NO" << endl;
        return;
    }
    int x = v.size() - 2,y=v.size() - 1,z=v.size();
    for (i = 0; i < x; i++) {
        for (j = i + 1; j <y ; j++) {
            for (k = j + 1; k <z ; k++) {
                bool judge = 0;
                int sum = v[i] + v[j] + v[k];
                for (m = 0; m < v.size(); m++) {
                    if (v[m] == sum) {
                        judge = 1;
                        break;
                    }
                }
                if (!judge) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}