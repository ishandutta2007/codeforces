#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

int IO;
int rd(){
	int s=0;
	while((IO=getchar())<48);
	do s=(s<<1)+(s<<3)+(IO^'0');
	while((IO=getchar())>47);
	return s;
}

const int N=2e5+10;
const ll P=1e9+7;

int n,k;

ll po[N]={1},Inv[N]={1,1};


ll C(int n,int m){
	if(n<0||n<m||m<0) return 0;
	return po[n]*Inv[m]%P*Inv[n-m]%P;
}


//  C(n-(r-l+1),k)
//  Inv[k]* po[n-(r-l+1)] * Inv[n-(r-l+1)-k]
//   


// 10^i*a[i]*C(n-i-1,k)
// 10^i*C(n-i-1,k)





ll f[N];
ll ans=0;

int main(){
	rep(i,2,N-1) Inv[i]=(P-P/i)*Inv[P%i]%P;
	rep(i,1,N-1) po[i]=po[i-1]*i%P;
	rep(i,1,N-1) Inv[i]=Inv[i]*Inv[i-1]%P;
	//rep(i,0,3) rep(j,0,i) cout<<i<<' '<<j<<' '<<C(i,j)<<endl;
	n=rd(),k=rd();
	f[0]=1*C(n-2,k-1);
	ll t=1;
	rep(i,1,n-1) {
		t=t*10%P;
		f[i]=f[i-1]+t*C(n-i-2,k-1)%P;
		f[i]%=P;
	}
	//rep(i,0,n-1) cout<<f[i]<<' ';puts("");
	t=1;
	rep(i,0,n-1) {
		f[i]=(f[i]-t*C(n-i-2,k-1)%P+t*C(n-i-1,k)%P+P)%P;
		//cout<<"#"<<n-i-2<<' '<<k-1<<' '<<t<<' '<<t*C(n-i-2,k-1)<<' '<<t*C(n-i-1,k)<<endl;
		t=t*10%P;
	}
	rep(i,1,n) {
		int x; scanf("%1d",&x);
		(ans+=x*f[n-i])%=P;
		//cout<<f[n-i]<<endl;
	}
	printf("%lld\n",ans);
}