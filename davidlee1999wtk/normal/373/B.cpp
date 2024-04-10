#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
long long qlen(long long a)
{
    long long t=0;
    while(a)
    {
        t++;
        a/=10;
    }
    return t;
}

long long qqs(long long a)
{
    int i,t=10;
    long long sum=1;
    for(i=1;i<=a;i++)
        sum*=t;
    return sum;
}
int main()
{
    long long m,w,k;
    long long i,j,ans=0;
    cin>>w>>m>>k;
    i=qlen(m);
    if((qqs(i)-m)*i<=w/k)
    {
        w-=(qqs(i)-m)*i*k;
        ans+=qqs(i)-m;
        //cout<<ans<<endl;
    }
    else
    {
        ans=w/(i*k);
        cout<<ans<<endl;
        return 0;
    }
    for(i=i+1;;i++)
    {
        if((long long)(qqs(i)-qqs(i-1))*i<=w/k)
        {
            w-=(qqs(i)-qqs(i-1))*i*k;
            ans+=qqs(i)-qqs(i-1);
        }
        else
        {
            ans+=w/(i*k);
            cout<<ans<<endl;
            return 0;
        }
    }
    return 0;
}