#include <bits/stdc++.h>

using namespace std;

#define int long long

int per(vector<int> a, int k) {
    int n = (int) a.size();
    if (n % k)
        return 0;
    for (int i = k; i < n; i++)
        if (a[i] != a[i - k])
            return 0;
    return 1;
}

int sm(vector<int> a) {
    int ans = 1;
    while (!per(a, ans))
        ans++;
    return ans;
}

int dp[100][100];
vector<int> p;

void build_dp() {
    for (int i = 1; i < 100; i++) {
        for (int j = 1; j < i; j++)
            if (i % j == 0)
                dp[i][j] = dp[i - j][j];
        dp[i][i] = (1LL << (i - 1));
        for (int j = 1; j < i; j++)
            dp[i][i] -= dp[i][j];
    }
}

vector<int> operator + (vector<int> a, vector<int> b) {
    for (int i = 0; i < (int) b.size(); i++)
        a.push_back(b[i]);
    return a;
}

int sol[100];

int get_dp(vector<int> a, int d) {
    int n = (int) a.size();
    for (int i = 1; i <= d; i++) {
        if (i <= n) {
            vector<int> first_i;
            for (int j = 0; j < i; j++)
                first_i.push_back(a[j]);
            vector<int> sum;
            while ((int) sum.size() < (int) a.size())
                sum = sum + first_i;
            sol[i] = 1;
            for (int j = 0; j < (int) a.size(); j++)
                if (a[j] != sum[j])
                    sol[i] = 0;
        } else
            sol[i] = (1LL << (i - n));
        for (int j = 1; j < i; j++)
            if (i % j == 0)
                sol[i] -= sol[j];
    }
    return sol[d];
}

int prefix(int x) {
    if (x == 0)
        return 1;
    int len = log2(x) + 1, ans = 1;
    for (int i = 1; i < len; i++)
        for (int x = 1; x < i; x++)
            ans += dp[i][x];
    vector<int> a;
    int y = x;
    while (x) {
        a.push_back(x % 2);
        x /= 2;
    }
    reverse(a.begin(), a.end());
    x = y;
    for (int d = 1; d < len; d++)
        if (len % d == 0) {
            int init = ans;
            vector<int> first_d, sum;
            for (int i = 0; i < d; i++)
                first_d.push_back(a[i]);
            for (int i = 0; i < len / d; i++)
                sum = sum + first_d;
            ans += (sum <= a && sm(sum) == d);
            for (int same = 1; same < d; same++)
                if (a[same] == 1) {
                    vector<int> troll;
                    for (int i = 0; i < same; i++)
                        troll.push_back(a[i]);
                    troll.push_back(0);
                    ans += get_dp(troll, d);
                }
        }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    build_dp();
    int l, r;
    cin >> l >> r;
    cout << prefix(r) - prefix(l - 1) << "\n";
}