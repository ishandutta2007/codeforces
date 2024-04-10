#include <iostream>
#include <vector>
#include <algorithm>

#include <cassert>
using namespace std;

int n;
vector<long long> x;
vector<long long> prefixSum;

struct TResult {
    bool Init;
    bool IsEven;
    int K;
    int Pos;
};

inline long long GetSum(const vector<long long>& s, int l, int r) {
    l = max(l, 0);
    r = min(r, (int) s.size() - 1);
    if (l > r) {
        return 0;
    }
    return ((l == 0) ? s[r] : s[r] - s[l - 1]);
}

inline long long GetSum(const TResult& a) {
    long long result = 0;
    if (a.IsEven) {
        result += x[a.Pos];
        result += x[a.Pos + 1];
    } else {
        result += x[a.Pos];
    }
    result += GetSum(prefixSum, a.Pos - a.K, a.Pos - 1);
    result += GetSum(prefixSum, n - a.K, n - 1);
    return result;
}

inline long long GetCount(const TResult& a) {
    if (a.IsEven) {
        return 2 + 2 * a.K;
    } else {
        return 1 + 2 * a.K;
    }
}

inline long long GetMedSum(const TResult& a) {
    if (a.IsEven) {
        return x[a.Pos] + x[a.Pos + 1];
    } else {
        return x[a.Pos];
    }
}

bool IsBetter(TResult x, TResult y) {
    long long xSum = GetSum(x);
    long long ySum = GetSum(y);
    long long xCount = GetCount(x);
    long long yCount = GetCount(y);
    long long xMedSum = GetMedSum(x);
    long long yMedSum = GetMedSum(y);
    if (x.IsEven && y.IsEven) {
        long long left = xSum * 2 * yCount - xMedSum * xCount * yCount;
        long long right = ySum * 2 * xCount - yMedSum * xCount * yCount;
        return left >= right;
    } else if (!x.IsEven && !y.IsEven) {
        long long left = xSum * yCount - xMedSum * xCount * yCount;
        long long right = ySum * xCount - yMedSum * xCount * yCount;
        return left >= right;
    } else {
        bool inv = false;
        if (x.IsEven) {
            swap(x, y);
            swap(xSum, ySum);
            swap(xCount, yCount);
            swap(xMedSum, yMedSum);
            inv = true;
        }
        long long left = xSum * yCount * 2 - xMedSum * 2 * xCount * yCount;
        long long right = ySum * xCount * 2 - yMedSum * xCount * yCount;
        if (inv) {
            return right >= left;
        } else {
            return left >= right;
        }
    }
}

void Update(TResult& r, const TResult& c) {
    if (!r.Init) {
        r = c;
        return;
    }
    if (IsBetter(c, r)) {
        r = c;
    }
}

TResult result;

void FillResult(TResult& x, bool isEven, int k, int pos) {
    x.Init = true;
    x.IsEven = isEven;
    x.K = k;
    x.Pos = pos;
}

void DoTernary(bool isEven, int pos) {
    if (isEven && pos + 1 == n) {
        return;
    }

    int maxK;
    if (isEven) {
        maxK = min(pos, n - pos - 2);
    } else {
        maxK = min(pos, n - pos - 1);
    }

    int bl = 0;
    int br = maxK;
    int ba = 0;
    while (bl <= br) {
        int bm1 = bl + (br - bl) / 3;
        int bm2 = br - (br - bl) / 3;

        TResult first;
        FillResult(first, isEven, bm1, pos);

        TResult second;
        FillResult(second, isEven, bm2, pos);

        if (IsBetter(first, second)) {
            ba = bm1;
            br = bm2 - 1;
        } else {
            ba = bm2;
            bl = bm1 + 1;
        }
    }

    TResult curResult;
    FillResult(curResult, isEven, ba, pos);

    Update(result, curResult);
}

int main() {
    /*
    freopen("input.txt", "w", stdout);
    const int N = 2e5;
    cout << N << endl;
    for (int i = 0; i < N; ++i) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
    freopen("input.txt", "r", stdin);
    */
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    x.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    prefixSum.resize(n);
    prefixSum[0] = x[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + x[i];
    }

    result.Init = false;
    for (int pos = 0; pos < n; ++pos) {
        DoTernary(true, pos);
        DoTernary(false, pos);
    }

    assert(result.Init);

    vector<int> resultNums;

    resultNums.reserve(GetCount(result));
    for (int i = result.Pos - result.K; i < result.Pos; ++i) {
        resultNums.push_back(x[i]);
    }
    if (result.IsEven) {
        resultNums.push_back(x[result.Pos]);
        resultNums.push_back(x[result.Pos + 1]);
    } else {
        resultNums.push_back(x[result.Pos]);
    }
    for (int i = 0; i < result.K; ++i) {
        resultNums.push_back(x[n - result.K + i]);
    }

    cout << resultNums.size() << endl;
    for (int x : resultNums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}