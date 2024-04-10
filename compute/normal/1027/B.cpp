#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    int q;
    cin>>n>>q;
    long long x,y;
    for(int i=0;i<q;i++)
    {
        scanf("%lld%lld",&x,&y);
        long long ans;
        if(n%2==0)
        {
            if((x+y)%2==0)
            {
                ans=n/2*(x-1)+(y+1)/2;
            }
            else{
                ans=n*n/2+n/2*(x-1)+(y+1)/2;
            }
        }
        else{
            if((x+y)%2==0)
            {
                ans=ceil(n*(x-1)/2.0)+(y+1)/2;
            }
            else{
                ans=ceil(n*n/2.0)+n*(x-1)/2+(y+1)/2;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}