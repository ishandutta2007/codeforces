#include <bits/stdc++.h>

using namespace std;

int used[(int)1e5 + 10];
int mas[(int)1e5 + 10];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> mas[i];
        used[i] = 0;
    }
    int q = 0;
    while (q >= 0 && q < n)
    {
        if (used[q] == 1)
        {
            cout << "INFINITE" << endl;
            return 0;
        }
        used[q] = 1;
        if (s[q] == '>')
            q += mas[q];
        else
            q -= mas[q];
    }
    cout << "FINITE" << endl;
    return 0;
}