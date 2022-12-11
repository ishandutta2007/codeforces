#include <iostream>
#include <vector>

using namespace std;

long long mod = 1e9 + 7;

int main()
{
    long long n, k, i, a, b, st, ans, cnt, ost;
    cin >> n >> k;
    st = 1;
    for (i = 0; i < k; i++)
        st *= 10;
    ans = 1;
    vector<long long> a1(n/k), b1(n/k);
    for (i = 0; i < n / k; i++)
    {
        cin >> a1[i];
    }
    for (i = 0; i < n / k; i++)
    {
        cin >> b1[i];
    }
    for (i = 0; i < n / k; i++)
    {
        a = a1[i];
        b = b1[i];
        cnt = (st - 1) / a + 1;
        if (k == 1)
        {
            if (b % a == 0) cnt -= 1;
        }
        else
        {
            ost = (b * (st / 10)) % a;
            if (ost != 0)
            {
                ost = a - ost;
            }
            ost = (st / 10 - ost - 1);
            if (ost >= 0)
                cnt -= ost / a + 1;
        }
        //cout << ost << ' ' << cnt << endl;
        ans = (ans * cnt) % mod;
    }
    cout << ans;
    return 0;
}