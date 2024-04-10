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

const int max_n = 3, inf = 1111111111;

int u[3], d[3][3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> d[0][1] >> d[0][2] >> d[1][2];
    d[1][0] = d[0][1];
    d[2][0] = d[0][2];
    d[2][1] = d[1][2];
    int n1 = 1, n2 = 2;
    int ans = inf;
    ans = min(ans, d[0][n1] + d[n1][0] + d[0][n2] + d[n2][0]);
    ans = min(ans, d[0][n1] + d[n1][n2] + d[n2][n1] + d[n1][0]);
    ans = min(ans, d[0][n1] + d[n1][n2] + d[n2][0]);
    swap(n1, n2);
    ans = min(ans, d[0][n1] + d[n1][0] + d[0][n2] + d[n2][0]);
    ans = min(ans, d[0][n1] + d[n1][n2] + d[n2][n1] + d[n1][0]);
    ans = min(ans, d[0][n1] + d[n1][n2] + d[n2][0]);
    cout << ans << endl;
    return 0;
}