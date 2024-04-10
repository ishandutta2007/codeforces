#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

string s;
int ph[1000005][3], sp[1000005][3], m[3], n;

int add(int x, int y, int m)
{
    return (x + y) % m;
}

int sub(int x, int y, int m)
{
    return add(x, m - y, m);
}

int mul(int x, int y, int m)
{
    return x * y % m;
}

int binpow(int x, int y, int m)
{
    if(y == 0)
        return 1;

    if(y % 2)
        return mul(x, binpow(x, y - 1, m), m);

    int z = binpow(x, y / 2, m);

    return mul(z, z, m);
}

int get(int x, int y, int i)
{
    return sub(ph[x + y][i], mul(ph[x][i], sp[y][i], m[i]), m[i]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();

    m[0] = 1e9 + 7, m[1] = 1e9 + 9, m[2] = 2147483647;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
        {
            ph[i + 1][j] = add(mul(ph[i][j], 10, m[j]), s[i] - '0', m[j]);
        }

    sp[0][0] = 1, sp[0][1] = 1, sp[0][2] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 3; j++)
            sp[i][j] = mul(sp[i - 1][j], 10, m[j]);

    for(int i = 1; i <= n / 2; i++)
    {
        int b = n - i;

        for(int z = 0; z < 4; z++)
        {
            int x, y;

            if(z == 0)
                x = b / 2;

            if(z == 1)
                x = b / 2 - 1;

            if(z == 2)
                x = b - i;

            if(z == 3)
                x = b - i - 1;

            y = b - x;

            if(i > 0 && x > 0 && y > 0 && (i == 1 || s[0] != '0') && (x == 1 || s[i] != '0') && (y == 1 || s[i + x] != '0'))
            {
                int f = 1;

                for(int j = 0; j < 3; j++)
                {
                    if(add(get(0, i, j), get(i, x, j), m[j]) != get(i + x, y, j))
                        f = 0;
                }

//                if(i == 9 && x == 9 && y == 9)
//                    cout << get(0, i, 2) << ' ' << get(i, x, 2) << ' ' << get(i + x, y, 2) << endl;

                if(f)
                {
                    cout << s.substr(0, i) << "+" << s.substr(i, x) << "=" << s.substr(i + x, y);
                    return 0;
                }
            }
        }


    }
}