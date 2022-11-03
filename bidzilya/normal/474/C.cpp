#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
    
    Point() :
        x(0),
        y(0)
    {
    }
    
    Point(int x, int y) :
        x(x),
        y(y)
    {
    }
};

Point operator + (const Point& lhs, const Point& rhs)
{
    return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

Point operator - (const Point& lhs, const Point& rhs)
{
    return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

bool operator == (const Point& lhs, const Point& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

int VMult(const Point& a, const Point& b)
{
    return a.x * b.y - a.y * b.x;
}

int SMult(const Point& a, const Point& b)
{
    return a.x * b.x + a.y * b.y;
}

bool IsOrthogonal(const Point& a, const Point& b)
{
    return SMult(a, b) == 0;
}

istream& operator >> (istream& input_stream, Point& point)
{
    input_stream >> point.x >> point.y;
    return input_stream;
}

Point Rotate90Degree(const Point& point)
{
    return Point(-point.y, point.x);
}

Point Rotate(const Point& point, const Point& start)
{
    return start + Rotate90Degree(point - start);
}

Point Rotate(const Point& point, const Point& start, int num)
{
    if (num >= 4) {
        num %= 4;
    }
    Point res = point;
    for (int i = 0; i < num; ++i) {
        res = Rotate(res, start);
    }
    return res;
}

int GetDistance2(const Point& a, const Point& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int ModuloValue(int x, int mod)
{
    if (x == mod) {
        x = 0;
    }
    return x;
}

bool IsLieInOneSquare(const vector<Point>& to_check)
{
    if (to_check[0] == to_check[1]) {
        return false;
    }
    vector<int> order(4);
    for (int i = 0; i < 4; ++i) {
        order[i] = i;
    }
    vector<Point> points(4);
    do {
        for (int i = 0; i < 4; ++i) {
            points[i] = to_check[order[i]];
        }
        bool good = true;
        int dist2 = GetDistance2(points[3], points[0]);
        for (int i = 1; i < 4; ++i) {
            if (GetDistance2(points[i], points[i - 1]) != dist2) {
                good = false;
                break;
            }
        }
        for (int i = 0; i < 4; ++i) {
            int j = ModuloValue(i + 1, 4);
            int k = ModuloValue(j + 1, 4);
            if (!IsOrthogonal(points[j] - points[i], points[k] - points[j])) {
                good = false;
                break;
            }
            if (VMult(points[j] - points[i], points[k] - points[j]) > 0) {
                good = false;
                break;
            }
        }
        if (good) {
            return true;
        }
    } while (next_permutation(order.begin(), order.end()));
    return false;
}

inline int GetBit(int mask, int num)
{
    return (mask >> num) & 1;
}

const int kInf = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<Point> pos(4), start(4), cur(4);
    vector<int> s(4);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> pos[j] >> start[j];
        }
        int ans = kInf;
        for (int mask = 0; mask < (1 << 8); ++mask) {
            for (int j = 0; j < 4; ++j) {
                s[j] = 2 * GetBit(mask, 2 * j) + GetBit(mask, 2 * j + 1);
            }
            for (int j = 0; j < 4; ++j) {
                cur[j] = Rotate(pos[j], start[j], s[j]);
            }
            if (IsLieInOneSquare(cur)) {
                int cur_ans = 0;
                for (int j = 0; j < 4; ++j) {
                    cur_ans += s[j];
                }
                ans = min(ans, cur_ans);
            }
        }
        if (ans == kInf) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    
    return 0;
}