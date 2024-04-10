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

const int max_n = 101111, inf = 1011111111;

int n;
long long dp[max_n];
pair<int, pair<int, int> > a[max_n];
vector<pair<int, long long> > q;

void write() {
    for (int i = 0; i < q.size(); ++i) {
        cout << "(" << q[i].first << " " << q[i].second << ") ";
    }
    cout << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &a[i].second.first, &a[i].first, &a[i].second.second);
    }
    a[n] = make_pair(inf, make_pair(-inf, 0));
    ++n;
    sort(a, a + n);
    reverse(a, a + n);
    dp[0] = a[0].second.second;
    q.push_back(make_pair(a[0].second.first, dp[0]));
    long long ans = dp[0];
    for (int i = 1; i < n; ++i) {
        while (q.size() && q.back().first >= a[i].first) {
            q.pop_back();
        }
        //write();
        dp[i] = q.back().second + a[i].second.second;
        //cout << dp[i] << endl;
        ans = max(ans, dp[i]);
        while (q.size() && q.back().first >= a[i].second.first) {
            q.pop_back();
        }
        q.push_back(make_pair(a[i].second.first, dp[i]));
    }
    printf("%I64d\n", ans);
    return 0;
}