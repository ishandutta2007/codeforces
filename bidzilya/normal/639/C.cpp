#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int BASE = 2;

struct TBigInt {
public:
    TBigInt(int n, long long val)
        : Base(n, val)
        , Neg(false)
    {
    }

    int GetSize() const {
        return Base.size();
    }

    long long& operator [] (int n) {
        return Base[n];
    }

    const long long operator [] (int n) const {
        return Base[n];
    }

    bool IsNeg() const {
        return Neg;
    }

    long long& GetBack() {
        return Base.back();
    }

    void PopBack() {
        Base.pop_back();
    }

    void PushBack(long long val) {
        Base.push_back(val);
    }

    void PopFront() {
        Base.pop_front();
    }

    long long& GetFront() {
        return Base.front();
    }

    const deque<long long>& GetBase() const {
        return Base;
    }

    void SetNeg(bool neg) {
        Neg = neg;
    }

private:
    deque<long long> Base;
    bool Neg;
};

ostream& operator << (ostream& outputStream, const TBigInt& bigInt) {
    if (bigInt.IsNeg()) {
        outputStream << '-';
    }
    for (int i = bigInt.GetSize() - 1; i >= 0; --i) {
        outputStream << bigInt[i];
    }
    return outputStream;
}

void Normalize(TBigInt& a) {
    long long buf = 0;
    for (int i = 0; i < a.GetSize(); ++i) {
        a[i] += buf;
        buf = (a[i] / BASE);
        a[i] %= BASE;
        if (a[i] < 0) {
            a[i] += BASE;
            --buf;
        }
    }
    if (buf < 0) {
        a.PushBack(buf);
        for (int i = 0; i < a.GetSize(); ++i) {
            a[i] *= -1;
        }
        Normalize(a);
        a.SetNeg(true);
    } else {
        a.SetNeg(false);
        while (buf > 0) {
            a.PushBack(buf % BASE);
            buf /= BASE;
        }
        while (a.GetBack() == 0 && a.GetSize() > 1) {
            a.PopBack();
        }
    }
}

int Compare(const deque<long long>& lhs, const deque<long long>& rhs) {
    if (lhs.size() < rhs.size()) {
        return -1;
    }
    if (lhs.size() > rhs.size()) {
        return 1;
    }
    for (int i = lhs.size() - 1; i >= 0; --i) {
        if (lhs[i] > rhs[i]) {
            return 1;
        }
        if (lhs[i] < rhs[i]) {
            return -1;
        }
    }
    return 0;
}

int Compare(const TBigInt& lhs, const TBigInt& rhs) {
    if (lhs.IsNeg() && !rhs.IsNeg()) {
        return -1;
    }
    if (!lhs.IsNeg() && rhs.IsNeg()) {
        return +1;
    }
    if (lhs.IsNeg() && rhs.IsNeg()) {
        return -Compare(lhs.GetBase(), rhs.GetBase());
    } else {
        return Compare(lhs.GetBase(), rhs.GetBase());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }

    TBigInt sum(n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        sum[i] += a[i];
    }
    Normalize(sum);

    long long result = 0;
    {
        TBigInt temp(n + 1, 0);
        temp[n] = a[n];
        Normalize(temp);

        if (Compare(temp, sum) == 0) {
            --result;
        }
    }

    for (int i = 0; i <= n; ++i) {
        long long l = -k - a[i];
        long long r = k - a[i];

        TBigInt lBig(1, 0);
        lBig[0] = -l;
        Normalize(lBig);

        TBigInt rBig(1, 0);
        rBig[0] = -r;
        Normalize(rBig);

        if (Compare(sum, lBig) <= 0 && Compare(sum, rBig) >= 0) {
            ++result;
        }

        if (sum.GetSize() == 1 || sum.GetFront() != 0) {
            break;
        }
        sum.PopFront();
    }

    cout << result << endl;

    return 0;
}