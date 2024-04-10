#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if(k==0)
    {
        cout<<"1\n";
    }
    else
    {
        if(n%2==0)
        {
            if(k<=n/2)
            {
                cout<<k<<"\n";
            }
            else
            {
                int di=k-n/2;
                cout<<n/2-di<<"\n";
            }
        }
        if(n%2==1)
        {
            if(k<=n/2)
            {
                cout<<k<<"\n";
            }
            else
            {
                int di=k-n/2;
                cout<<n/2+1-di<<"\n";
            }
        }
    }
    return 0;
}
/**

**/