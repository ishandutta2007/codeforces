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
const ll T3=333333336,T2=500000004;
map <ll,int> M;

ll qsm(ll x,ll k){
	k=(k+P-1)%(P-1);
	ll res=1;
	while(k>0) {
		if(k&1) res=res*x%P;
		x=x*x%P;
		k>>=1;
	}
	return res;
}

double t[N];

int main(){
	//cout<<2*T2%P<<' '<<T3*3%P<<endl;
	//t[0]=1,t[1]=0;
	//rep(i,2,10) t[i]=(t[i-1]+t[i-2])/2,cout<<i<<' '<<t[i]<<endl;
	int n=rd();
	ll x=1,k=0;
	rep(i,1,n) {
		ll t;scanf("%lld",&t);
		if(t==1000000006) k=1;
		t%=P-1;
		x=x*t%(P-1);
	}
	ll a=qsm(2,x),b=qsm(2,x-1);
	//b=b*T2%P;
	//cout<<a<<' '<<b<<endl;
	if(x&1) a=(a+1+P)%P;
	else a=(a-1)%P;
	//cout<<a<<' '<<b<<endl;
	//cout<<a<<endl;
	a=a*T3%P;
	a=(b-a+P)%P;
	printf("%lld/%lld\n",a,b);
}