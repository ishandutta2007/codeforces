#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}


const int N=1e6+10,P=1e9+7;

int n,m,p;
ll sum[N],po[N]={1};
ll f[N];
ll s[N];
ll ans;
int main(){
	n=rd();
	rep(i,1,N-1) po[i]=po[i-1]*2%P;
	drep(i,N-1,1) po[i]=po[i-1]*i%P;
	po[0]=0;
	rep(i,1,n) sum[rd()]++;
	rep(i,1,1e6) {
		for(reg int j=i+i;j<=1e6;j+=i) sum[i]+=sum[j];
		s[i]=po[sum[i]]%P;
		//if(sum[i]) cout<<i<<' '<<sum[i]<<endl;
		//if(s[i]) cout<<i<<' '<<s[i]<<endl;
	}
	drep(i,1e6,1) for(reg int j=i+i;j<=1e6;j+=i) (s[i]-=s[j])%=P;
	rep(i,2,1e6) ans=(ans+i*s[i]%P)%P;
	ans=(ans%P+P)%P;
	cout<<ans<<endl;
}