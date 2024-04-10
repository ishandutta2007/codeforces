#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll int hcf(ll int n1,ll int n2)
{
    if(n2%n1==0)
    return n1;
    return hcf(n2%n1,n1);
}
bool check(ll int n1,ll int n2)
{
    return hcf(n1,n2)==1;
}
int main()
{
    ll int l,r,i,j,k;
    cin>>l>>r;
    for(i=l;i<=r;i++)
    {
        for(j=i+1;j<=r;j++)
        {
            if(check(i,j))
            {
            for(k=j+1;k<=r;k++)
            {
                if(check(j,k))
                {
                    if(check(i,k))
                    {
                        continue;
                    }
                    else 
                    {
                        cout<<i<<" "<<j<<" "<<k;return 0;
                    }
                }
            }
            }
        }
    }
    cout<<-1;// till now no combination would have been detected samjha
    return 0; 
}