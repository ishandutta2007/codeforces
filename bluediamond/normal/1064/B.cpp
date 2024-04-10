/**
   
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int ans=1;
        int x;
        cin>>x;
        while(x)
        {
            if(x&1)
            {
                ans*=2;
            }
            x>>=1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/**
**/