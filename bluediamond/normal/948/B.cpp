#include <bits/stdc++.h>

using namespace std;

bool prime(int n)
{
    if(n<=1)
        return 0;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return 0;
    return 1;
}
int P(int n)
{
    int ma=0;
    for(int i=1;i*i<=n;i++)
        if(n%i==0)
        {
            if(prime(i))
                ma=i;
            if(prime(n/i))
                return n/i;
        }
    return ma;
}
int n,ans;

int main()
{
    cin>>n;
    ans=n;
    int x=P(n);
    for(int i=n-x+1;i<=n;i++)
        if(prime(i)==0)
            ans=min(ans,i-P(i)+1);
    cout<<ans;
    return 0;
}