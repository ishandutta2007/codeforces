#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lcm(ll a,ll b)
{
    return a/__gcd(a,b)*b;
}
int main()
{
    //freopen("data.in","r",stdin);
    ll a,b;
    cin>>a>>b;
    ll x=abs(a-b);
    if(a==b) cout<<0<<endl;
    else
    {
        ll ans=0x3f3f3f3f3f3f3f3f;
        ll lc=lcm(a,b);
        for(int i=1;i*i<=x;i++)
        {
            if(x%i==0)
            {
                ll cur=x/i;
                ll k=(a%cur==0?0:(cur-a%cur));
                ll tmp=lcm(a+k,b+k);
                if(lc>tmp)
                {
                    lc=tmp;
                    ans=k;
                }
                else if(lc==tmp) ans=min(ans,k);
                cur=i;
                k=(a%cur==0?0:(cur-a%cur));
                tmp=lcm(a+k,b+k);
                if(lc>tmp)
                {
                    lc=tmp;
                    ans=k;
                }
                else if(lc==tmp) ans=min(ans,k);
                //cout<<i<<":"<<ans<<endl;
            }
        }
        cout<<ans<<endl;
    }
}