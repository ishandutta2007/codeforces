#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
long long n,m,i,j,k,md,s,l,r,mid,ans;
long long pa[1000005],pb[1000005];
vector<long long> v;
long long mul(long long x,long long y,long long mod){
    x%=mod;
    y%=mod;
    return x*y%mod;
}
long long excgcd(long long n,long long m,long long &x,long long &y){
	if (m==0){
		x=1;
		y=0;
		return n;
	}
	long long ans=excgcd(m,n%m,y,x);
	y=y-n/m*x;
	return ans;
}
long long inv(long long x,long long mod){
	long long s1,s2;
	excgcd(x,mod,s1,s2);
	if (s1<0) s1+=mod;
	return s1;
}
long long calc(long long x){
	long long ans=s*(x/md);
	x%=md;ans+=x;
	dzd(v,it) if(*it<=x) ans--;
	return ans;
}
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	rep(i,n){
		int x;scanf("%d",&x);pa[x]=i;
	}
	rep(i,m){
		int x;scanf("%d",&x);pb[x]=i;
	}
	s=md=n*m/__gcd(n,m);
	rep(i,1000000){
		if(pa[i]&&pb[i]){
			long long c1=pa[i],c2=pb[i],m1=n,m2=m;
			long long t=__gcd(m1,m2);
			if ((c2-c1)%t!=0){
				continue;
			}
			long long md=m1/t*m2;
			c1=((mul(mul(inv(m1/t,m2/t),((c2-c1)/t),(m2/t)),m1,md)+c1)%md+md)%md;
			if(c1==0) c1=md;
			v.push_back(c1);
			s--;
		}
	}
	ans=-1;l=0;r=1.5e18;
	while(l<r){
		mid=(l+r)/2;
		if(calc(mid)<k){
			l=mid+1;
			ans=mid;
		}
		else r=mid;
	}
	cout<<ans+1<<endl;
	return 0;
}