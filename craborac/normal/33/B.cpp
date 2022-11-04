#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
//#include<set>
//#include<utility>
//#include<vector>

using namespace std;

int d1[30][30], d2[30][30];

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    if(n != s2.size())
    {
        cout << "-1";
        return 0;
    }
    int m;
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            if(i != j)
            {
                d1[i][j] = (int)1e5;
                d2[i][j] = d1[i][j];
            }
            else
            {
                d1[i][j] = 0;
                d2[i][j] = 0;
            }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        char a, b;
        int c;
        cin >> a >> b >> c;
        d1[a - 'a'][b - 'a'] = min(c, d1[a - 'a'][b - 'a']);
        d2[b - 'a'][a - 'a'] = min(c, d2[b - 'a'][a - 'a']);
    }
    for(int k = 0; k < 30; k++)
    {
        for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < 30; j++)
            {
                d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
                d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
            }
        }
    }
    long long answer = 0;
    string ans = "";
    for(int i = 0; i < n; i++)
    {
        int min = (int)1e5;
        int min_ind = 0;
        for(int j = 0; j < 26; j++)
        {
            if(d1[s1[i] - 'a'][j] + d2[j][s2[i] - 'a'] < min)
            {
                min = d1[s1[i] - 'a'][j] + d2[j][s2[i] - 'a'];
                min_ind = j;
            }
        }
        if(min == (int)1e5)
        {
            cout << "-1";
            return 0;
        }
        answer += (long long)min;
        char qwe = 'a' + min_ind;
        ans += qwe;
    }
    cout << answer << "\n";
    cout << ans;
    return 0;
}