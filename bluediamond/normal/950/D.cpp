#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,poz;
int q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    while(q--)
    {
        cin>>poz;
        if(poz%2==1)
        {
            cout<<(poz+1)/2<<"\n";
        }
        else
        {
            while(poz%2==0)
            {
                poz=poz/2+n;
            }
            cout<<poz/2+1<<"\n";
        }
    }
    return 0;
}
/**
**/