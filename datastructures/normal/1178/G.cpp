#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*fg;
}
int n,q,u[200005],v[200005],first[200005],nxt[200005],a[200005],b[200005];
struct Vec{
	ll x,y;
	Vec operator -(const Vec &a)const{
		Vec ans;
		ans.x=x-a.x,ans.y=y-a.y;
		return ans;
	}
	bool operator <(const Vec &a)const{
		if (x!=a.x)return x<a.x;
		return y<a.y;
	}
};
bool cmp(Vec a,Vec b){ //whether A is less than B
	if (a.x<0)a.x=-a.x,a.y=-a.y;
	if (b.x<0)b.x=-b.x,b.y=-b.y;
	return a.y*b.x<b.y*a.x;
}
ll qwqabs(ll x){
	if (x<0)return -x;
	return x;
}
struct Block{
	int B;
	int Bcnt,Bid[200005],Bl[200005],Br[200005];
	ll k[200005];
	Vec a[200005],b[200005];
	struct node{
		Vec qwq;
		int id;
		bool operator <(const node &a)const{
			return qwq<a.qwq;
		}
	}ovo[200005];
	Vec q[200005];
	int tot[200005];
	void B_build(){
		B=600;
		Bcnt=0;
		for (int i=1;i<=n;i++){
			if (i%B==1){
				++Bcnt;
				Bl[Bcnt]=i;
			}
			Bid[i]=Bcnt;
			Br[Bcnt]=i;
		}
		return;
	}
	void pushup(int id){
		for (int i=Bl[id];i<=Br[id];i++)a[i].y-=a[i].x*k[id];
		k[id]=0;
		int qwql=Bl[id];
		tot[id]=qwql;
		tot[id]--;
		for (int i=Bl[id];i<=Br[id];i++)b[i]=a[ovo[i].id];
		for (int i=Bl[id];i<=Br[id];){
			Vec qwq;
			qwq.x=b[i].x,qwq.y=b[i].y;
			int j=i;
			while(j<=Br[id]&&b[j].x==b[i].x){
				if (b[j].y>qwq.y)qwq=b[j];
				j++;
			}
			while(tot[id]>qwql&&cmp(qwq-q[tot[id]-1],qwq-q[tot[id]]))tot[id]--;
			tot[id]++;
			q[tot[id]]=qwq;
			i=j;
		}
		return;
	}
	void qwq_mem(){
		memset(k,0,sizeof(k));
		for (int i=1;i<=Bcnt;i++){
			for (int j=Bl[i];j<=Br[i];j++)ovo[j].qwq=a[j],ovo[j].id=j;
			sort(ovo+Bl[i],ovo+Br[i]+1);
			pushup(i);
		}
		return;
	}
	void add(int l,int r,ll val){
		int lid=Bid[l],rid=Bid[r];
		if (lid==rid){
			for (int i=l;i<=r;i++)a[i].y+=a[i].x*val;
			pushup(lid);
			return;
		}
		for (int i=l;i<=Br[lid];i++)a[i].y+=a[i].x*val;
		for (int i=Bl[rid];i<=r;i++)a[i].y+=a[i].x*val;
		pushup(lid),pushup(rid);
		for (int i=lid+1;i<=rid-1;i++)k[i]-=val;
		return;
	}
	ll Block_ask(int id){
		if (Bl[id]>tot[id])return 0;
		int l=Bl[id],r=tot[id]-1,pos=tot[id];
		Vec awa;
		awa.y=k[id],awa.x=1;
		while(l<=r){
			int mid=(l+r)/2;
		 	if (cmp(q[mid+1]-q[mid],awa)==1)pos=mid,r=mid-1;
		 	else l=mid+1;
		}
		return -k[id]*q[pos].x+q[pos].y;
	}
	ll ask(int l,int r){
		int lid=Bid[l],rid=Bid[r];
		ll ans=0;
		if (lid==rid){
			pushup(lid);
			for (int i=l;i<=r;i++)ans=max(ans,a[i].y);
			return ans;
		}
		for (int i=l;i<=Br[lid];i++)ans=max(ans,a[i].y-a[i].x*k[lid]);
		for (int i=Bl[rid];i<=r;i++)ans=max(ans,a[i].y-a[i].x*k[rid]);
		for (int i=lid+1;i<=rid-1;i++)ans=max(ans,Block_ask(i));
		return ans;
	}
}B1,B2;
ll s1[200005],s2[200005];
int idx,l[200005],r[200005];
void dfs(int now,int fa){
	s1[now]=s1[fa]+a[now];
	s2[now]=s2[fa]+b[now];
	++idx;
	(B1.a[idx]).x=qwqabs(s2[now]),(B2.a[idx]).x=qwqabs(s2[now]);
	(B1.a[idx]).y=s1[now]*qwqabs(s2[now]),(B2.a[idx]).y=-s1[now]*qwqabs(s2[now]);
	l[now]=idx;
	for (int i=first[now];i;i=nxt[i])dfs(v[i],now);
	r[now]=idx;
	return;
}
signed main(){
	cin>>n>>q;
	for (int i=2;i<=n;i++){
		u[i]=read(),v[i]=i;
		nxt[i]=first[u[i]],first[u[i]]=i;
	}
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)b[i]=read();
	B1.B_build();
	B2.B_build();
	dfs(1,0);
	B1.qwq_mem();
	B2.qwq_mem();
	while(q--){
		int opt,x,y;
		opt=read();
		if (opt==1){
			x=read(),y=read();
			B1.add(l[x],r[x],y);
			B2.add(l[x],r[x],-y);
		}
		else{
			x=read();
			ll ans=max(B1.ask(l[x],r[x]),B2.ask(l[x],r[x]));
			printf("%lld\n",ans);
		}
	}
	return 0;
}