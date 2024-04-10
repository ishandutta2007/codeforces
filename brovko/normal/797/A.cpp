#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k;
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    
    if(k == 1)
    {
        cout << n;
        return 0;
    }
    
    for(int i = 2; i <= n; i++)
    {
        while(n % i == 0)
        {
            n /= i;
            v.push_back(i);

            if(n > 1 && v.size() == k - 1)
            {
                for(auto to:v)
                    cout << to << ' ';
                cout << n;

                return 0;
            }
        }
    }

    cout << -1;
}