#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

long long mas[(int)1e5 + 10];

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    if(k == n * m)
    {
        cout << n * m;
        return 0;
    }
    if(k == 1)
    {
        cout << "1";
        return 0;
    }
    long long l = 1;
    long long r = n * m;
    while(r - l > 1)
    {
        long long mm = (l + r) / 2;
        long long ans = 0;
        for(long long i = 1; i <= n; i++)
        {
            long long j = mm / i;
            ans += min(j, m);
        }
        if(ans < k)
            l = mm;
        else
            r = mm;
    }
    cout << r;

    return 0;
}