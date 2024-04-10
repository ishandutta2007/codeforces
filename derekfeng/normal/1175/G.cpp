#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,k,a[200005];
int f[20005],g[20005];
int F(pii a,int x){
	return a.fi*x+a.se;
}
struct SegTreeStack{
	int tot;
	pii dat[400005];
	int s[2][400005];
	void init(){
		tot=0;
	}
	int ins(int i,int l,int r,pii x){
		if(!i){
			i=++tot,s[0][i]=s[1][i]=0;
			dat[i]=x;return i;
		}
		int md=(l+r)>>1;pii y=dat[i];
		int resx=F(x,md);
		int resy=F(y,md);
		if(resx<resy)dat[i]=x;
		if(l==r)return i;
		if(x.fi<y.fi){
			if(resx<resy)s[0][i]=ins(s[0][i],l,md,y);
			else s[1][i]=ins(s[1][i],md+1,r,x);
		}else{
			if(resx<resy)s[1][i]=ins(s[1][i],md+1,r,y);
			else s[0][i]=ins(s[0][i],l,md,x);
		}
		return i;
	}
	int mrg(int i1,int i2,int l,int r){
		if(!i1||!i2)return i1|i2;
		int md=(l+r)>>1;
		pii x=dat[i1],y=dat[i2];
		s[0][i1]=mrg(s[0][i1],s[0][i2],l,md);
		s[1][i1]=mrg(s[1][i1],s[1][i2],md+1,r);
		int resx=F(x,md);
		int resy=F(y,md);
		if(resy<resx)dat[i1]=y;
		if(l==r)return i1;
		if(x.fi<y.fi){
			if(resx<resy)s[0][i1]=ins(s[0][i1],l,md,y);
			else s[1][i1]=ins(s[1][i1],md+1,r,x);
		}else{
			if(resx<resy)s[1][i1]=ins(s[1][i1],md+1,r,y);
			else s[0][i1]=ins(s[0][i1],l,md,x);
		}
		return i1;
	}
	int qry(int i,int l,int r,int p){
		if(!i)return 1e9;
		int ret=F(dat[i],p);
		if(l==r)return ret;
		int md=(l+r)>>1;
		if(p<=md)ret=min(ret,qry(s[0][i],l,md,p));
		else ret=min(ret,qry(s[1][i],md+1,r,p));
		return ret;
	}
}tr1;
struct SegTreeAns{
	int tot;
	pii dat[400005];
	int s[2][400005];
	void init(){
		tot=0;
		dat[0]={0,1e9},s[0][0]=s[1][0]=0;
	}	
	int ins(int id,int l,int r,pii x){
		int i=++tot;
		dat[i]=dat[id];
		s[0][i]=s[0][id],s[1][i]=s[1][id];
		int md=(l+r)>>1;pii y=dat[i];
		int resx=F(x,md);
		int resy=F(y,md);
		if(resx<resy)dat[i]=x;
		if(l==r)return i;
		if(x.fi<y.fi){
			if(resx<resy)s[0][i]=ins(s[0][i],l,md,y);
			else s[1][i]=ins(s[1][i],md+1,r,x);
		}else{
			if(resx<resy)s[1][i]=ins(s[1][i],md+1,r,y);
			else s[0][i]=ins(s[0][i],l,md,x);
		}
		return i;
	}
	int qry(int i,int l,int r,int p){
		if(!i)return 1e9;
		int ret=F(dat[i],p);
		if(l==r)return ret;
		int md=(l+r)>>1;
		if(p<=md)ret=min(ret,qry(s[0][i],l,md,p));
		else ret=min(ret,qry(s[1][i],md+1,r,p));
		return ret;
	}
}tr2;
int main(){
	scanf("%d%d",&n,&k);
	int mx=0;f[0]=1e9;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]),f[i]=i*mx;
	}
	for(int t=2;t<=k;t++){
		memset(g,0x3f,sizeof(g));
		tr1.init(),tr2.init();
		stack<pair<int,pii> >sta;
		sta.push({1e9,{0,0}});
		for(int i=1;i<=n;i++){
			int r=0;
			while(sta.top().fi<a[i]){
				pair<int,pii>t=sta.top();sta.pop();
				r=tr1.mrg(r,t.se.fi,1,2e4);
			}
			r=tr1.ins(r,1,2e4,{-(i-1),f[i-1]});
			int rr=tr2.ins(sta.top().se.se,1,n,{a[i],tr1.qry(r,1,2e4,a[i])}); 
			sta.push({a[i],{r,rr}});
			g[i]=tr2.qry(rr,1,n,i);
		}
		memcpy(f,g,sizeof(f));
	}
	printf("%d",f[n]);
}