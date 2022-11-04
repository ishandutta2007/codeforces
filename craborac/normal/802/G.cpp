#include <bits/stdc++.h>
#define android ios

using namespace std;

int mas[1001][6];

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s, t = "heidi";
    cin >> s;
    int n = s.size();
    for (int i = 0; i <= n; i++)
    {
        fill(mas[i], mas[i] + 6, 0);
        mas[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (mas[i - 1][j])
                mas[i][j] = 1;
            if (mas[i - 1][j - 1] && s[i - 1] == t[j - 1])
            {
                mas[i][j] = 1;
                if (j == 5)
                {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}