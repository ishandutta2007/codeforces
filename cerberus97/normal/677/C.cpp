#include <iostream>

#define mod 1000000007

using namespace std;

long long ways[70] = {0};
char s[100005];

void pre()
{
    for (int i = 0; i < 64; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            ways[i & j]++;
        }
    }
}

int getNum(char s)
{
    if (isdigit(s))
        return s - '0';

    if (isupper(s))
        return s - 'A' + 10;

    if (islower(s))
        return s - 'a' + 36;

    if (s == '-')
        return 62;

    return 63;
}

int main()
{
    pre();
    long long ans = 1;

    cin >> s;

    for (int i = 0; s[i]; ++i)
    {
        ans = (ans * ways[getNum(s[i])]) % mod;
    }

    cout << ans;
}