#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define int long long
#define mod 998244353
using namespace std;
struct node{
	int l,r,key,val;
	node(){
		l=r=key=val=0;
		return;
	}
}fhq[1000005];
int cnt,root,x,y,z;
inline void newnode(int val){
	++cnt;
	fhq[cnt].val=val;
	fhq[cnt].key=rand()*rand()+rand();
	return; 
}
inline void split(int now,int val,int &x,int &y){
	if (now==0){
		x=y=0;
		return;
	}
	if (fhq[now].val<=val){
		x=now;
		split(fhq[now].r,val,fhq[now].r,y);
	}
	else{
		y=now;
		split(fhq[now].l,val,x,fhq[now].l);
	}
	return;
} 
inline int merge(int x,int y){
	if (x==0)return y;
	if (y==0)return x;
	if (fhq[x].key>fhq[y].key){
		fhq[x].r=merge(fhq[x].r,y);
		return x;
	}
	else{
		fhq[y].l=merge(x,fhq[y].l);
		return y;
	}
}
inline void ins(int val){
	newnode(val);
	split(root,val,x,y);
	root=merge(x,merge(cnt,y));
	return;
}
inline void del(int val){
	split(root,val-1,x,y);
	split(y,val,y,z);
	root=merge(x,z);
	return;
}
inline int pre(int val){
	split(root,val-1,x,y);
	int now=x;
	while(fhq[now].r!=0)now=fhq[now].r;
	root=merge(x,y);
	return fhq[now].val;
}
inline int nxt(int val){
	split(root,val,x,y);
	int now=y;
	while(fhq[now].l!=0)now=fhq[now].l;
	root=merge(x,y);
	return fhq[now].val;
}
inline int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
inline int inv(int x){
	return Qpow(x,mod-2);
}
int n,T,p[200005],q[200005],f[200005],mulp[200005],mulq[200005],a[200005],pos,ans;
inline int calc(int l,int r){
	return (f[r]-f[l-1]*(mulq[r]*mulp[l-1]%mod)%mod+mod)%mod;
}
signed main(){
	cin>>n>>T;
	mulp[0]=mulq[0]=1;
	for (int i=1;i<=n;i++){
		scanf("%lld",&p[i]);
		p[i]=p[i]*inv(100)%mod;
		q[i]=inv(p[i]);
		f[i]=(f[i-1]+1)*q[i]%mod;
		mulp[i]=mulp[i-1]*p[i]%mod;
		mulq[i]=mulq[i-1]*q[i]%mod;
	}
	ans=calc(1,n);
	a[1]=1;
	ins(1),ins(n+1);
	while(T--){
		scanf("%lld",&pos);
		if (a[pos]==0){
			ans-=calc(pre(pos),nxt(pos)-1);
			ans+=calc(pre(pos),pos-1);
			ans+=calc(pos,nxt(pos)-1);
			ans=(ans%mod+mod)%mod;
			a[pos]=1;
			ins(pos);
		}
		else{
			ans-=calc(pre(pos),pos-1);
			ans-=calc(pos,nxt(pos)-1);
			ans+=calc(pre(pos),nxt(pos)-1);
			ans=(ans%mod+mod)%mod;
			a[pos]=0;
			del(pos);
		}
		printf("%lld\n",ans);
	}
	return 0;
}