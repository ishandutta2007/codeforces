#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
#include<map>

using namespace std;

int n;
int ans;

string s1[201], s2[201];

void dfs(string s, int v)
{
    ans = max(ans, v);
    for (int i = 0; i < n; i++)
    {
        if (s2[i] == s)
        {
            dfs(s1[i], v + 1);
        }
    }
}

int main()
{
    ans = 1;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s1[i] >> s >> s2[i];
        for (int j = 0; j < s1[i].size(); j++)
        {
            if ('A' <= s1[i][j] && s1[i][j] <= 'Z')
            {
                s1[i][j] += 'a' - 'A';
            }
        }
        for (int j = 0; j < s2[i].size(); j++)
        {
            if ('A'<= s2[i][j] && s2[i][j] <= 'Z')
            {
                s2[i][j] += 'a' - 'A';
            }
        }
    }
    dfs("polycarp", 1);
    cout << ans;
}