#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define int long long
#define maxn 131072
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write_num(int x){
	if (x==0)return;
	write_num(x/10);
	putchar(x%10+'0');
	return;
}
void write(int x){
	if (x<0)putchar('-'),x=-x;
	if (x==0)putchar('0');
	write_num(x);
	putchar(' ');
	return;
}
int n,q,s,opt,x,l,r,y;
int totm,u[5000005],v[5000005],w[5000005],first[5000005],nxt[5000005];
void add(int a,int b,int c){
	int i=++totm;
	u[i]=a,v[i]=b,w[i]=c;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
struct node{
	int id,dis;
	bool operator <(const node &x)const{
		return x.dis<dis;
	}
};
node make_node(int id,int dis){
	node ans;
	ans.id=id,ans.dis=dis;
	return ans;
}
priority_queue<node> h;
int dis[5000005];
void dijkstra(int s){
	memset(dis,0x7f,sizeof(dis));
	dis[s]=0;
	h.push(make_node(s,dis[s]));
	while(!h.empty()){
		int now=(h.top()).id;
		h.pop();
		for (int i=first[now];i;i=nxt[i])
			if (dis[v[i]]>dis[now]+w[i]){
				dis[v[i]]=dis[now]+w[i];
				h.push(make_node(v[i],dis[v[i]]));
			}
	}
	return;
}
int build1(int now,int nowl,int nowr){
	if (nowl==nowr)return nowl;
	int mid=(nowl+nowr)/2;
	int l=build1(now*2,nowl,mid),r=build1(now*2+1,mid+1,nowr);
	add(l,2*maxn+now,0);
	add(r,2*maxn+now,0);
	return 2*maxn+now;
}
int build2(int now,int nowl,int nowr){
	if (nowl==nowr)return nowl+maxn;
	int mid=(nowl+nowr)/2;
	int l=build2(now*2,nowl,mid),r=build2(now*2+1,mid+1,nowr);
	add(3*maxn+now,l,0);
	add(3*maxn+now,r,0);
	return 3*maxn+now;
}
void update(int now,int nowl,int nowr,int lt,int rt,int x,int val){
	if (nowl>=lt&&nowr<=rt){
		int y;
		if (nowl==nowr){
			if (x>0)y=nowl+maxn;
			else y=nowl;
		}
		else{
			if (x>0)y=now+3*maxn;
			else y=now+2*maxn;
		}
		if (x>0)add(x,y,val);
		else add(y,-x+maxn,val);
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)update(now*2,nowl,mid,lt,rt,x,val);
	if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,x,val);
	return;
}
signed main(){
	cin>>n>>q>>s;
	build1(1,1,n);
	build2(1,1,n);
	for (int i=1;i<=n;i++)add(i,i+maxn,0),add(i+maxn,i,0);
	while(q--){
		opt=read();
		if (opt==1){
			x=read(),l=read(),y=read();
			add(x,l+maxn,y);
		}
		if (opt==2){
			x=read(),l=read(),r=read(),y=read();
			update(1,1,n,l,r,x,y);
		}
		if (opt==3){
			x=read(),l=read(),r=read(),y=read();
			update(1,1,n,l,r,-x,y);
		}
	}
	dijkstra(s);
	for (int i=1;i<=n;i++)
		if (dis[i+maxn]<=1e18)write(dis[i+maxn]);
		else write(-1);
	return 0;
}