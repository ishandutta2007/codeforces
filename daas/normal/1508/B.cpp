#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
const int  MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,ans[MAXN],n,K,flag;
void fun(int n,int K,int plus)
{
	if(!n)
	{
		if(K>1) flag=1;
		return;
	}
	if(n-2>=62) {ans[plus+1]=plus+1;fun(n-1,K,plus+1);return;}
	int l=1,r=n,res=(1ll<<n-1),len=0;
	while(l<=r)
	{
		int mid=(l+r)>>1,del=res-(1ll<<n-mid);
		if(del<K) len=mid,l=mid+1;
		else r=mid-1;
	}
	//cout<<n<<" "<<K<<" "<<plus<<" "<<len<<" "<<(1ll<<(n-len))<<endl;
	for(int i=1;i<=len;++i) ans[plus+i]=plus+len-i+1;
	fun(n-len,K-(res-(1ll<<n-len)),plus+len);
}
signed main()
{
	T=read();
	while(T--)
	{
		n=read(),K=read();
		flag=0;
		fun(n,K,0);
		if(flag) {puts("-1");continue;}
		for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
		putchar('\n');
	}
	return 0;
}