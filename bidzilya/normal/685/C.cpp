#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include <cassert>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

inline int GetBit(int mask, int num) {
    return (mask >> num) & 1;
}

const long long INF = 1e18;
const long long INF3 = 3 * INF;

struct TPoint {
    long long X;
    long long Y;
    long long Z;

    void Init(const vector<long long>& coeffs) {
        assert(coeffs.size() == 3);
        X = coeffs[0];
        Y = coeffs[1];
        Z = coeffs[2];
    }

    void Read() {
        scanf(LLD_SPEC LLD_SPEC LLD_SPEC, &X, &Y, &Z);
    }

    void Write() const {
        printf(LLD_SPEC " " LLD_SPEC " " LLD_SPEC, X, Y, Z);
    }

    vector<long long> GetCoords() const {
        return vector<long long>{X, Y, Z};
    }
};

const vector<TPoint> BASE_POINTS = {
    {1, 1, 1},
    {-1, 1, 1},
    {1, -1, 1},
    {1, 1, -1}
};

inline long long GetSMult(const TPoint& lhs, const TPoint& rhs) {
    return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
}

vector<long long> minVals;
vector<long long> maxVals;

vector<vector<long long>> curVals(4, vector<long long>(2));

bool Check(int n, long long d, TPoint& result) {
    auto update = [] (long long& a, long long& b) {
        b >>= 1;
        if (a & 1) {
            ++a;
        }
        a >>= 1;
    };

    for (int b = 0; b < 2; ++b) {
        for (int i = 1; i < 4; ++i) {
            curVals[i][0] = minVals[i] - d - b;
            curVals[i][1] = maxVals[i] + d - b;

            update(curVals[i][0], curVals[i][1]);
        }

        curVals[0][0] = minVals[0] - d - 3 * b;
        curVals[0][1] = maxVals[0] + d - 3 * b;

        update(curVals[0][0], curVals[0][1]);

        bool ok = true;
        for (int i = 0; i < 4; ++i) {
            if (curVals[i][0] > curVals[i][1]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }

        long long minVal = curVals[1][0] + curVals[2][0] + curVals[3][0];
        long long maxVal = curVals[1][1] + curVals[2][1] + curVals[3][1];

        if (minVal > curVals[0][1] || maxVal < curVals[0][0]) {
            continue;
        }

        vector<long long> vals(3);
        vals[0] = curVals[1][0];
        vals[1] = curVals[2][0];
        vals[2] = curVals[3][0];

        long long sumVal = minVal;

        if (sumVal < curVals[0][0]) {
            long long need = curVals[0][0] - sumVal;

            long long d = min(curVals[1][1] - vals[0], need);
            need -= d;
            vals[0] += d;

            d = min(curVals[2][1] - vals[1], need);
            need -= d;
            vals[1] += d;

            d = min(curVals[3][1] - vals[2], need);
            need -= d;
            vals[2] += d;
        }

        for (int i = 0; i < 3; ++i) {
            vals[i] <<= 1;
            vals[i] += b;
        }

        result.Init({(vals[1] + vals[2]) >> 1, (vals[0] + vals[2]) >> 1, (vals[0] + vals[1]) >> 1});
        return true;
    }

    return false;
}

int main() {
    // freopen("input2.txt", "r", stdin);

    int tests;
    scanf("%d", &tests);
    for (int test = 0; test < tests; ++test) {
        int n;
        scanf("%d", &n);

        vector<TPoint> points(n);
        for (int i = 0; i < n; ++i) {
            points[i].Read();
        }

        minVals.assign(4, -INF3);
        maxVals.assign(4, INF3);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                long long a = GetSMult(BASE_POINTS[j], points[i]);

                minVals[j] = max(minVals[j], a);
                maxVals[j] = min(maxVals[j], a);
            }
        }

        TPoint result;
        long long bl = 0;
        long long br = 3 * INF;
        while (bl <= br) {
            long long bm = (bl + br) >> 1;

            if (Check(n, bm, result)) {
                br = bm - 1;
            } else {
                bl = bm + 1;
            }
        }

        result.Write();
        printf("\n");
    }

    return 0;
}