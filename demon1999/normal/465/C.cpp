#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    long k = -1, p, n, i, ok, j;
    char c[2000], s[2000];
    cin >> n >> p;
    for(i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for(i = n - 1; i >= 0; i --)
    {
        ok = 0;
        j = c[i] - 95;
        while(j <= p)
        {
            if((i - 1 < 0 || (int)c[i - 1] - 96 != j)&&(i - 2 < 0 || (int)c[i - 2] - 96 != j))
            {
                ok = 1;
                break;
            }
            j ++;
        }
        if(ok == 0)
        {
            continue;
        }
        s[i] = j + 96;
        ok = 0;
        if(i - 1 > -1) s[i - 1] = c[i - 1];
        j = i + 1;
        for(int o = i + 1; o < n; o ++)
        {
            if((o == 1 || s[o - 2] != 'a') && s[o - 1] != 'a')
            {
                s[o] ='a';
                continue;
            }
            if((o == 1 || s[o - 2] != 'b') && s[o - 1] != 'b' && 2 <= p)
            {
                s[o] ='b';
                continue;
            }
            if((o == 1 || s[o - 2] != 'c') && s[o - 1] != 'c' && 3 <= p)
            {
                s[o] ='c';
                continue;
            }
            ok = 1; break;
        }
        if(ok == 0)
        {
            for(long o = 0; o < i; o++)cout << c[o];
            for(long o = i; o < n; o++)cout << s[o];
            return 0;
        }
    }
    cout << "NO";
    return 0;
}