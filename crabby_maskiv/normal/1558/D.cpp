#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5;
const int mod=998244353;
int n,m;
int fac[N],invf[N];
inline int po(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
inline int C(int x,int k){
	if(x<k) return 0;
	return 1ll*fac[x]*invf[k]%mod*invf[x-k]%mod;
}
struct fhq{
	int x,tag,rnd,ls,rs;
}f[N];
int rt,P;
inline int build(int x){
	int p=++P;
	f[p].tag=f[p].ls=f[p].rs=0;
	f[p].rnd=rand();
	f[p].x=x;
	return p;
}
inline void pushd(int p){
	f[p].x+=f[p].tag;
	if(f[p].ls) f[f[p].ls].tag+=f[p].tag;
	if(f[p].rs) f[f[p].rs].tag+=f[p].tag;
	f[p].tag=0;
}
void split(int p,int k,int &x,int &y){
	if(p==0){
		x=y=0;
		return;
	}
	pushd(p);
	if(k>=f[p].x){
		x=p;
		split(f[p].rs,k,f[x].rs,y);
	}
	else{
		y=p;
		split(f[p].ls,k,x,f[y].ls);
	}
}
int merge(int x,int y){
	if(!x||!y) return x|y;
	pushd(x);pushd(y);
	if(f[x].rnd<f[y].rnd){
		f[x].rs=merge(f[x].rs,y);
		return x;
	}
	else{
		f[y].ls=merge(x,f[y].ls);
		return y;
	}
}
int main(){
	int i,j;
	fac[0]=1;
	for(i=1;i<N;i++) fac[i]=1ll*fac[i-1]*i%mod;
	invf[N-1]=po(fac[N-1],mod-2);
	for(i=N-2;i>=0;i--) invf[i]=ll(invf[i+1])*(i+1)%mod;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		rt=P=0;
		int tot=0;
		for(i=1;i<=m;i++){
			int x,y;cin>>x>>y;
			int p1,p2,p3;
			split(rt,y-2,p1,p2);
			if(p2) f[p2].tag++;
			split(p2,y,p2,p3);
			if(!p2){
				tot++;
				p2=build(y);
			}
			rt=merge(p1,merge(p2,p3));
		}
		cout<<C(2*n-1-tot,n)<<endl;
	}
	return 0;
}