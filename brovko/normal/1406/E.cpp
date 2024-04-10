#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 goerohgerigegoihr
#define y0 peowjfefwepojfewe

using namespace std;

int n, np[100005], used[100005], in[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 2; i * i <= n; i++)
        if(np[i] == 0)
            for(int j = i * i; j <= n; j += i)
                np[j] = 1;

    int N = 1000;
    int K = n;
    int F = 0;

    vector <int> v;

    for(int i = n; i >= 2; i--)
    {
        if(np[i] == 0)
        {
            cout << "B " << i << endl;
            int k;
            cin >> k;

            for(int j = i; j <= n; j += i)
            {
                if(used[j] == 0)
                {
                    k--;
                    used[j] = 1;
                    K--;
                }
            }

            if(k != 0 && in[i] == 0)
            {
                v.push_back(i);
                in[i] = 1;
            }
        }

        if((i % N == 0 || i == 2) && F == 0)
        {
            cout << "A " << 1 << endl;
            int k;
            cin >> k;

            if(k != K)
            {
                for(int j = max(i, 2ll); j <= min(n, i + N); j++)
                    if(np[j] == 0)
                {
                    cout << "A " << j << endl;
                    int k;
                    cin >> k;

                    if(k > 0 && in[j] == 0)
                    {
                        v.push_back(j);
                        in[j] = 1;
                        F = 1;
                    }
                }
            }
        }
    }

    int ans = 1;

    for(auto to:v)
    {
        ans *= to;

        int x = to * to;
        int f = 1;

        while(f == 1 && x <= n)
        {
            cout << "A " << x << endl;
            int k;
            cin >> k;

            if(k == 0)
                f = 0;

            x *= to;
            if(f)
                ans *= to;
        }
    }

    cout << "C " << ans;
}