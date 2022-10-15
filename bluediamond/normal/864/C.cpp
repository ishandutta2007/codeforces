#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll a,b,f,k,cost=0,fuel,rest;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>f>>k;
    fuel=b;
    rest=k%2;
    k/=2;
    if(rest==0)
    {
    for(ll i=1;i<k;i++)
    {
        /**
        0...a
        0...f...a...f...0
        6 5 4 3
        a b f k
        0...4...6...4...0
        k=3
        2*(a-f)
        **/
        fuel-=f;
        if(fuel<0)
        {
            cout<<-1;
            return 0;
        }
        if(fuel<2*(a-f))
        {
            cost++;
            fuel=b;
        }
        if(fuel<2*(a-f))
        {
            cout<<-1;
            return 0;
        }
        fuel-=2*(a-f);
        if(fuel<2*f)
        {
            cost++;
            fuel=b;
        }
        fuel-=f;
    }
    /**
    0...a
    0...f...a...f...0
    2*(a-f)
    **/
    fuel-=f;
    if(fuel<0)
    {
        cout<<-1;
        return 0;
    }
    if(fuel<2*(a-f))
    {
        cost++;
        fuel=b;
    }
    if(fuel<2*(a-f))
    {
        cout<<-1;
        return 0;
    }
    fuel-=2*(a-f);
    if(fuel<f)
    {
        cost++;
        fuel=b;
    }
    fuel-=f;
    if(fuel<0)
    {
        cout<<-1;
        return 0;
    }
    cout<<cost;
    return 0;
    }
    for(ll i=1;i<=k;i++)
    {
        /**
        0...a
        0...f...a...f...0
        6 5 4 3
        a b f k
        0...4...6...4...0
        k=3
        2*(a-f)
        **/
        fuel-=f;
        if(fuel<0)
        {
            cout<<-1;
            return 0;
        }
        if(fuel<2*(a-f))
        {
            cost++;
            fuel=b;
        }
        if(fuel<2*(a-f))
        {
            cout<<-1;
            return 0;
        }
        fuel-=2*(a-f);
        if(fuel<2*f)
        {
            cost++;
            fuel=b;
        }
        fuel-=f;
    }
    fuel-=f;
    if(fuel<0)
    {
        cout<<-1;
        return 0;
    }
    if(fuel<a-f)
    {
        cost++;
        fuel=b;
    }
    fuel-=(a-f);
    if(fuel<0)
    {
        cout<<-1;
        return 0;
    }
    cout<<cost;
    return 0;
}
/**
**/