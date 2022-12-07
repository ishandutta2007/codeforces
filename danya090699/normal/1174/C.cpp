#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q=1;
    cin>>n;
    int ar[n+1];
    for(int a=2; a<=n; a++) ar[a]=0;
    for(int a=2; a<=n; a++)
    {
        if(ar[a]==0)
        {
            for(int b=a; b<=n; b+=a) ar[b]=q;
            q++;
        }
    }
    for(int a=2; a<=n; a++) printf("%d ", ar[a]);
}