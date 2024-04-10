#include <bits/stdc++.h>

using namespace std;

string mas[1010];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mas[i];
    }
    int ans = 6;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int q = 0;
            for (int w = 0; w < 6; w++)
                if (mas[i][w] != mas[j][w])
                    q++;
            ans = min(ans, (q - 1) / 2);
        }
    }
    cout << ans << endl;
    return 0;
}