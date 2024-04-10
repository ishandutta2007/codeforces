#include<bits/stdc++.h>
using namespace std;
int isprime[1000001],can;
int a,b,k;
void prime()
{
    for(int i=2;i<1000001;i++)
    {
        isprime[i]=1;
        for(int j=2;j*j<=i;j++)
            if(i%j==0)
            {
                isprime[i]=0;
                break;
            }
        isprime[i]+=isprime[i-1];
    }
}
bool check(int x)
{
    for(int i=a;i<b-x+1;i++)
        if(isprime[i+x]-isprime[i-1]<k)
            return 0;
    return 1;
}
int main()
{
    prime();
    cin>>a>>b>>k;
    if(a==b&&isprime[a]-isprime[a-1]&&k==1)
    {
        cout<<k;
        return 0;
    }
    else if(a==b)
    {
        cout<<-1;
        return 0;
    }
    int l=1,r=b-a+1;
    while(r>l)
    {
        int mid=(l+r)/2;
        if(check(mid))
            r=mid,
            can=1;
        else
            l=mid+1;
    }
    if(can)
        cout<<l+1;
    else
        cout<<-1;
}