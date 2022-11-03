#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const long long INF = 1e18;
const int INT_INF = 1e9;

const int BASE = 5;

long long GetSums(const vector<long long>& sums, int l, int r) {
    return (l == 0 ? sums[r] : sums[r] - sums[l - 1]);
}

long long Solve(const vector<long long>& b, const vector<long long>& addCost, int n, long long cost, int k) {
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].first = b[i];
        a[i].second = addCost[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        a[i].second -= a[i].first * cost;
    }
    priority_queue<long long> q;
    long long qSum = 0;
    for (int i = 0; i < k; ++i) {
        q.push(a[i].second);
        qSum += a[i].second;
    }
    long long minCost = qSum + cost * a[k - 1].first * k;
    for (int i = k; i < n; ++i) {
        q.push(a[i].second);
        qSum += a[i].second;
        qSum -= q.top();
        q.pop();
        minCost = min(minCost, qSum + cost * a[i].first * k);
    }
    return minCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    long long bCost, cCost;
    cin >> n >> k >> bCost >> cCost;

    vector<long long> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        t[i] += INT_INF;
    }

    sort(t.begin(), t.end());

    if (5 * cCost <= bCost) {
        vector<long long> sums(n);
        sums[0] = t[0];
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + t[i];
        }
        const auto& getCost = [&] (int pos) -> long long {
            return t[pos] * k - GetSums(sums, pos - k + 1, pos);
        };
        long long minCost = getCost(k - 1);
        for (int i = k; i < n; ++i) {
            minCost = min(minCost, getCost(i));
        }
        cout << minCost * cCost << endl;
    } else {
        long long minCost = INF;
        vector<int> rems(n);
        for (int i = 0; i < n; ++i) {
            rems[i] = t[i] % BASE;
        }
        vector<long long> b(n);
        vector<long long> c(n);
        for (int r = 0; r < BASE; ++r) {
            for (int i = 0; i < n; ++i) {
                c[i] = 0;
                int oldRem = rems[i];
                while (rems[i] != r) {
                    ++rems[i];
                    ++c[i];
                    if (rems[i] >= BASE) {
                        rems[i] -= BASE;
                    }
                }
                b[i] = (t[i] + c[i]) / BASE;
                c[i] *= cCost;
                rems[i] = oldRem;
            }
            minCost = min(minCost, Solve(b, c, n, bCost, k));
        }
        cout << minCost << endl;
    }
    return 0;
}