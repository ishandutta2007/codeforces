#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long i;
    long long cnt = 0;
    vector<long long> st;
    vector<long long> p(n + 1);
    long long sum = 0;
    for (i = 0; i < n + 1; i++)
    {
        long long a;
        cin >> a;
        p[i] = a;
        sum += a;
        if (sum % 2 == 0)
            st.push_back(0);
        else
        {
            if (sum < 0)
                st.push_back(-1), cnt++, sum++;
            else
                st.push_back(1), cnt++, sum--;
        }
//        cout << st[i] << endl;
        sum /= 2;
    }
//    cout << sum << endl;
    i = n;
    while (cnt > 0)
    {
        if (st[i] != 0)
            cnt--;
        sum *= 2;
        sum += st[i];
        i--;
        if (sum > 3 * k || sum < -3 * k)
        {
            break;
        }
    }
    i++;
    int ans = 0;
    for (i; i >= 0; i--)
    {
//        cout << i << ' ' << sum << endl;
        if (sum > 3 * k || sum < -3 * k)
            break;
        if (p[i] - sum <= k && p[i] - sum >= -k)
            if (n != i)
                ans++;
            else
                if (p[i] - sum != 0)
                ans++;
        sum *= 2;
    }
    cout << ans << endl;
    return 0;
}