#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<18;
const int mod=998244353;
int n,m;
inline int po(int x,int k){
	int ret=1;
	while(k){
		if(k&1) ret=ret*ll(x)%mod;
		x=x*ll(x)%mod;
		k>>=1;
	}
	return ret;
}
int rev[N];
inline void getrev(int nn){
	for(int i=1;i<nn;i++) rev[i]=(rev[i>>1]>>1)|(i&1)*(nn>>1);
}
inline void NTT(int *a,int nn,int flag){
	int i,j,k;
	getrev(nn);
	for(i=1;i<nn;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(j=1;j<nn;j<<=1){
		for(k=0;k<nn;k+=j<<1){
			int w,omg=1;
			if(flag==1) w=po(3,(mod-1)/(j<<1));
			else w=po(3,mod-1-(mod-1)/(j<<1));
			for(i=0;i<j;i++){
				ll x=a[i+k],y=a[i+j+k];
				a[i+k]=(x+omg*ll(y))%mod;
				a[i+j+k]=(x-omg*ll(y)%mod+mod)%mod;
				omg=omg*ll(w)%mod;
			}
		}
	}
	if(flag==-1){
		int ivn=po(nn,mod-2);
		for(i=0;i<nn;i++) a[i]=a[i]*ll(ivn)%mod;
	}
}
int A[N],B[N];
inline vector<int> pmul(const vector<int> &a,const vector<int> &b){
	int nn=1;while(nn<a.size()+b.size()-1) nn<<=1;
	int i,j;
	for(i=0;i<nn;i++) A[i]=B[i]=0;
	for(i=0;i<a.size();i++) A[i]=a[i];
	for(i=0;i<b.size();i++) B[i]=b[i];
	NTT(A,nn,1);
	NTT(B,nn,1);
	for(i=0;i<nn;i++) A[i]=A[i]*ll(B[i])%mod;
	NTT(A,nn,-1);
	vector<int> ret(a.size()+b.size()-1);
	for(i=0;i<ret.size();i++) ret[i]=A[i];
	return ret;
}
inline vector<int> pinv(const vector<int> &a,int nn){
	vector<int> ret(nn);ret[0]=po(a[0],mod-2);
	int i,j;
	for(j=2;j<=nn;j<<=1){
		vector<int> F=a;F.resize(j);
		vector<int> G=ret;G.resize(j>>1);
		F=pmul(pmul(F,G),G);
		G.resize(j);
		for(i=0;i<j;i++) ret[i]=(2*G[i]-F[i]%mod+mod)%mod;
	}
	return ret;
}
inline vector<int> psqrt(const vector<int> &a,int nn){
	vector<int> ret(nn);ret[0]=1;
	int i,j;
	for(j=2;j<=nn;j<<=1){
		vector<int> F=a;F.resize(j);
		vector<int> G=ret;G.resize(j>>1);
		vector<int> H=pmul(G,G);H.resize(j);
		G=pinv(G,j);
		for(i=0;i<j;i++){
			F[i]=(F[i]+H[i])%mod;
			G[i]=499122177ll*G[i]%mod;
		}
		ret=pmul(F,G);ret.resize(nn);
	}
	return ret;
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);m++;
	vector<int> C(1e5+1);
	for(i=1;i<=n;i++){
		cin>>j;C[j]=1;
	}
	for(i=0;i<m;i++)
		C[i]=((mod-4*C[i])%mod+mod)%mod;
	C[0]=(C[0]+1)%mod;
	int nn=1;while(nn<m) nn<<=1;
	C=psqrt(C,nn);
	C[0]=(C[0]+1)%mod;
	C=pinv(C,nn);
	for(i=0;i<nn;i++) C[i]=(C[i]*2)%mod;
	for(i=1;i<m;i++) printf("%d\n",C[i]);
	return 0;
}