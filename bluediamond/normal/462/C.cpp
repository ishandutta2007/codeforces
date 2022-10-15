#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int n;
        cin>>n;
        vector<ll>a(n);
        for(int i=0;i<n;i++)
                cin>>a[i];
        sort(a.rbegin(),a.rend());
        ll r=0;
        ll m=n;
        for(int i=0;i<n;i++)
        {
                r+=a[i]*m;
                if(i)
                        m--;
        }
        cout<<r<<"\n";

        return 0;
}