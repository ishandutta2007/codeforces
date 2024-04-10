#include <bits/stdc++.h>
#define android ios

using namespace std;

struct point
{
    long long x, y;
    point(long long x_ = 0, long long y_ = 0): x(x_), y(y_) {};
    point operator -(const point a)const
    {
        return point(x - a.x, y - a.y);
    }
    double len()
    {
        return sqrt(x * x + y * y);
    }
};

struct line
{
    long long a, b, c;
    line(): a(0), b(0), c(0) {};
    line(point q, point w)
    {
        a = q.y - w.y;
        b = w.x - q.x;
        c = -q.x * a - q.y * b;
    }
    double dist(point q)
    {
        return (a * q.x + b * q.y + c) / sqrt(a * a + b * b);
    }
};

point mas[1010];

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> mas[i].x >> mas[i].y;
    mas[n] = mas[0];
    mas[n + 1] = mas[1];
    double ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        line l = line(mas[i - 1], mas[i + 1]);
        ans = min(ans, abs(l.dist(mas[i]) / 2));
        //cout << i << " " << abs(l.dist(mas[i])) << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = min(ans, (mas[i] - mas[j]).len() / 2);
            //cout << i << " " << j << " " << (mas[i] - mas[j]).len() << endl;
        }
    }
    cout.precision(20);
    cout << ans << endl;
    return 0;
}