#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n;
    cin>>n;
    int ar[n+1][n+1];
    ar[1][1]=0, ar[n][n]=0;
    for(int a=2; a<=2*n-1; a++)
    {
        for(int r=1; r<=n; r++)
        {
            int c=a-r+1;
            if(c>0 and c<=n)
            {
                if(r&1) ar[r][c]=0;
                else ar[r][c]=1ll<<(a-2);
            }
        }
    }
    for(int a=1; a<=n; a++)
    {
        for(int b=1; b<=n; b++) cout<<ar[a][b]<<" ";
        cout<<"\n";
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int k, r=1, c=1;
        cin>>k;
        cout<<"1 1\n";
        for(int b=1; b<2*n-1; b++)
        {
            if((k&1)==((r-1)&1)) c++;
            else r++;

            k>>=1;

            cout<<r<<" "<<c<<"\n";
        }
    }
}