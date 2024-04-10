#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
const int mod=998244353;
int n,m;
ll a[N],s[N];
struct fhq{
	int ls,rs,rnd,sz;
	ll x,tag;
}f[N<<1];
int P;
inline int build(ll x){
	int p=++P;
	f[p].ls=f[p].rs=f[p].tag=0;
	f[p].rnd=rand();
	f[p].sz=1;
	f[p].x=x;
	return p;
}
inline void upd(int p){
	f[p].sz=f[f[p].ls].sz+f[f[p].rs].sz+1;
}
inline void pushd(int p){
	f[p].x+=f[p].tag;
	if(f[p].ls) f[f[p].ls].tag+=f[p].tag;
	if(f[p].rs) f[f[p].rs].tag+=f[p].tag;
	f[p].tag=0;
}
void split(int p,ll k,int &x,int &y){
	if(!p){
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
	upd(p);
}
int merge(int x,int y){
	if(!x||!y) return x|y;
	pushd(x);pushd(y);
	if(f[x].rnd<f[y].rnd){
		f[x].rs=merge(f[x].rs,y);
		upd(x);
		return x;
	}
	else{
		f[y].ls=merge(x,f[y].ls);
		upd(y);
		return y;
	}
}
inline void ins(int &rt,ll x){
	int p1=0,p2=0,p3=build(x);
	split(rt,x,p1,p2);
	rt=merge(merge(p1,p3),p2);
}
inline int qry(int &rt,ll x){
	int p1=0,p2=0;
	split(rt,x,p1,p2);
	int ret=f[p2].sz;
	rt=merge(p1,p2);
	return ret;
}
int rt;
inline int solve(){
	if(n==1) return 1;
	int ans=0,i;
	ll w0=0,w1=0;rt=0;
	for(i=2;i<=n;i+=2){
		if(i>2){
			ins(rt,-s[i-2]);
			ins(rt,-(s[i-2]-a[1])+a[1]);
			f[rt].tag+=a[i-1]-a[i];
			ans+=qry(rt,s[i]-s[n]);
			if(n-i>2) ans+=qry(rt,s[i]-s[n-1]+a[n]);			
		}
		if(s[n]-s[i]>s[i]) ans++;
		if(n-i>2&&s[n-1]-s[i]>s[i]+a[n]) ans++;
		if(s[n]-s[i]+a[1]>s[i]-a[1]) ans++;
		if(n-i>2&&s[n-1]-s[i]+a[1]>s[i]-a[1]+a[n]) ans++;
		ans%=mod;
	}
	rt=0;
	for(i=1;i<=n;i+=2){
		if(i>2){
			ins(rt,-s[i-2]);
			if(i!=3||n==3) ins(rt,-(s[i-2]-a[1])+a[1]);
			f[rt].tag+=a[i-1]-a[i];
			ans+=qry(rt,s[i]-s[n]);
			if(n-i>2) ans+=qry(rt,s[i]-s[n-1]+a[n]);			
		}
		if(s[n]-s[i]>s[i]) ans++;
		if(n-i>2&&s[n-1]-s[i]>s[i]+a[n]) ans++;
		if(s[n]-s[i]+a[1]>s[i]-a[1]) ans++;
		if(n-i>2&&s[n-1]-s[i]+a[1]>s[i]-a[1]+a[n]) ans++;
		ans%=mod;
	}
	for(i=2;i<=n-2;i++)
		if(s[i]>s[n]-s[i]) ans++;
	return ans%mod;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;P=0;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		cout<<solve()<<endl;
	}
	return 0;
}