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

struct pers{
    int t, num, num1;
    bool operator < (const pers &a) const {
        return t < a.t;
    }
};

int n, ans[2][max_n];
pers p1[max_n], p2[max_n];
vector <pers> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        p1[i].t = a;
        p2[i].t = b;
        p1[i].num = i;
        p2[i].num = i;
        p1[i].num1 = 0;
        p2[i].num1 = 1;
        v.push_back(p1[i]);
        v.push_back(p2[i]);
    }
    sort(p1, p1 + n);
    sort(p2, p2 + n);
    sort(v.begin(), v.end());
    for (int i = 0; i < n / 2; ++i) {
        ans[0][p1[i].num] = 1;
        ans[1][p2[i].num] = 1;
    }
    for (int i = 0; i < n; ++i) {
        ans[v[i].num1][v[i].num] = 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[0][i];
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[1][i];
    }
    return 0;
}