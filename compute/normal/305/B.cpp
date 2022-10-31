#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
long long p,q;
long long a[100];

long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    cin>>p>>q;
    cin>>n;
    long long t;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int i;
    for(i=0;i<n;i++)
    {
        if(q==0||p/q<a[i]) break;
        t=gcd(p,q);
        p/=t;
        q/=t;
        p-=q*a[i];
        t=p;
        p=q;
        q=t;
    }
    if(i==n&&q==0)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}