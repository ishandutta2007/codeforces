#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

istream& operator >> (istream& input_stream, Point& point)
{
    input_stream >> point.x >> point.y;
    return input_stream;
}

struct Line
{
    int a, b, c;

    long long operator () (const Point& point) const
    {
        return 1LL * a * point.x + 1LL * b * point.y + c;
    }
};

istream& operator >> (istream& input_stream, Line& line)
{
    input_stream >> line.a >> line.b >> line.c;
    return input_stream;
}

int main()
{
    ios_base::sync_with_stdio(false);

    Point p1, p2;

    cin >> p1 >> p2;

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        Line line;
        cin >> line;

        long long l1, l2;
        l1 = line(p1);
        l2 = line(p2);

        if (l1 < 0 && l2 > 0 || l1 > 0 && l2 < 0) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}