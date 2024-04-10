#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll x=n;
        array<ll,2> p={0,0};
        for(ll i=2;i*i<=n;i++)
        {
            ll c=0;
            while((x%i)==0)
            {
                x/=i;
                c++;
            }
            p=max(p,{c,i});
        }
        if(x>1) p=max(p,{1,x});
        cout << p[0] << "\n";
        for(int i=0;i<p[0];i++) n/=p[1];
        for(int i=1;i<=p[0]-1;i++) cout << p[1] << " ";
        cout << n*p[1] << "\n";
    }
    return 0;
}