#include <bits/stdc++.h>

using namespace std;

const int N = 1500 + 7;
int n;
int k;
string s[N];
map<string, int> f;
int sol;

char ft(char a, char b)
{
    if (a == b)
    {
        return a;
    }
    else
    {
        string roflan = "SET";
        for (auto &c : roflan)
        {
            if (c != a && c != b)
            {
                return c;
            }
        }
        return '!';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            string fuq;
            for (int o = 0; o < k; o++)
            {
                fuq += ft(s[i][o], s[j][o]);
            }
            sol += f[fuq];
        }
        f[s[i]]++;
    }
    cout << sol << "\n";
}