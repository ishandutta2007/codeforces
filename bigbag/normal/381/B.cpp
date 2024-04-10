#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 111111111;

int n, a[max_n], used[5555];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        used[a[i]]++;
    }
    vector <int> ans;
    for (int i = 1; i <= 5000; ++i) {
        if (used[i] > 0) {
            ans.push_back(i);
            --used[i];
        }
    }
    for (int i = 5000; i > 0; --i) {
        if (used[i] > 0 && i != ans[ans.size() - 1]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}