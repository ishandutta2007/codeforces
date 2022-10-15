#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if(k>=1000000)
    {
        cout<<"-1\n";
        return 0;
    }
    ll lol=k*(k+1)/2;
    vector<ll>divi;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            divi.push_back(i);
            if(i*i!=n)
            {
                divi.push_back(n/i);
            }
        }
    }
    sort(divi.rbegin(),divi.rend());
    for(auto &gcd:divi)
    {
        ll mi=gcd*lol;
        if(mi%gcd!=0 || mi/gcd!=lol)
        {
            continue;
        }
        if(mi>n)
        {
            continue;
        }
        for(ll i=1;i<k;i++)
        {
            cout<<i*gcd<<" ";
            n-=i*gcd;
        }
        cout<<n<<"\n";
        return 0;
    }
    cout<<"-1\n";
    return 0;
}
/**

**/