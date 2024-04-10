#include <bits/stdc++.h>

using namespace std;

int CheckOne(vector<pair<int, int>> V, int have) {
    sort(V.begin(), V.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    int n = V.size();

    vector<int> Max(n);
    int acc = -1e9;
    for (int i = 0; i < n; ++i) {
        acc = max(acc, V[i].first);
        Max[i] = acc;
    }

    int j = 0, ans = -1e9;
    for (int i = n - 1; i > 0; --i) {
        while (V[i].second + V[j].second <= have) {
            ++j;
            if (i == j) break;
        }
        if (j == 0) continue;
        --j;
        j = min(j, i - 1);
        if (j < 0) {
            j = 0;
            continue;
        }

        assert(V[i].second + V[j].second <= have);
        ans = max(ans, V[i].first + Max[j]);
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int n, have[2];
    cin >> n >> have[0] >> have[1];

    vector<pair<int, int>> V[2];
    for (int i = 0; i < n; ++i) {
        int b, p; char t;
        cin >> b >> p >> t;

        V[t == 'D'].emplace_back(b, p);
    }

    // Check TD
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        int now = -1e9;
        for (auto p : V[i]) {
            if (p.second <= have[i])
                now = max(now, p.first);
        }
        ans += now;
    }

    for (int i = 0; i < 2; ++i) {
        ans = max(ans, CheckOne(V[i], have[i]));
    }

    if (ans < 0) ans = 0;
    cout << ans << endl;

	
	return 0;
}