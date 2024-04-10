#include<cstdio>
typedef long long ll;
ll n,s[50000],t[50000],k;
inline ll F(ll a){return(a*(n/a)*(n/a+1)>>1)-n/a*(a-1);}
int main(){
	scanf("%I64d",&n);
	ll i;
	for(i=1;i*i<n;i++)if(n%i==0)
	  s[++k]=i,t[k]=n/i;
	for(ll j=1;j<=k;j++)printf("%I64d ",F(t[j]));
	if(i*i==n)printf("%I64d ",F(i));
	for(ll j=k;j;j--)printf("%I64d ",F(s[j]));
	return 0; 
}