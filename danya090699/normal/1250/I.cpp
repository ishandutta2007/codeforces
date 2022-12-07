#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q=0, an;
    cin>>n;
    if(n==1) cout<<1;
    else
    {
        for(int a=2; a*a<=n; a++)
        {
            if(n%a==0)
            {
                q++, an=a;
                while(n%a==0) n/=a;
            }
        }
        if(n>1) q++, an=n;

        if(q==1) cout<<an;
        else cout<<1;
    }
}