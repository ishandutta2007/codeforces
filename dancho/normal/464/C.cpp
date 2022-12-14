#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

long long mod = 1000000007;

long long qpow(long long v, long long st)
{
    long long r = 1;
    while (st)
    {
        if (st & 1)
        {
            r *= v;
            if (r >= mod)
                r %= mod;
        }
        v = v * v;
        if (v >= mod)
            v %= mod;
        st /= 2;
    }
    return r;
}

char beg[1 << 18];
int n;

char d[1 << 18];
string t[1 << 18];

char b0[8], buf[1 << 18];

long long rem[16], len[16];

int main()
{
    scanf("%s", beg);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", buf);
        d[i] = buf[0];
        t[i] = buf + 3;
    }

    for (int i = 0; i < 10; ++i)
    {
        rem[i] = i;
        len[i] = 1;
    }

    for (int i = n - 1; i >= 0; --i)
    {
        long long nrem = 0;
        long long nlen = 0;
        int sz = t[i].size();
        for (int j = 0; j < sz; ++j)
        {
            nrem = nrem * qpow(10, len[t[i][j] - '0']) + rem[t[i][j] - '0'];
            nlen += len[t[i][j] - '0'];
            if (nrem >= mod)
                nrem %= mod;
            if (nlen >= mod - 1)
                nlen %= (mod - 1);
        }
        rem[d[i] - '0'] = nrem;
        len[d[i] - '0'] = nlen;
    }

    int sz = strlen(beg);
    long long nrem = 0;
    for (int i = 0; i < sz; ++i)
    {
        nrem = nrem * qpow(10, len[beg[i] - '0']) + rem[beg[i] - '0'];
        if (nrem >= mod)
            nrem %= mod;
    }

    printf("%lld\n", nrem);

    return 0;
}