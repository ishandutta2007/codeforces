#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TBox {
    long long Sum;
    int First;
    int Second;
};

bool operator < (const TBox& lhs, const TBox& rhs) {
    return lhs.Sum < rhs.Sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<long long> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    long long sa = 0;
    long long sb = 0;

    for (int i = 0; i < n; ++i) {
        sa += a[i];
    }
    for (int i = 0; i < m; ++i) {
        sb += b[i];
    }

    vector<pair<int, int>> swaps;
    long long result = abs(sa - sb);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long newResult = abs(sa - sb + 2 * (b[j] - a[i]));
            if (newResult < result) {
                swaps = vector<pair<int, int>>{make_pair(i, j)};
                result = newResult;
            }
        }
    }

    vector<TBox> as;
    as.reserve(n * (n - 1) / 2);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            as.push_back(TBox{a[i] + a[j], i, j});
        }
    }
    sort(as.begin(), as.end());

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            long long curSum = 2 * (b[i] + b[j]) + sa - sb;

            int bl = 0;
            int br = as.size() - 1;
            int ba = -1;
            while (bl <= br) {
                int bm = (bl + br) >> 1;

                if (curSum <= 2 * as[bm].Sum) {
                    ba = bm;
                    br = bm - 1;
                } else {
                    bl = bm + 1;
                }
            }

            if (ba != -1) {
                long long newResult = abs(curSum - 2 * as[ba].Sum);
                if (newResult < result) {
                    swaps = vector<pair<int, int>>{make_pair(as[ba].First, i), make_pair(as[ba].Second, j)};
                    result = newResult;
                }
            }

            bl = 0;
            br = as.size() - 1;
            ba = -1;
            while (bl <= br) {
                int bm = (bl + br) >> 1;

                if (curSum >= 2 * as[bm].Sum) {
                    ba = bm;
                    bl = bm + 1;
                } else {
                    br = bm - 1;
                }
            }

            if (ba != -1) {
                long long newResult = abs(curSum - 2 * as[ba].Sum);
                if (newResult < result) {
                    swaps = vector<pair<int, int>>{make_pair(as[ba].First, i), make_pair(as[ba].Second, j)};
                    result = newResult;
                }
            }
        }
    }


    cout << result << endl;
    cout << swaps.size() << endl;
    for (int i = 0; i < (int) swaps.size(); ++i) {
        cout << swaps[i].first + 1 << " " << swaps[i].second + 1 << endl;
    }

    return 0;
}