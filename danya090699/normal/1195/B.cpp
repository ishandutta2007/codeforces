#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    for(int a=1; a<=n; a++)
    {
        if(a*(a+1)/2-(n-a)==k)
        {
            cout<<n-a;
            break;
        }
    }
}