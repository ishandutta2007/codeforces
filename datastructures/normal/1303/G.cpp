#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
ll Mx(ll a,ll b){
	return a>b?a:b;
}
struct node{
	ll k,b;
	node(){
		k=b=0;
		return;
	}
}tree[600005];
void ins(int now,int nowl,int nowr,ll k,ll b){
	int fg1=0,fg2=0;
	if (k*nowl+b>=tree[now].k*nowl+tree[now].b)fg1=1;
	if (k*nowr+b>=tree[now].k*nowr+tree[now].b)fg2=1;
	if (fg1==1&&fg2==1){
		tree[now].k=k;
		tree[now].b=b;
		return;
	}
	int mid=(nowl+nowr)>>1;
	if (fg1==0&&fg2==0)return;
	if (k*mid+b>tree[now].k*mid+tree[now].b)swap(k,tree[now].k),swap(b,tree[now].b);
	if (k<tree[now].k)ins(now<<1,nowl,mid,k,b);
	if (k>tree[now].k)ins(now<<1|1,mid+1,nowr,k,b);
	return;
}
ll ask(int now,int nowl,int nowr,int pos){
	ll ans=tree[now].k*pos+tree[now].b;
	if (nowl==nowr)return ans;
	int mid=(nowl+nowr)>>1;
	if (pos<=mid)ans=Mx(ans,ask(now<<1,nowl,mid,pos));
	else ans=Mx(ans,ask(now<<1|1,mid+1,nowr,pos));
	return ans;
}
void clear(int now){
	if (tree[now].k==0&&tree[now].b==0)return;
	tree[now].k=0,tree[now].b=0;
	clear(now*2),clear(now*2+1);
	return;
}
int n,a[150005],u[300005],v[300005],first[150005],nxt[300005];
int book[150005];
int rt,size[150005],qwq,mn,md;
ll ans;
void getroot(int now,int fa){
	size[now]=1;
	int mx=0;
	for (int i=first[now];i&&rt==0;i=nxt[i])
		if (v[i]!=fa&&book[v[i]]==0){
			getroot(v[i],now);
			size[now]+=size[v[i]];
			mx=max(mx,size[v[i]]);
		}
	mx=max(mx,qwq-size[now]);
	if (mx*2<=qwq)rt=now;
	return;
}
void getsize(int now,int fa,int d){
	md=max(md,d);
	size[now]=1;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa&&book[v[i]]==0){
			getsize(v[i],now,d+1);
			size[now]+=size[v[i]];
		}
	return;
}
int son[150005],tot;
void calc_ins(int now,int fa,int d,ll nows,ll nowv){
	int fg=0;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa&&book[v[i]]==0){
			calc_ins(v[i],now,d+1,nows+a[v[i]],nowv+1ll*(d+1)*a[v[i]]);
			fg=1;
		}
	if (fg==0)ins(1,1,n,nows,nowv);
	return;
}
void calc_ask(int now,int fa,int d,ll nows,ll nowv){
	int fg=0;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]!=fa&&book[v[i]]==0){
			calc_ask(v[i],now,d+1,nows+a[v[i]],nowv+nows+a[v[i]]);
			fg=1;
		}
	}
	if (fg==0)ans=Mx(ans,ask(1,1,n,d)+nowv);
	return;
}
void dfs(int now){
	book[now]=1;
	tot=0;
	for (int i=first[now];i;i=nxt[i]){
		if (book[v[i]]==1)continue;
		son[++tot]=v[i];
	}
	for (int i=1;i<=tot;i++){
		ans=Mx(ans,ask(1,1,md,1)+a[now]);
		calc_ask(son[i],0,2,a[now]+a[son[i]],2*a[now]+a[son[i]]);
		calc_ins(son[i],0,1,a[son[i]],a[son[i]]);
	}
	ans=Mx(ans,ask(1,1,md,1)+a[now]);
	clear(1);
	for (int i=tot;i>=1;i--){
		ans=Mx(ans,ask(1,1,n,1)+a[now]);
		calc_ask(son[i],0,2,a[now]+a[son[i]],2*a[now]+a[son[i]]);
		calc_ins(son[i],0,1,a[son[i]],a[son[i]]);
	}
	ans=Mx(ans,ask(1,1,md,1)+a[now]);
	clear(1);
	for (int i=first[now];i;i=nxt[i]){
		if (book[v[i]]==1)continue;
		rt=0,qwq=size[v[i]],mn=1e9;
		getroot(v[i],0);
		getsize(rt,0,1);
		dfs(rt);
	}
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	for (int i=1;i<=n;i++)a[i]=read();
	rt=0,qwq=n,mn=1e9;
	getroot(1,0);
	getsize(rt,0,1);
	dfs(rt);
	cout<<ans<<endl;
	return 0;
}