#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b)
{
    return (int) a.size() < (int) b.size();
}

int f[26];

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "? 1 1" << endl;
        string s;
        cin >> s;
        cout << "! " << s << endl;
        return 0;
    }
    map<string, int> mp;
    cout << "? " << 1 << " " << n << endl;
    for (int i = 1; i <= n * (n + 1) / 2; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;
    }
    cout << "? " << 2 << " " << n << endl;
    for (int i = 1; i <= n * (n - 1) / 2; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]--;
    }
    vector<string> a;
    for (auto &it : mp)
    {
        if (it.second)
        {
            a.push_back(it.first);
        }
    }
    sort(a.begin(), a.end(), cmp);
    cout << "! ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            f[j] = 0;
        }
        for (auto &x : a[i])
        {
            f[x - 'a']++;
        }
        if (i)
        {
            for (auto &x : a[i - 1])
            {
                f[x - 'a']--;
            }
        }
        for (int j = 0; j < 26; j++)
        {
            if (f[j])
            {
                cout << (char) (j + 'a');
            }
        }
    }
    cout << endl;
}