#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1111, inf = 111111111;

int f, l, r, x, n, poz, cnt, m[max_n], ans[max_n];
char s[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    gets(s);
    cin >> n;
    for (int i = 0; i < 10; i++)
    {
        if (s[i] == '1')
        {
            l = i + 1;
            r = 0;
            x = i + 1;
            poz = 1;
            cnt = 1;
            ans[1] = x;
            while (cnt < n)
            {
                f = 0;
                for (int j = 0; j < 10; j++)
                    if (s[j] == '1' && j + 1 != x)
                    {
                        if (poz == 0 && l + j + 1 > r)
                        {
                            f = 1;
                            cnt++;
                            x = j + 1;
                            l += j + 1;
                            ans[cnt] = j + 1;
                            break;
                        }
                        if (poz == 1 && l < r + j + 1)
                        {
                            f = 1;
                            cnt++;
                            x = j + 1;
                            r += j + 1;
                            ans[cnt] = j + 1;
                            break;
                        }
                    }
                if (f == 0) break;
                poz = (poz + 1) % 2;
            }
            if (cnt == n)
            {
                cout << "YES" << endl;
                for (int j = 1; j <= n; j++)
                    cout << ans[j] << ' ';
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}