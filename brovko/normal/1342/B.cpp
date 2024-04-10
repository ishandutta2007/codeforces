#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t;
string a;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        cin >> a;
        int n=a.size();
        int k0=0;
        int k1=0;
        for(auto to:a)
            if(to=='0')
            k0=1;
            else k1=1;
        if(k0==0)
        {
            for(int i=0;i<n;i++)
                cout << 1;
            cout << "\n";
        }
        else if(k1==0)
        {
            for(int i=0;i<n;i++)
                cout << 0;
            cout << "\n";
        }
        else
        {
            for(int i=0;i<n;i++)
                cout << 10;
            cout << "\n";
        }
    }
}