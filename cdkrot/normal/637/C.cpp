#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int mn = 6;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int k = 0;
            for (int t = 0; t < 6; t++)
                if (s[i][t] != s[j][t])
                    k++;
            mn = min(mn, (k + 1) / 2 - 1);
        }
    cout << mn << endl;
    return 0;
}