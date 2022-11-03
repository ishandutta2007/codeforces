#include <iostream>
#include <vector>
using namespace std;

const int kDefaultSize = 100;
const int kModulus = 1e9 + 7;

struct Matr
{
    explicit Matr(int size = 2) :
        size(size)
    {
        data.resize(size, vector<int>(size, 0));
    }
    int size;
    vector<vector<int> > data;
};

Matr GetEd(int size)
{
    Matr r(size);
    for (int i = 0; i < size; ++i) {
        r.data[i][i] = 1;
    }
    return r;
}

Matr operator * (const Matr& a, const Matr& b)
{
    int size = a.size;
    Matr c(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            c.data[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                c.data[i][j] += (1LL * a.data[i][k] * b.data[k][j]) % kModulus;
                if (c.data[i][j] >= kModulus) {
                    c.data[i][j] -= kModulus;
                }
            }
        }
    }
    return c;
}

Matr operator ^ (const Matr& a, int pw)
{
    if (pw == 0) {
        return GetEd(a.size);
    }
    if ((pw & 1) == 1) {
        return a * (a ^ (pw - 1));
    }
    return (a * a) ^ (pw >> 1);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    vector<int> t(kDefaultSize);
    t[0] = 1;
    for (int i = 1; i < kDefaultSize; ++i) {
        t[i] = 1;
        for (int j = 0; j < n; ++j) {
            if (i - d[j] >= 0) {
                t[i] += t[i - d[j]];
                if (t[i] >= kModulus) {
                    t[i] -= kModulus;
                }
            }
        }
    }

    if (x < kDefaultSize) {
        cout << t[x] << endl;
        return 0;
    }

    Matr m(kDefaultSize + 1);
    for (int j = 0; j + 1 < kDefaultSize; ++j) {
        m.data[j + 1][j] = 1;
    }

    for (int i = 0; i < n; ++i) {
        ++m.data[kDefaultSize - d[i]][kDefaultSize - 1];
    }

    m.data[kDefaultSize][kDefaultSize - 1] = 1;
    m.data[kDefaultSize][kDefaultSize] = 1;

    m = m ^ (x - kDefaultSize + 1);

    int ans = 0;
    for (int i = 0; i < kDefaultSize; ++i) {
        ans += (1LL * t[i] * m.data[i][kDefaultSize - 1]) % kModulus;
        if (ans >= kModulus) {
            ans -= kModulus;
        }
    }

    ans += m.data[kDefaultSize][kDefaultSize - 1];
    if (ans >= kModulus) {
        ans -= kModulus;
    }

    cout << ans << endl;

    return 0;
}