#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, be=2e18, bnu, bq;
    cin>>n>>k;
    for(int a=0; a<k; a++)
    {
        int x;
        cin>>x;
        if(n%x<be)
        {
            be=n%x, bnu=a+1, bq=n/x;
        }
    }
    cout<<bnu<<" "<<bq;
}