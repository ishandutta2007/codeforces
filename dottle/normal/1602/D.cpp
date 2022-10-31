#include<bits/stdc++.h>
#define mid (l+r>>1)
const int N=3.1e5,M=N<<5;
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}


int n,id[N],rt,node,lc[M],rc[M],suf[N],a[N],b[N],rev[M],pr[M]; 
#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx,w;
}e[M];int hd[M],S;
void add(int fr,int to,int w){
    e[++S]=(edge){to,hd[fr],w},hd[fr]=S;
}
int dis[M],v[M];
priority_queue<pair<int,int>> q;

int cnt;
int build(int l,int r){
	int k=++cnt;
	if(l==r){id[l]=k,rev[k]=l+1;return k;}
	lc[k]=build(l,mid),rc[k]=build(mid+1,r);
	add(k,lc[k],0),add(k,rc[k],0);
	return k;
}

void upd(int k,int l,int r,int x,int y,int st){
	if(x>r||y<l)return;
	if(x<=l&&y>=r)return add(st,k,1);
	upd(lc[k],l,mid,x,y,st);
	upd(rc[k],mid+1,r,x,y,st);
}

void print(int u) {
	if(pr[u])
		print(pr[u]);
	if(rev[u]) 
		cout<<rev[u]-1<<' ';
}

int main() {
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	rt=build(0,n);
	for(int i=1;i<=n;i++)
		suf[i]=++cnt;
	for(int i=1;i<=n;i++) 
		add(id[i],suf[i+b[i]],0);
	for(int i=1;i<=n;i++) 
		upd(rt,0,n,i-a[i],i,suf[i]);
	for(int i=1;i<=cnt;i++)
		dis[i]=2147483647;
	int s=suf[n];
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		auto nw=q.top();q.pop();
		if(v[nw.second])continue;
		v[nw.second]=1;
		fore(nw.second)
			if(dis[nw.second]+e[i].w<dis[_to]){
				dis[_to]=dis[nw.second]+e[i].w;
				pr[_to]=nw.second;
				q.push({-dis[_to],_to});
			}
	}
	if(dis[id[0]]==2147483647)
		cout<<-1<<endl;
	else{
		cout<<dis[id[0]]<<endl;
		print(id[0]);
	}
	return 0;
}