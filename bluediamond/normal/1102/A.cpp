#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<"1\n";
        return 0;
    }
    if(n==2)
    {
        cout<<"1\n";
        return 0;
    }
    if(n%4==0)
    {
        cout<<0<<"\n";
        return 0;
    }
    if(n%4==1 || n%4==2)
    {
        cout<<"1\n";
        return 0;
    }
    cout<<"0\n";
    return 0;
}
/**

**/