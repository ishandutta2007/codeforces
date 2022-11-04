#include <bits/stdc++.h>

using namespace std;

int ar[30], num[30];
vector<int> mas[30][5000];

int main()
{
    srand(3228);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ar[s[i] - 'a']++;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                int d = j - i;
                if (d < 0)
                    d += n;
                mas[s[i] - 'a'][d - 1].push_back(s[j] - 'a');
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        double mx = 0;
        for (int j = 0; j < n - 1; j++)
        {
            int cnt = 0;
            fill(num, num + 26, 0);
            for (int q: mas[i][j])
                num[q]++;
            for (int q = 0; q < 26; q++)
                if (num[q] == 1)
                    cnt++;
            mx = max(mx, (double)cnt / mas[i][j].size());
        }
        ans += mx * ((double)ar[i] / n);
    }
    cout.precision(20);
    cout << ans << endl;
    return 0;
}