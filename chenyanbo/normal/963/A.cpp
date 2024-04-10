#include<bits/stdc++.h>
using namespace std;
#define  MO 1000000009
int vv[65];
inline int ksm(int p, int k)
{
	vv[0]=p;
	for(int i=1; i<=29; ++i)vv[i]=(long long)vv[i-1]*vv[i-1]%MO;
	int s=1;
	for(int i=29; i>=0; --i){
		if(1<<i<=k){
			k-=1<<i;
			s=(long long)s*vv[i]%MO;
		}
	}
	return s;
}

long long ll,a_,b_,s,l,ans,q,n,a,b,k;
char ss[1000050];
long long aa[1000050];

inline void upt(long long &a ,long long b)
{
	a=(a+b)%MO;
}

int main()
{
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	scanf("%s",ss+1);
	for(int i=1; i<=k; ++i)if(ss[i]=='+')aa[i-1]=1;else aa[i-1]=MO-1;
	for(int i=0; i<k; ++i)upt(s,aa[i]*ksm(a,n-i)%MO*ksm(b,i)%MO);
	a_=ksm(a,k);
	b_=ksm(b,k);
	q=b_*ksm(a_,MO-2)%MO;
	
	if(q==1){
		l=(n+1)/k;
		s=s*l%MO;
		cout<<s;
		return 0;
	}
	
	l=(n+1)/k;
	ans=(ksm(q,l)+MO-1)%MO;
	ans=ans*ksm(q+MO-1,MO-2)%MO;
	ans=ans*s%MO;
	cout<<ans;
}