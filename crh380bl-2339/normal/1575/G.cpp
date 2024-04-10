#include<bits/stdc++.h>
#define ll long long
#define N 100001
#define mod 1000000007
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
bool bo[N];
int p[N],tot=0,mu[N],S[N],a[N],num[N],sum[N],q[N];
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int main(){
	int i,j,n,ans=0,d,t,d1,s;
	mu[1]=1;bo[1]=1;
	for(i=2;i<N;++i){
		if(!bo[i]){
			p[++tot]=i;
			q[tot]=N/i;
			mu[i]=-1;
			for(j=2;j*i<N;++j){
				bo[j*i]=1;
				if(j%i)mu[j*i]=-mu[j]; 
			}
		}
	}
	for(i=1;i<N;++i){
		for(j=1;j*i<N;++j){
			S[i*j]=(1LL*S[i*j]+j*mu[i]+mod)%mod;
		}
	}
	read(n);
	for(i=1;i<=n;++i)read(a[i]);
	int m=min(900,n);
	for(d=m+1;d<=n;++d){
		for(i=1;i*d<=n;++i){
			for(j=1;j*d<=n;++j)ans=(ans+1LL*S[d]*gcd(a[i*d],a[j*d]))%mod;
		}
	}
	for(d=1;d<=m;++d){
		memset(num,0,sizeof(num));
		for(i=1;i*d<=n;++i)++num[a[i*d]];
		for(i=1;i<=tot;++i){
			for(j=q[i];j>=1;--j)num[j]+=num[p[i]*j]; 
		}
		t=0;
		for(d1=1;d1<N;++d1){
			t=(t+1LL*S[d1]*num[d1]%mod*num[d1])%mod;
		}
		ans=(ans+1LL*t*S[d])%mod;
	}
	printf("%d\n",ans);
	return 0;
}