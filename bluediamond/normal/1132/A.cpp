#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ll a; cin>>a; /// ((
        ll b; cin>>b; /// ()
        ll c; cin>>c; /// )(
        ll d; cin>>d; /// ))
        if(a!=d)
        {
                cout<<"0\n";
                return 0;
        }
        if(c>0 && a==0)
        {
                cout<<"0\n";
                return 0;
        }
        cout<<"1\n";
        return 0;
}