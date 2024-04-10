#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, a[35], ans;
vector <int> s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<(1 << (n/2));i++)
    {
        int x=0;
        int y=i;
        int z=0;
        while(y)
        {
            if(y%2==1)
                x=(x+a[z])%m;
            y/=2;
            z++;
        }
        s.push_back(x);
    }
    sort(s.begin(), s.end());

    /*for(auto x:s)
        cout << x << ' ';
    cout << endl;*/

    for(int i=0;i<(1 << (n-n/2));i++)
    {
        int x=0;
        int y=i;
        int z=n/2;
        while(y)
        {
            if(y%2==1)
                x=(x+a[z])%m;
            y/=2;
            z++;
        }
        int c=lower_bound(s.begin(), s.end(), m-x)-s.begin();
        if(c!=0)
            ans=max(ans, (s[c-1]+x)%m);
        c=lower_bound(s.begin(), s.end(), 2*m-x)-s.begin();
        if(c!=0)
            ans=max(ans, (s[c-1]+x)%m);
    }
    cout << ans;
}