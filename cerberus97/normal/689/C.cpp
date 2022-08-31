#include <iostream>
#include <cmath>

using namespace std;

double oneThird = 1.0/3.0;
long long cb[1000005];

void pre()
{
    for (long long i = 0; i < 1000005; ++i)
        cb[i] = i*i*i;
}

inline long long getAns(long long n)
{
    long long ans = 0, sm = floor(pow(n, oneThird) + 1e-6);

    for (long long k = 2; k <= sm; ++k)
    {
        ans += floor(n/(cb[k]));
    }

    return ans;
}

long long binSearch(long long m, long long l, long long r)
{
    long long mid, ans;

    while (l < r)
    {
        mid = (l + r)/2;
        ans = getAns(mid);

        if (ans < m)
            l = mid + 1;

        else
            r = mid;
    }

    if (l > r)
        return -1;

    if (getAns(l) == m)
        return l;

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    pre();

    long long m;

    cin >> m;
    cout << binSearch(m, 1, 5e15) << '\n';

    return 0;
}