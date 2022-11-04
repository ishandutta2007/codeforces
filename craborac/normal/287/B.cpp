#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

int main()
{
    long long n,k;
    cin >> n >> k;
    if(n == 1)
    {
        cout << "0";
        return 0;
    }
    if(n > 1 + (k * (k - 1)) / 2)
    {
        cout << "-1";
        return 0;
    }
    long long l = 0;
    long long r = k - 1;
    while(r - l > 1)
    {
        long long m = (l + r) / 2;
        long long sum = 1 + ((2 * k - m - 1) * m) / 2;
        if(sum < n)
            l = m;
        else
            r = m;
    }
    cout << r;

    return 0;
}