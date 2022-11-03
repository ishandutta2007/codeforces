#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<pair<int, int>> g(m);
    for (int i = 0; i < m; ++i) {
        cin >> g[i].first >> g[i].second;
    }

    vector<pair<int, int>> minDollar(n);
    minDollar[0].first = a[0];
    minDollar[0].second = 0;
    for (int i = 1; i < n; ++i) {
        minDollar[i] = min(minDollar[i - 1], make_pair(a[i], i));
    }

    vector<pair<int, int>> minFunt(n);
    minFunt[0].first = b[0];
    minFunt[0].second = 0;
    for (int i = 1; i < n; ++i) {
        minFunt[i] = min(minFunt[i - 1], make_pair(b[i], i));
    }

    int resultK = -1;
    vector<int> resultBuyDay(m, -1);

    int bl = 0;
    int br = n - 1;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        vector<pair<long long, int>> costs(m);
        vector<int> day(m);
        for (int i = 0; i < m; ++i) {
            long long cost;
            if (g[i].first == 1) {
                cost = minDollar[bm].first;
                day[i] = minDollar[bm].second;
            } else {
                cost = minFunt[bm].first;
                day[i] = minFunt[bm].second;
            }
            cost *= g[i].second;
            costs[i].first = cost;
            costs[i].second = i;
        }
        sort(costs.begin(), costs.end());

        long long curCost = 0;
        for (int i = 0; i < k; ++i) {
            curCost += costs[i].first;
        }

        if (curCost <= s) {
            resultK = bm;
            resultBuyDay.assign(m, -1);
            for (int i = 0; i < k; ++i) {
                resultBuyDay[costs[i].second] = day[costs[i].second];
            }
            br = bm - 1;
        } else {
            bl = bm + 1;
        }
    }

    if (resultK == -1) {
        cout << -1 << endl;
        return 0;
    }

    cout << resultK + 1 << endl;
    for (int i = 0; i < m; ++i) {
        if (resultBuyDay[i] != -1) {
            cout << i + 1 << " " << resultBuyDay[i] + 1 << '\n';
        }
    }
    cout.flush();

    return 0;
}