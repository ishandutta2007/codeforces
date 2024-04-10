#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    ll a[n],i1,i2,i,k;
    for(i=0;i<n;i++)
    cin>>a[i];
    i1=i2=0;i=0,k=1;
    for(i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            i1=i;
            while(a[i]>a[i+1] && i<n-1)i++;
            i2=i;
            if((a[i1]>a[i2+1] && i2<n-1) || (i1>0 && a[i2]<a[i1-1])){k=0;
            break;}
            
            for(i=i+1;i<n-1;i++)
            {
                if(a[i]>a[i+1]){ k=0;break;}
            }
            
            break;
        }
    }
    if(k)cout<<"yes\n"<<i1+1<<" "<<i2+1;
    else cout<<"no";
    
    return 0;
}