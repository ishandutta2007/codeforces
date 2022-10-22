#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1000;
const int MAXM = 1100;
const int INF = 2000000000;

int n;
long long x[2000010];


long long dfs(int a, int b) {
    if (b == n) return x[a];
    long long ans = x[a];
    ans += dfs(a, b * 4);
    ans += dfs(a + b, b * 4);
    ans += dfs(a + 2 * b, b * 4);
    ans += dfs(a + 3 * b, b * 4);
    return ans;
}



int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        x[i] = -x[i];
    }
    sort(x, x + n);
    
    cout << -dfs(0, 1) << endl;
    
    
    return 0;
}