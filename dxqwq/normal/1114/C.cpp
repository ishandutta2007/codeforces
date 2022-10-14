#include<bits/stdc++.h>
using namespace std;
unsigned long long base[20],a[20],c[20],k=0; 
int find(unsigned long long n)
{
	for(int i=1; i<=k; i++) if(base[i]==n) return i;
	return 0;
}
void setb(unsigned long long n)
{
	if(n==1) return ;
	for(int i=2; i<=sqrt(n); i++) if(n%i==0) 
	{
		if(find(i)!=0) c[find(i)]++;
		else 
		{
			k++;
			base[k]=i;
			c[k]=1;
		}
		setb(n/i);
		return ;
	}
	if(find(n)!=0) c[find(n)]++;
	else 
	{
		k++;
		base[k]=n;
		c[k]=1;
	}
	return ;
}
unsigned long long fac(unsigned long long i,unsigned long long n)
{
	unsigned long long res=0;
	while(n>=i)
	{
		res+=n/i;
		n=n/i;
	}
	return res;
}
void setn(long long n)
{
	for(int i=1; i<=k; i++) a[i]=fac(base[i],n);
	return ;
}
unsigned long long getans()
{
	unsigned long long res=9223372036854775806;
	for(int i=1; i<=k; i++) if(res>a[i]/c[i]) res=a[i]/c[i];
	return res;
}
int main()
{
	unsigned long long n,b;
	cin>>n>>b;
	setb(b);
	setn(n);
	cout<<getans();
	return 0;
}