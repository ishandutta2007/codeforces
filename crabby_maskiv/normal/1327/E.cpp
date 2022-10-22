#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<19;
const ll mod=998244353;
int n,m;
inline ll po(ll x,ll k){
	ll ret=1;
	while(k){
		if(k&1) ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}
int rev[N];
ll omg[N];
inline void getrev(int nn){
	for(int i=1;i<nn;i++) rev[i]=(rev[i>>1]>>1)|(i&1)*(nn>>1);
}
inline void NTT(ll *a,int nn,int flag){
	int i,j,k;
	for(i=0;i<nn;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(j=1;j<nn;j<<=1){
		for(k=0;k<nn;k+=j<<1){
			int w=0;
			for(i=0;i<j;i++){
				ll x=a[i+k],y=a[i+j+k];
				a[i+k]=(x+omg[w]*y)%mod;
				a[i+j+k]=(x-omg[w]*y%mod+mod)%mod;
				w=(w+flag*(N/(j<<1))+N)%N;
			}
		}
	}
	if(flag==-1){
		ll ivn=po(nn,mod-2);
		for(i=0;i<nn;i++) a[i]=a[i]*ivn%mod;
	}
}
ll A[N],B[N];
inline vector<ll> pmul(const vector<ll> &a,const vector<ll> &b){
	int nn=1;while(nn<a.size()+b.size()-1) nn<<=1;
	int i;
	for(i=0;i<nn;i++) A[i]=B[i]=0;
	for(i=0;i<a.size();i++) A[i]=a[i];
	for(i=0;i<b.size();i++) B[i]=b[i];
	getrev(nn);
	NTT(A,nn,1);
	NTT(B,nn,1);
	for(i=0;i<nn;i++) A[i]=A[i]*B[i]%mod;
	NTT(A,nn,-1);
	vector<ll> ret(a.size()+b.size()-1);
	for(i=0;i<ret.size();i++) ret[i]=A[i]; 
	return ret;
}
int main(){
	int i,j;
	ll w=po(3,(mod-1)/N);
	omg[0]=1;
	for(i=1;i<N;i++) omg[i]=omg[i-1]*w%mod;
	cin>>n;
	vector<ll> F(n);
	w=1;
	for(i=0;i<n;i++){
		if(i==0) F[i]=1;
		else{
			F[i]=9*w%mod;
			w=w*10%mod;
		}
	}
	vector<ll> G=pmul(F,F);
	for(i=n-1;i>=0;i--) cout<<G[i]*10%mod<<" ";
	return 0;
}