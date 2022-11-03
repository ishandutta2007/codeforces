#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MIN_DIST = 0;
const long long MAX_DIST = 1e18;

const long long MAX_COORD = 1e18;;
const long long MIN_COORD = -1e18;

bool InnerCheck(const vector<pair<long long, long long>>& x, const vector<pair<long long, long long>>& prefix,
           const vector<pair<long long, long long>>& suffix, int n, long long maxDist)
{
    if ((prefix[n - 1].second - prefix[n - 1].first) * (prefix[n - 1].second - prefix[n - 1].first) <= maxDist) {
        return true;
    }
    if ((x[n - 1].first - x[0].first) * (x[n - 1].first - x[0].first) <= maxDist) {
        return true;
    }
    for (int l = 0, r = -1; l < n; ++l) {
        r = max(r, l);
        while (r + 1 < n && (x[r + 1].first - x[l].first) * (x[r + 1].first - x[l].first) <= maxDist &&
                            abs(x[r + 1].first) <= abs(x[l].first))
        {
            ++r;
        }
        while (r - 1 > l && abs(x[r].first) > abs(x[l].first)) {
            --r;
        }

        long long curMaxDist = 0;

        long long minYCoord = MAX_COORD;
        long long maxYCoord = MIN_COORD;

        const auto& update = [&curMaxDist] (long long x, long long y) {
            curMaxDist = max(curMaxDist, x * x + y * y);
        };

        if (l != 0) {
            update(prefix[l - 1].first, x[l].first);
            update(prefix[l - 1].first, x[r].first);
            update(prefix[l - 1].second, x[l].first);
            update(prefix[l - 1].second, x[r].first);

            minYCoord = min(minYCoord, prefix[l - 1].first);
            maxYCoord = max(maxYCoord, prefix[l - 1].second);
        }

        if (r != n - 1) {
            update(suffix[r + 1].first, x[l].first);
            update(suffix[r + 1].first, x[r].first);
            update(suffix[r + 1].second, x[l].first);
            update(suffix[r + 1].second, x[r].first);

            minYCoord = min(minYCoord, suffix[r + 1].first);
            maxYCoord = max(maxYCoord, suffix[r + 1].second);
        }

        if (minYCoord < maxYCoord) {
            curMaxDist = max(curMaxDist, (maxYCoord - minYCoord) * (maxYCoord - minYCoord));
        }

        if (curMaxDist <= maxDist) {
            return true;
        }
    }
    return false;
}

bool Check(vector<pair<long long, long long>>& x, vector<pair<long long, long long>>& prefix,
           vector<pair<long long, long long>>& suffix, int n, long long maxDist)
{
    if (InnerCheck(x, prefix, suffix, n, maxDist)) {
        return true;
    }
    reverse(x.begin(), x.end());
    reverse(prefix.begin(), prefix.end());
    reverse(suffix.begin(), suffix.end());
    bool result = InnerCheck(x, suffix, prefix, n, maxDist);
    reverse(x.begin(), x.end());
    reverse(prefix.begin(), prefix.end());
    reverse(suffix.begin(), suffix.end());
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long long, long long>> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i].first >> x[i].second;
    }

    sort(x.begin(), x.end());

    vector<pair<long long, long long>> prefix(n);
    vector<pair<long long, long long>> suffix(n);

    prefix[0].first = prefix[0].second = x[0].second;
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1];
        prefix[i].first = min(prefix[i].first, x[i].second);
        prefix[i].second = max(prefix[i].second, x[i].second);
    }

    suffix[n - 1].first = suffix[n - 1].second = x[n - 1].second;
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = suffix[i + 1];
        suffix[i].first = min(suffix[i].first, x[i].second);
        suffix[i].second = max(suffix[i].second, x[i].second);
    }

    long long bl = MIN_DIST;
    long long br = MAX_DIST;
    long long ba = MAX_DIST;

    while (bl <= br) {
        long long bm = (bl + br) >> 1;

        if (Check(x, prefix, suffix, n, bm)) {
            ba = bm;
            br = bm - 1;
        } else {
            bl = bm + 1;
        }
    }

    cout << ba << endl;

    return 0;
}