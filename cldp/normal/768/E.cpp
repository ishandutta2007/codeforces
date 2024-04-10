#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 2010;

unordered_map<long long, bool> z[61];
unordered_map<long long, int> f[61];

int g[61] = {100, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

int dp(int a, long long b) {
    if (z[a][b]) return f[a][b];
    z[a][b] = true;
    vector<int> X;
    for (int i = 1; i <= a; ++i) {
        if ((1LL << i) & b) continue;
        X.push_back(dp(a - i, b | (1LL << i)));
    }
    if (X.empty()) return f[a][b] = 0;
    unordered_set<int> S;
    for (int i = 0; i < X.size(); ++i) S.insert(X[i]);
    int ans = 0;
    while (true) {
        if (S.find(ans) == S.end()) break;
        ++ans;
    }
    return f[a][b] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;

    //for (int i = 1; i <= 60; ++i) dp(i, 0);
    
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        ans ^= g[a];
    }
    if (ans == 0) cout << "YES" << endl; else cout << "NO" << endl;
    
    return 0;
}