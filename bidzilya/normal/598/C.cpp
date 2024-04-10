#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

using BigInt = vector<int>;

bool operator < (const BigInt& lhs, const BigInt& rhs)
{
    if (lhs.size() < rhs.size()) {
        return true;
    }
    if (lhs.size() > rhs.size()) {
        return false;
    }
    for (int i = (int) lhs.size() - 1; i >= 0; --i) {
        if (lhs[i] > rhs[i]) {
            return false;
        }
        if (lhs[i] < rhs[i]) {
            return true;
        }
    }
    return false;
}

bool operator == (const BigInt& lhs, const BigInt& rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (int i = 0; i < (int) lhs.size(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

bool operator != (const BigInt& lhs, const BigInt& rhs)
{
    return !(lhs == rhs);
}

bool operator > (const BigInt& lhs, const BigInt& rhs)
{
    return !(lhs < rhs || lhs == rhs);
}

BigInt operator + (const BigInt& lhs, const BigInt& rhs)
{
    int n = lhs.size();
    int m = rhs.size();
    int t = 0;
    BigInt r(max(n, m));
    for (int i = 0; i < max(n, m); ++i) {
        if (i < n) {
            t += lhs[i];
        }
        if (i < m) {
            t += rhs[i];
        }
        r[i] = t % 10;
        t /= 10;
    }
    while (t > 0) {
        r.push_back(t % 10);
        t /= 10;
    }
    return r;
}

BigInt operator * (const BigInt& lhs, const BigInt& rhs)
{
    int n = lhs.size();
    int m = rhs.size();
    BigInt r(n + m, 0);
    for (int i = 0; i < n; ++i) {
        long long t = 0;
        for (int j = 0; j < m; ++j) {
            t += 1LL * lhs[i] * rhs[j];
            t += r[i + j];
            r[i + j] = t % 10;
            t /= 10;
        }
        int index = i + m;
        while (t > 0) {
            if (index == r.size()) {
                r.push_back(0);
            }
            t += r[index];
            r[index] = t % 10;
            t /= 10;
            ++index;
        }
    }
    while (r.size() > 1 && r.back() == 0) {
        r.pop_back();
    }
    return r;
}

BigInt Init(long long t)
{
    BigInt r;
    while (t > 0) {
        r.push_back(t % 10);
        t /= 10;
    }
    return r;
}

ostream& operator << (ostream& outputStream, const BigInt& rhs)
{
    for (int i = (int) rhs.size() - 1; i >= 0; --i) {
        outputStream << rhs[i];
    }
    return outputStream;
}

struct Point
{
    long long x;
    long long y;

    int index;

    Point()
        : x(0)
        , y(0)
        , index(-1)
    {
    }

    Point(long long x, long long y, int index)
        : x(x)
        , y(y)
        , index(index)
    {
    }
};

istream& operator >> (istream& inputStream, Point& point)
{
    inputStream >> point.x >> point.y;
    return inputStream;
}

inline long long GetVMult(const Point& lhs, const Point& rhs)
{
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

inline long long GetSMult(const Point& lhs, const Point& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

bool operator < (const Point& lhs, const Point& rhs)
{
    if (lhs.y > 0) {
        if (rhs.y < 0) {
            return true;
        }
        if (rhs.y == 0 && rhs.x > 0) {
            return false;
        }
        if (rhs.y == 0 && rhs.x < 0) {
            return true;
        }
        if (rhs.y > 0) {
            return GetVMult(lhs, rhs) > 0;
        }
    }
    if (lhs.y < 0) {
        if (rhs.y > 0) {
            return false;
        }
        if (rhs.y == 0) {
            return false;
        }
        if (rhs.y < 0) {
            return GetVMult(lhs, rhs) > 0;
        }
    }
    if (lhs.y == 0) {
        if (lhs.x > 0) {
            return true;
        }
        if (rhs.y < 0) {
            return true;
        }
        if (rhs.y > 0) {
            return false;
        }
        if (rhs.y == 0) {
            return false;
        }
    }
    assert(false);
}

using Answer = pair<Point, Point>;

bool operator < (const Answer& lhs, const Answer& rhs)
{
    long long lhsSMult = GetSMult(lhs.first, lhs.second);
    BigInt lhsSMult2 = Init(lhsSMult * lhsSMult);

    long long rhsSMult = GetSMult(rhs.first, rhs.second);
    BigInt rhsSMult2 = Init(rhsSMult * rhsSMult);

    BigInt lhsLen = Init(GetSMult(lhs.first, lhs.first) * GetSMult(lhs.second, lhs.second));

    BigInt rhsLen = Init(GetSMult(rhs.first, rhs.first) * GetSMult(rhs.second, rhs.second));

    if (lhsSMult == 0) {
        if (rhsSMult == 0) {
            return false;
        }
        if (rhsSMult < 0) {
            return true;
        }
        if (rhsSMult > 0) {
            return false;
        }
    }

    if (lhsSMult > 0) {
        if (rhsSMult > 0) {
            return lhsSMult2 * rhsLen > rhsSMult2 * lhsLen;
        }
        if (rhsSMult < 0) {
            return true;
        }
        if (rhsSMult == 0) {
            return true;
        }
    }

    if (lhsSMult < 0) {
        if (rhsSMult > 0) {
            return false;
        }
        if (rhsSMult == 0) {
            return false;
        }
        if (rhsSMult < 0) {
            return lhsSMult2 * rhsLen < rhsSMult2 * lhsLen;
        }
    }
}

void Update(Answer& ans, const Answer& compAns)
{
    if (compAns < ans) {
        ans = compAns;
    }
}

ostream& operator << (ostream& outputStream, const Point& point)
{
    outputStream << "(" << point.x << " " << point.y << ")";
    return outputStream;
}

int main()
{
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
        points[i].index = i;
    }
    sort(points.begin(), points.end());

#ifdef DEBUG
    cout << "Sorted points = " << endl;
    for (const Point& p : points) {
        cout << "  ";
        cout << p << endl;
    }
    cout << endl;
#endif

    Answer ans;
    ans.first = points[0];
    ans.second = points[1];
    for (int i = 1; i < n; ++i) {
        int j = i + 1;
        if (j == n) {
            j = 0;
        }
        Answer curAns;
        curAns.first = points[i];
        curAns.second = points[j];
        Update(ans, curAns);
    }

    if (ans.first.index > ans.second.index) {
        swap(ans.first, ans.second);
    }

    cout << ans.first.index + 1 << " " << ans.second.index + 1 << endl;

    return 0;
}