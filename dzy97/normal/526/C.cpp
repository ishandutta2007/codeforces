#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


typedef long long LL;

LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    LL n,s1,v1,s2,v2;
    LL T,tt=0;
	LL i,j,k,ans,p,q,m,num;
	cin>>n>>v1>>v2>>s1>>s2;
	m=lcm(s1,s2);
	num=n/m;
	if(num){num--;}
	if(v1*s2>=v2*s1)
	{
	    num=m/s1*num;
	    p=(n-num*s1)/s2;
	    ans=num*v1+p*v2;
	    if(s1>=s2)
	    {
	        for(i=num;i*s1<=n;i++)
	        {
	            q=i*v1+(n-i*s1)/s2*v2;
	            if(q>ans)ans=q;
	        }
	    }
	    else
	    {
	        for(i=p;i>=0;i--)
	        {
	            q=i*v2+(n-i*s2)/s1*v1;
	            if(q>ans)ans=q;
	        }
	    }
	}
	else
	{
	    num=m/s2*num;
	    p=(n-num*s2)/s1;
	    ans=num*v2+p*v1;
	    if(s2>=s1)
	    {
	        for(i=num;i*s2<=n;i++)
	        {
	            q=i*v2+(n-i*s2)/s1*v1;
	            if(q>ans)ans=q;
	        }
	    }
	    else
	    {
	        for(i=p;i>=0;i--)
	        {
	            q=i*v1+(n-i*s1)/s2*v2;
	            if(q>ans)ans=q;
	        }
	    }
	}
	cout<<ans<<endl;
    return 0;
}