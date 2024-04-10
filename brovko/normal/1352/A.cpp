#include <bits/stdc++.h>
#define int long long
#define y1 ewpojfewopfiwehfew

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        vector <int> v;
        cin >> n;
        int x=1;
        while(n)
        {
            if(n/x%10)
                v.push_back(n/x%10*x);
            n-=n/x%10*x;

            x*=10;
        }

        cout << v.size() << "\n";
        for(auto to:v)
        {
            cout << to << ' ';
        }
        cout << "\n";
    }
}