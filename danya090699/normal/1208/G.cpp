#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int f[n+1];
    for(int a=2; a<=n; a++) f[a]=a;
    for(int a=2; a<=n; a++)
    {
        if(f[a]==a)
        {
            for(int b=a; b<=n; b+=a) f[b]-=f[b]/a;
        }
    }
    sort(f+3, f+n+1);
    long long an=1+(k>1);
    for(int a=0; a<k; a++) an+=f[a+3];
    cout<<an;
}