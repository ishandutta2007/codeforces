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

const int max_n = 5555, inf = 1111111111;

int n, a[max_n];
vector<int> v[5];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v[a[i]].push_back(i + 1);
    }
    int cnt = min(v[1].size(), min(v[2].size(), v[3].size()));
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i) {
        cout << v[1][i] << " " << v[2][i] << " " << v[3][i] << endl;
    }
    return 0;
}