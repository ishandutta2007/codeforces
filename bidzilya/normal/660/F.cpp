#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

#include <cassert>
using namespace std;

struct TLinearFunc {
    long long A;
    long long B;

    long long operator () (long long x) const {
        return A * x + B;
    }
};

using TSeg = pair<long long, long long>;

class THull {
public:
    void Init(long long l, long long r) {
        L = l;
        R = r;
    }

    void Add(const TLinearFunc& f) {
        bool needAdd = Fs.empty();
        while (!Fs.empty()) {
            const TLinearFunc& g = Fs.back();
            const TSeg& seg = Segs.back();

            if (f(seg.first) <= g(seg.first) && f(seg.second) <= g(seg.second)) {
                break;
            }

            if (f(seg.first) >= g(seg.first)) {
                Fs.pop_back();
                Segs.pop_back();
                needAdd = true;
                continue;
            }

            long long a = f.A - g.A;
            long long b = f.B - g.B;

            long long pos = (-b) / a;

            while (pos * a > -b) {
                --pos;
            }
            while ((pos + 1) * a <= -b) {
                ++pos;
            }

            assert(pos >= seg.first && pos < seg.second);

            Segs.back().second = pos;
            needAdd = true;
            break;
        }
        if (needAdd) {
            if (Fs.empty()) {
                Fs.push_back(f);
                Segs.push_back(make_pair(L, R));
            } else {
                if (R >= Segs.back().second + 1) {
                    Fs.push_back(f);
                    Segs.push_back(make_pair(Segs.back().second + 1, R));
                }
            }
        }
    }

    long long Get(long long pos) const {
        int bl = 0;
        int br = Segs.size() - 1;

        while (bl <= br) {
            int bm = (bl + br) >> 1;

            if (Segs[bm].first <= pos && Segs[bm].second >= pos) {
                return Fs[bm](pos);
            } else if (Segs[bm].first > pos) {
                br = bm - 1;
            } else {
                bl = bm + 1;
            }
        }
        assert(false);
    }
private:
    deque<TLinearFunc> Fs;
    deque<TSeg> Segs;
    long long L;
    long long R;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> s(n + 1);
    s[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        s[i] = s[i + 1] + a[i];
    }
    vector<long long> t(n + 1);
    t[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        t[i] = t[i + 1] + s[i];
    }

    const long long MAX_A = 1e7;
    const long long MAX_N = 2e5;
    const long long MAX_SUM = MAX_A * MAX_N;

    THull hull;
    hull.Init(-MAX_SUM, MAX_SUM);

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        hull.Add(TLinearFunc{i, t[i]});

        result = max(result, -s[i + 1] * (i + 1) - t[i + 1] + hull.Get(s[i + 1]));
    }

    cout << result << endl;

    return 0;
}