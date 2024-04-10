#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int l, m[333];
char s[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    gets(s);
    l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        int x = s[i];
        if (x > 0)  m[x]++;
    }
    for (int i = '1'; i <= '3'; i++)
    {
        //cout << i << endl;
        if (m[i] != 0 && m[i - 1] > 0 || m[i - 2] > 0 && m[i] != 0) cout << "+";
        for (int j = 1; j < m[i]; j++)
            cout << i - '0' << "+";
        if (m[i] != 0) cout << i - '0';
    }
    return 0;
}