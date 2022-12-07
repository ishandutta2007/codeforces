#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ch[n+1], add=0, cu=0, be=1e18, bnu;
    for(int a=0; a<=n; a++) ch[a]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        x--;
        if(x<=a)
        {
            cu+=a-x;
            ch[0]++, ch[n-1-a]--;
            ch[n-1-a]-=(n-1-x)-x, ch[n-a]+=(n-1-x)-x;
            ch[n-a]--, ch[n-a+x]++;
            ch[n-a+x]++, ch[n]--;
        }
        else
        {
            cu+=x-a;
            ch[0]--, ch[x-a]++;
            ch[x-a]++, ch[n-1-a]--;
            ch[n-1-a]-=(n-1-x)-x, ch[n-a]+=(n-1-x)-x;
            ch[n-a]--, ch[n]++;
        }
    }
    for(int a=0; a<n; a++)
    {
        if(cu<be)
        {
            be=cu, bnu=a;
        }
        add+=ch[a];
        cu+=add;
    }
    cout<<be<<" "<<bnu;
}