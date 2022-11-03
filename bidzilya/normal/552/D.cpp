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

int GetVMult(const Point& a, const Point& b)
{
    return a.x * b.y - a.y * b.x;
}

int GetLength2(const Point& a)
{
    return a.x * a.x + a.y * a.y;
}

Point operator - (const Point& a, const Point& b)
{
    return Point(a.x - b.x, a.y - b.y);
}

bool PointCmp(const Point& a, const Point& b)
{
    return GetVMult(a, b) > 0 || GetVMult(a, b) == 0 && GetLength2(a) < GetLength2(b);
}

int GetC3(int n)
{
    return 1LL * n * (n - 1) * (n - 2) / 6;
}

int GetC2(int n)
{
    return n * (n - 1) / 2;
}

istream& operator >> (istream& input_stream, Point& point)
{
    input_stream >> point.x >> point.y;
    return input_stream;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int, int> with_x_coord;
    for (int i = 0; i < n; ++i) {
        ++with_x_coord[a[i].x];
    }

    int ans = GetC3(n);
    for (const auto& itr: with_x_coord) {
        ans -= GetC3(itr.second);
    }

    for (int start_index = 0; start_index < n; ++start_index) {
        vector<Point> b;
        for (int i = 0; i < n; ++i) {
            if (a[i].x > a[start_index].x) {
                b.push_back(a[i] - a[start_index]);
            }
        }

        sort(b.begin(), b.end(), PointCmp);

        for (int i = 0; i < (int) b.size(); ) {
            int j = i;
            while (j + 1 < (int) b.size() && GetVMult(b[i], b[j + 1]) == 0) {
                ++j;
            }

            ans -= GetC2(j - i + 1);

            i = j + 1;
        }
    }

    cout << ans << endl;

    return 0;
}