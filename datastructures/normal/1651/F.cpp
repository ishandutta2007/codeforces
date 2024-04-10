#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 2000000000
#define inf 1000000000000000000
#define ll long long
using namespace std;
ll read(){
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct tree_node{
	int l,r;
	ll val;
	tree_node(){
		l=r=val=0;
		return;
	}
}tree[13000005];
int cnt,root1[200005],root2[200005];
void ins(int &now,int nowl,int nowr,int pos,ll val){
	int pre=now;
	now=++cnt;
	tree[now]=tree[pre];
	tree[now].val+=val;
	if (nowl==nowr)return;
	int mid=(nowl+nowr)/2;
	if (pos<=mid)ins(tree[now].l,nowl,mid,pos,val);
	else ins(tree[now].r,mid+1,nowr,pos,val);
	return;
}
ll ask(int now,int nowl,int nowr,int lt,int rt){
	if (now==0)return 0;
	if (nowl>=lt&&nowr<=rt)return tree[now].val;
	int mid=(nowl+nowr)/2;
	ll s=0;
	if (mid>=lt)s+=ask(tree[now].l,nowl,mid,lt,rt);
	if (mid+1<=rt)s+=ask(tree[now].r,mid+1,nowr,lt,rt);
	return s;
}
int n,q;
ll c[200005],r[200005],x,y;
int sta[200005],tot;
ll t[200005],val[200005];
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)c[i]=read(),r[i]=read();
	for (int i=1;i<=n;i++){
		root1[i]=root1[i-1];
		ins(root1[i],0,maxn,c[i]/r[i],r[i]);
		root2[i]=root2[i-1];
		ins(root2[i],0,maxn,c[i]/r[i],c[i]);
	}
	++tot;
	sta[tot]=n+1;
	t[tot]=-maxn/2;
	val[tot]=inf;
	c[n+1]=inf;
	cin>>q;
	while(q--){
		x=read(),y=read();
		sta[tot+1]=0;
		while(tot>0){
			ll sum=(ask(root1[sta[tot]-1],0,maxn,x-t[tot],maxn)-ask(root1[sta[tot+1]],0,maxn,x-t[tot],maxn))*(x-t[tot]);
			sum+=(ask(root2[sta[tot]-1],0,maxn,0,x-t[tot]-1)-ask(root2[sta[tot+1]],0,maxn,0,x-t[tot]-1));
			if (sum<=y){
				y-=sum;
				ll qwq=min(c[sta[tot]],val[tot]+(x-t[tot])*r[sta[tot]]);
				if (y<=qwq){
					t[tot]=x;
					val[tot]=qwq-y;
					break;
				}
				else{
					y-=qwq;
					tot--;
				}
			}
			else{
				int lt=sta[tot+1],rt=sta[tot]-1,pos=0;
				ll awa=ask(root1[sta[tot+1]],0,maxn,x-t[tot],maxn)*(x-t[tot])+ask(root2[sta[tot+1]],0,maxn,0,x-t[tot]-1);
				while(lt<=rt){
					int mid=(lt+rt)/2;
					if (ask(root1[mid],0,maxn,x-t[tot],maxn)*(x-t[tot])+ask(root2[mid],0,maxn,0,x-t[tot]-1)-awa<=y)pos=mid,lt=mid+1;
					else rt=mid-1;
				}
				y-=ask(root1[pos],0,maxn,x-t[tot],maxn)*(x-t[tot])+ask(root2[pos],0,maxn,0,x-t[tot]-1)-awa;
				ll qwqt=t[tot];
				++tot;
				sta[tot]=pos+1;
				t[tot]=x;
				val[tot]=min(c[pos+1],r[pos+1]*(x-qwqt))-y;
				break;
			}
		}
	}
	cout<<inf-val[1]<<endl;
	return 0;
}