#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans_A,ans_B,ans_C;
ll P[505][505],n,V,s,B,v[10001];
void dfsb(ll i,ll b,ll a){
	if((double)b*b>V/a)
		return;
	if(i>n){
		B=max(B,b);
		return;
	}
	for(ll j=v[i];j>=0;j--){
		dfsb(i+1,b*P[i][j],a);
	}
}
void dfsa(ll i,ll a){
	ll j,t,Smax,c,A;
	if((double)a*a*a>V)
		return;
	if(i>n){
		t=V/a;
		Smax=4*a*sqrt(t)+2*t;
		if(Smax>=s)
			return;
		B=0;dfsb(1,1,a);
		c=V/a/B;
		A=(a*B+B*c+c*a)<<1;
		if(A<s){
			s=A;
			ans_A=a;
			ans_B=B;
			ans_C=c;
		}
		return ;
	}
	for(j=v[i];j>=0;--j){
		v[i]-=j;
		dfsa(i+1,a*P[i][j]);
		v[i]+=j;
	}
}
int main(){
	long long T;cin>>T;
	while(T--){
		cin>>n;
		V=1;
		for(ll i=1;i<=n;i++){
			ll a,b;
			cin>>a>>b;v[i]=b;
			P[i][0]=1;
			for(ll j=1;j<=b;j++){
				P[i][j]=P[i][j-1]*a;
			}
			V*=P[i][b];
		}
		s=1ll<<62;
		dfsa(1,1);
		cout<<s<<" "<<ans_A<<" "<<ans_B<<" "<<ans_C<<endl;
	}
	return 0;
}