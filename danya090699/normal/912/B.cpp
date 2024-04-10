#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    if(k==1) cout<<n;
    else
    {
        int a=0, an=0;
        while((1ll<<a)<=n)
        {
            an+=(1ll<<a), a++;
        }
        cout<<an;
    }
}