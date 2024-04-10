#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int t;
        cin>>t;
        while(t--)
        {
                ll a,b;
                cin>>a>>b;
                if(a==b+1)
                        cout<<"NO\n";
                else
                        cout<<"YES\n";
        }

        return 0;
}