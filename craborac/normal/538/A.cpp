#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    string t = "CODEFORCES";
    int m = t.size();
    if (n >= m)
    {
        int l = 0;
        while (l < m && s[l] == t[l])
        {
            l++;
        }
        int r = 0;
        while (r < m && t[m - 1 - r] == s[n - 1 - r])
        {
            r++;
        }
        if (l + r >= m)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
        return 0;
    }
}