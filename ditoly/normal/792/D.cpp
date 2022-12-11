#include<cstdio> 
#include<iostream>
using namespace std;
#define ll long long
#define MN 100000
char s[MN+5];
ll find(ll x,ll n,ll k)
{
	n>>=1;
	if(k<=n)return find(x<<1,n,k);
	if(k-=n+1)return find(x<<1|1,n,k);
	return x;
}
ll query(ll x,ll n)
{
	int cnt=0,a[100];ll ans=0;
	while(x>1)a[cnt++]=x&1,x>>=1;
	while(cnt--){n>>=1;if(a[cnt])ans+=n+1;}
	return ans+1+(n>>1);
}
int main()
{
	ll n,x;int q,i;
	cin>>n>>q;
	while(q--)
	{
		cin>>x;scanf("%s",s);
		x=find(1,n,x);
		for(i=0;s[i];++i)
		{
			if(s[i]=='U'&&x>1)x>>=1;
			if(s[i]=='L'&&x<<1<n)x<<=1;
			if(s[i]=='R'&&x<<1<n)x=x<<1|1;
		}
		cout<<query(x,n)<<endl;
	}
}