#include<bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define pb push_back
#define ii pair<int,int>
#define ppb pop_back
#define orta ((bas+son)>>1)
#define st first
#define nd second
#define ll long long
#define N 2000005
#define inf 200000000000000000
#define MOD 998244353
#define LOG 32
#define M 305
using namespace std;

struct query {

	int x,y,c;

}Q[N];

int q;
int d;
int go[4][2]={0,1,1,0,-1,0,0,-1};
int prv[N];
int a[M*M];
int ans[N];
int n,m;
int cur,bf;
int dad[M*M];

int find(int x) {

	if(dad[x]==x) return x;
	return dad[x]=find(dad[x]);

}

void merge(int x,int y) {

	x=find(x);
	y=find(y);
	if(x==y) return ;
	cur--;
	dad[x]=y;

}

ii dcp(int node) {
	return {(node+m-1)/m,node%m?node%m:m};
}

int getnode(int x,int y) {
	return (x-1)*m+y;
}

void look(int node,int i) {

	for(int j=0;j<4;j++) {
		int x=Q[i].x+go[j][0];
		int y=Q[i].y+go[j][1];
		if(x<1 || y<1 || x>n || y>m) continue ;
		int node2=getnode(x,y);
		if(a[node2]==a[node]) {
			merge(node,node2);
		}
	}

}

void dfs(int node) {

	if(dad[node]) return ;
	ii pos=dcp(node);
	dad[node]=d;
	for(int i=0;i<4;i++) {
		int x=pos.st+go[i][0];
		int y=pos.nd+go[i][1];
		if(x>n || y>m || x<1 || y<1) continue ;
		int to=getnode(x,y);
		if(a[to]==a[node])
			dfs(to);
	}

}

int main() {

	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=q;i++) {
		scanf("%d %d %d",&Q[i].x,&Q[i].y,&Q[i].c);
	}
	fill(dad+1,dad+1+n*m,1);
	cur=1;bf=0;
	for(int i=1;i<=q;i++) {
		int node=getnode(Q[i].x,Q[i].y);
		prv[i]=a[node];
		if(bf!=Q[i].c) {
			for(int j=1;j<=n*m;j++) {
				if(a[j]<Q[i].c) {
					if(find(j)==j)
						cur--;
					dad[j]=0;
				}
			}
		}
		if(a[node]<Q[i].c) {
			dad[node]=node;
			cur++;
		}
		a[node]=Q[i].c;
		look(node,i);
		ans[i]+=cur;
		bf=Q[i].c;
	}
	bf=10005;cur=0;
	fill(dad+1,dad+n*m+1,0);
	for(int i=1;i<=n*m;i++) {
		if(!dad[i]) {
			++cur;
			d=i;
			dfs(i);
		}
	}
	for(int i=q;i>=1;i--) {
		int node=getnode(Q[i].x,Q[i].y);
		if(bf!=Q[i].c) {
			for(int j=1;j<=n*m;j++) {
				if(a[j]>=Q[i].c) {
					if(find(j)==j)
						cur--;
					dad[j]=0;
				}
			}
		}
		ans[i]+=cur;
		a[node]=prv[i];
		if(a[node]<Q[i].c) {
			dad[node]=node;
			cur++;
			look(node,i);
		}	
		bf=Q[i].c;
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);

}