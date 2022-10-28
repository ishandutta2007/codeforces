#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long int
int main()
{
    ios_base::sync_with_stdio(0);
    li a[9],i,sum=0;
    for(i=0;i<9;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    a[0]=sum/2-a[1]-a[2];
    a[4]=sum/2-a[3]-a[5];
    a[8]=sum/2-a[6]-a[7];
    for(i=1;i<=9;i++)
    {
        
        cout<<a[i-1]<<" ";
        if(i%3==0)cout<<"\n";
        
    }
    return 0;
}