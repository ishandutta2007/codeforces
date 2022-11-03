#include <iostream>
#include <vector>
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

Point operator - (const Point& a, const Point& b)
{
    return Point(a.x - b.x, a.y - b.y);
}

istream& operator >> (istream& input_stream, Point& p)
{
    input_stream >> p.x >> p.y;
    return input_stream;
}

int VMult(const Point& p1, const Point& p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}

int SMult(const Point& p1, const Point& p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}

bool IsInOneLine(const Point& a, const Point& b, const Point& c)
{
    return VMult(c - a, b - a) == 0;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    Point s;
    cin >> s;
    vector<Point> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> used(n, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            used[i] = 1;
            ++ans;
            for (int j = i + 1; j < n; ++j) {
                if (!used[j] && IsInOneLine(s, a[i], a[j])) {
                    used[j] = 1;
                }
            }
        }
    }

    cout << ans << endl;


    return 0;
}