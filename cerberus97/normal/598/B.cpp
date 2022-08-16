#include <iostream>

using namespace std;

void shift(char* s, int len, int k)
{
    char temp[len + 1];

    for (int i = 0, j = (len - k) % len; i < len; ++i, j = (j + 1) % len)
    {
        temp[i] = s[j];
    }

    for (int i = 0; i < len; ++i)
        s[i] = temp[i];
}

int main()
{
    int m, l, r, k;
    char s[10001];

    cin >> s >> m;

    while (m--)
    {
        cin >> l >> r >> k;
        k %= r - l + 1;
        shift(s + l - 1, r - l + 1, k);
    }

    cout << s;
}