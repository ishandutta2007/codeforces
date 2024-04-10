#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;

int n,m,i,j,k,x,y,vis[maxn],ans,nm[maxn];
int em,e[maxn*2],nx[maxn*2],ls[maxn],tot;
struct node{
	int x,i;
	node(int _x=0,int _i=0){x=_x,i=_i;}
} d[maxn];
int operator<(node a,node b){return a.x<b.x||a.x==b.x&&a.i<b.i;}


void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

void down(int x){
	for(int y=x*2;y<=tot&&d[y]<d[x]||y+1<=tot&&d[y+1]<d[x];x=y,y=x*2){
		if (y+1<=tot&&d[y+1]<d[y]) y++;
		swap(d[x],d[y]);
		nm[d[x].i]=x,nm[d[y].i]=y;
	}
}

void up(int x){
	for(int y=x/2;y&&d[x]<d[y];x=y,y=x/2){
		swap(d[x],d[y]);
		nm[d[x].i]=x,nm[d[y].i]=y;
	}
	down(x);
}

void change(int x){
	d[x].x++;
	down(x);
}

void del(int x){
	swap(d[x],d[tot]),tot--;
	if (x<=tot) nm[d[x].i]=x,up(x);
}

void add(node p){
	++tot,nm[p.i]=tot,d[tot]=p;
	up(tot);
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
	for(i=1;i<=n;i++) add(node(0,i));
	for(i=0;i<n;i++) {
		node tmp=d[1];
		if (tmp.x==i) ans++;
		x=tmp.i,vis[x]=1;
		for(j=ls[x];j;j=nx[j]) if (!vis[e[j]]) 	
			change(nm[e[j]]);
		del(1);
	}
	printf("%d",ans-1);
}