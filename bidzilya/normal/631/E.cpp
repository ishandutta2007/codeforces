#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

#include <cassert>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

const int MIN_BORDER = -1e6;
const int MAX_BORDER = 1e6;

using TPair = pair<long long, long long>;

inline long long Apply(const TPair& value, int pos) {
    return value.first * pos + value.second;
}

class TConvexBox {
public:
    void Build(bool rightDir) {
        RightDir = rightDir;
        Values.clear();
        Borders.clear();
    }

    long long Get(int pos) const {
        int bl = 0;
        int br = Values.size() - 1;
        while (bl <= br) {
            int bm = (bl + br) >> 1;

            if (Borders[bm].first <= pos && Borders[bm].second >= pos) {
                return Apply(Values[bm], pos);
            } else if (Borders[bm].first > pos) {
                br = bm - 1;
            } else {
                bl = bm + 1;
            }
        }
        assert(false);
    }

    void Add(const TPair& value) {
        while (!Values.empty()) {
            const TPair curValue = (RightDir ? Values.back() : Values.front());
            const TPair curBorder = (RightDir ? Borders.back() : Borders.front());

            long long leftOldValue = Apply(curValue, curBorder.first);
            long long leftNewValue = Apply(value, curBorder.first);

            long long rightOldValue = Apply(curValue, curBorder.second);
            long long rightNewValue = Apply(value, curBorder.second);

            if (leftNewValue >= leftOldValue && rightNewValue >= rightOldValue) {
                if (RightDir) {
                    Values.pop_back();
                    Borders.pop_back();
                } else {
                    Values.pop_front();
                    Borders.pop_front();
                }
                continue;
            }

            if (leftNewValue < leftOldValue && rightNewValue < rightOldValue) {
                break;
            }

            if (RightDir) {
                long long t1 = value.first - curValue.first;
                long long t2 = curValue.second - value.second;

                int pos = t2 / t1;

                while (pos * t1 >= t2) {
                    --pos;
                }
                while ((pos + 1) * t1 < t2) {
                    ++pos;
                }

                Borders.back().second = pos;
            } else {
                long long t1 = curValue.first - value.first;
                long long t2 = value.second - curValue.second;

                int pos = t2 / t1;

                while (pos * t1 <= t2) {
                    ++pos;
                }
                while ((pos - 1) * t1 > t2) {
                    --pos;
                }

                Borders.front().first = pos;
            }
            break;
        }

        if (Values.empty()) {
            Values.push_back(value);
            Borders.push_back(make_pair(MIN_BORDER, MAX_BORDER));
        } else {
            if (RightDir) {
                if (Borders.back().second + 1 <= MAX_BORDER) {
                    Values.push_back(value);
                    Borders.push_back(make_pair(Borders.back().second + 1, MAX_BORDER));
                }
            } else {
                if (Borders.front().first - 1 >= MIN_BORDER) {
                    Values.push_front(value);
                    Borders.push_front(make_pair(MIN_BORDER, Borders.front().first - 1));
                }
            }
        }
    }

private:
    bool RightDir;
    deque<TPair> Values;
    deque<TPair> Borders;
};

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    vector<long long> sum(n);
    sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }

    long long baseValue = 0;
    for (int i = 0; i < n; ++i) {
        baseValue += 1LL * (i + 1) * a[i];
    }

    long long result = baseValue;

    TConvexBox box;

    box.Build(true);
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            long long curAdd = sum[i - 1] - 1LL * a[i] * (i + 1);
            curAdd += box.Get(a[i]);
            result = max(result, baseValue + curAdd);
        }
        box.Add(make_pair(i + 1, (i == 0 ? 0 : -sum[i - 1])));
    }

    box.Build(false);
    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1) {
            long long curAdd = -1LL * a[i] * (i + 1) + sum[i];
            curAdd += box.Get(a[i]);
            result = max(result, baseValue + curAdd);
        }
        box.Add(make_pair(i + 1, -sum[i]));
    }

    printf(LLD_SPEC "\n", result);

    return 0;
}