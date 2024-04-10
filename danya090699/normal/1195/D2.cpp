#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], q[11], st[30];
    st[0]=1;
    for(int a=1; a<30; a++) st[a]=(1ll*st[a-1]*10)%mod;
    for(int a=1; a<=10; a++) q[a]=0;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        int x=ar[a], zq=0;
        while(x) x/=10, zq++;
        q[zq]++;
    }
    int an=0;
    for(int a=0; a<n; a++)
    {
        int cu=0;
        while(ar[a])
        {
            int zi=ar[a]%10;
            for(int i=0; i<2; i++)
            {
                for(int b=1; b<=10; b++)
                {
                    int x=cu+min(cu+i, b);
                    x=(1ll*zi*st[x])%mod;
                    an=(an+1ll*q[b]*x)%mod;
                }
            }
            ar[a]/=10, cu++;
        }
    }
    cout<<an;
}