#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    long long su=0, ma=0;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        su+=x;
        ma=max(ma, 1ll*x);
    }
    if(su%2==0 and ma<=su-ma) cout<<"YES";
    else cout<<"NO";
}