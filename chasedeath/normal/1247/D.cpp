#include<cstdio> 
#include<cctype>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<bitset>
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
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }


const int N=1e6+10;
const ll MAX=1e14;

int n;
int a[N];
int cnt[N];
ll p;


ll qpow(ll x,ll k){
	ll res=1;
	while(k) {
		if(k&1) {
			double t=(double)x*res;
			if(t>=MAX) res=MAX;
			else res=x*res;
		}
		double t=(double)x*x;
		if(t>=MAX) x=MAX;
		else x=x*x;
		k>>=1;
	}
	return res;
}



int main(){
	n=rd(),p=rd();
	ll ans=0;
	rep(i,1,n) {
		a[i]=rd();
		int x=a[i];
		ll t=1,t2=1;
		for(reg int j=2;j*j<=x;++j) if(x%j==0) {
			int c=0;
			while(x%j==0) x/=j,c++;
			c%=p;
			t2=t2*qpow(j,c);
			c=(p-c)%p;
			ll res=qpow(j,c);
			double tmp=1.0*t*res;
			if(tmp>MAX) t=MAX;
			else t=t*res;
		}
		if(x>1) {
			t2=t2*x;
			ll res=qpow(x,p-1);
			double tmp=1.0*t*res;
			if(tmp>MAX) t=MAX;
			else t=t*res;
		}
		//cout<<"#"<<i<<' '<<t<<' '<<cnt[t]<<endl;
		if(t<=1e5) ans+=cnt[t];
		cnt[t2]++;
	}
	printf("%lld\n",ans);
}