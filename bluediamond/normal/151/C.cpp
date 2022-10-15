#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll a;
ll ans[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a;
    int cnt=0;
    ll d=2;
    while(d*d<=a)
    {
        while(a%d==0)
        {
            ans[++cnt]=d;
            a/=d;
        }
        d++;
    }
    if(a>1)
    {
        ans[++cnt]=a;
    }
    if(cnt==2)
    {
        cout<<"2\n";
    }
    else
    {
        cout<<"1\n";
        if(cnt==1)
        {
            cout<<"0\n";
        }
        else
        {
            cout<<(ll)ans[1]*ans[2]<<"\n";
        }
    }
    return 0;
}