#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cauta(ll n,ll P)
{
    ll r=0,pas=(1<<29);
    while(pas)
    {
        if(r+pas<=1e9 and n/(r+pas)>=P)
            r+=pas;
        pas/=2;
    }
    if(n/r!=P)
        return -1;
    return r;
}
void slove(int key)
{
    if(key==0)
    {
        cout<<"1 1\n";
        return;
    }
    for(ll i=1;i*i<key;i++)
        if(key%i==0)
        {
            ll a,b;
            a=i;
            b=key/i;
            if((a+b)%2==1 or (b-a)%2==1)
                continue;
            ll n,P,MAG;
            n=(a+b)/2;
            P=(b-a)/2;
            MAG=cauta(n,P);
            if(MAG==-1)
                continue;
            cout<<n<<" "<<MAG<<"\n";
            return;
        }
    cout<<"-1\n";
}
int test;
int main()
{
    cin>>test;
    while(test--)
    {
        ll VAL;
        cin>>VAL;
        slove(VAL);
    }
    return 0;
}