#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(19260817);
int n,tot;
int key[1000005],sz[1000005],s[2][1000005];
ll d[1000005],d_tag[1000005];
int node(ll x){
	int i=++tot;
	d[i]=x,sz[i]=1;
	key[i]=rng();
	return i;
}
void push(int i,ll D){
	d[i]+=D,d_tag[i]+=D;
}
void pushdown(int i){
	if(d_tag[i]){
		if(s[0][i])push(s[0][i],d_tag[i]);
		if(s[1][i])push(s[1][i],d_tag[i]);
		d_tag[i]=0;
	}
}
void pushup(int i){
	sz[i]=sz[s[0][i]]+sz[s[1][i]]+1;
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	int i;
	if(key[x]<key[y])i=x,pushdown(i),s[1][i]=merge(s[1][i],y);
	else i=y,pushdown(i),s[0][i]=merge(x,s[0][i]);
	pushup(i);
	return i;
}
int w,rt,sm;
void split(int i,int &x,int &y){
	if(!i){x=y=0;return;}
	pushdown(i);
	if((ll)(sm+sz[s[0][i]]+1)*w>d[i])y=i,split(s[0][i],x,s[0][i]);
	else sm+=sz[s[0][i]]+1,x=i,split(s[1][i],s[1][i],y);
	pushup(i);
}
ll ans,cur;
void iter(int i){
	if(!i)return;
	pushdown(i);
	iter(s[0][i]);
	cur+=d[i],ans=max(ans,cur);
	iter(s[1][i]);
}
int main(){
//	freopen("opt.in","r",stdin);
//	freopen("opt.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&w);
		int A,B;
		sm=0,split(rt,A,B);
		int t=node((ll)(sz[A]+1)*w);
		if(B)push(B,w);
		rt=merge(A,merge(t,B));
	//	cur=0;iter(cur);puts("");
	}
	iter(rt);
	printf("%lld",ans);
}