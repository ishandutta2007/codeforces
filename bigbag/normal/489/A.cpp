#include <map>
#include <set>
#include <stack>
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

const int max_n = 3333, inf = 1111111111;

int n, a[max_n];
vector<pair<int, int> > ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 1; i > 0; --i) {
        int mx = a[i], poz = i;
        for (int j = 0; j <= i; ++j) {
            if (mx < a[j]) {
                mx = a[j];
                poz = j;
            }
        }
        ans.push_back(make_pair(i, poz));
        swap(a[i], a[poz]);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}