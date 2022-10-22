#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, a[1005], used[1005];
vector <int> v;

int mex()
{
    int ans = 0;

    while(used[ans])
        ans++;

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        v.clear();

        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < 1005; i++)
            used[i] = 0;

        for(int i = 0; i < n; i++)
            used[a[i]]++;

        while(mex() < n)
        {
            int x = mex();

            used[a[x]]--;
            used[x]++;

            a[x] = x;
            v.push_back(x);
        }

        for(int i = 0; i < n; i++)
            if(a[i] > i || a[i] < i - 1)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(a[j] == i)
                {
                    int x = mex();
                    v.push_back(j);

                    used[a[j]]--;
                    used[x]++;

                    a[j] = x;
                }
            }

            int x = mex();
            v.push_back(i);

            used[a[i]]--;
            used[x]++;
            a[i] = x;
        }

        cout << v.size() << "\n";
        for(auto to:v)
            cout << to + 1 << ' ';

        cout << "\n";
    }
}