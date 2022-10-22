#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int a, k[100005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> s;
    int n = s.size();

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;

        for(int j = i; j < n; j++)
        {
            sum += s[j] - '0';
            k[sum]++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        int sum = 0;

        for(int j = i; j < n; j++)
        {
            sum += s[j] - '0';

            if(sum == 0)
            {
                if(a == 0)
                    ans += n * (n + 1) / 2;

                continue;
            }

            if(a % sum == 0)
            {
                int b = a / sum;

                if(b < 100005)
                    ans += k[b];
            }
        }
    }

    cout << ans;
}