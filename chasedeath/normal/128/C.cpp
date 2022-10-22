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


const int N=2e3+10,P=1e9+7;

int n,m,k;
ll Inv[N]={1,1},po[N]={1};

ll C(int n,int m){
	if(n<m)return 0;
	return po[n]*Inv[m]%P*Inv[n-m]%P;
}

int main(){
	n=rd(),m=rd(),k=rd();
	rep(i,1,N-1) po[i]=po[i-1]*i%P;
	rep(i,2,N-1) Inv[i]=(P-P/i)*Inv[P%i]%P;
	rep(i,1,N-1) Inv[i]=Inv[i]*Inv[i-1]%P;
	ll ans=C(n-1,k*2)*C(m-1,k*2)%P;
	printf("%lld\n",ans%P);
}