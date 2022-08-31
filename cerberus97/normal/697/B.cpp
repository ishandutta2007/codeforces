#include <iostream>
#include <cstring>

using namespace std;

char s[200];

int findChar(char c)
{
    for (int i = 0; s[i]; ++i)
        if (s[i] == c)
            return i;

    return -1;
}

int getNum(int l, int r)
{
    int ans = 0;

    for (int i = l; i <= r; ++i)
    {
        ans = (ans * 10) + (s[i] - '0');
    }

    return ans;
}

bool findNonZero(int l, int r)
{
    for (int i = l; i <= r; ++i)
        if (s[i] != 0 and s[i] != '0')
            return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s;

    int dot = findChar('.'), e = findChar('e'), len = strlen(s);
    int b = getNum(e+1, len-1);

    for (int i = e; i <= e+5; ++i)
        s[i] = 0;

    len = e;

    int newDot = dot+b;

    for (int i = dot; i < newDot; ++i)
        s[i] = s[i+1];

    s[newDot] = '.';

    for (int i = newDot-1; s[i] == 0; --i)
        s[i] = '0';

    for (int i = 0; i < newDot; ++i)
        cout << s[i];

    if (findNonZero(newDot+1, len-1))
    {
        for (int i = newDot; i < len; ++i)
            cout << s[i];
    }

    return 0;
}