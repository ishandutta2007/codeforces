#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

string s[300];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        bool d = 0;
        for (int j = 0;  j < i; j++)
            if (s[j] == s[i])
                d = 1;
        if (d)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}