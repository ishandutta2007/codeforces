#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    if(a > b)
        swap(a, b);

    for(int x = 1; x <= a; x++)
        for(int x2 = -b; x2 <= b; x2++)
        {
            int y = round(sqrt((ld)a * a - x * x));
            int y2 = round(sqrt((ld)b * b - x2 * x2));

            if(x != 0 && x2 != 0 && y != 0 && y2 != 0 && x != x2 && y != y2)
            {
                int A = x * x + y * y;
                int B = x2 * x2 + y2 * y2;
                int C = (x - x2) * (x - x2) + (y - y2) * (y - y2);

                vector <int> v = {A, B, C};
                sort(v.begin(), v.end());

                vector <int> u = {a * a, b * b, a * a + b * b};

                if(v == u)
                {
                    cout << "YES\n" << 0 << ' ' << 0 << "\n" << x << ' ' << y << "\n" << x2 << ' ' << y2;
                    return 0;
                }
            }
        }

    cout << "NO";
}