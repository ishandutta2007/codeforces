#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long int LLI;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int a[100000],b[100000];
LLI c[100000];
vector<pair<int,LLI> > adjList[100000];
int disc[100000],fin[100000],num = 0;
LLI dist[200000];
int doDFS(int u,int p,LLI d) {
	int i;
	disc[u] = num++,dist[num-1] = d;
	for (i = 0; i < adjList[u].size(); i++) {
		int v = adjList[u][i].first;
		if (v != p) doDFS(v,u,d+adjList[u][i].second),dist[num++] = d;
	}
	fin[u] = num;
	return 0;
}
struct node { LLI b,ac,ab,bc,abc; };
node tree[1 << 19];
LLI lazy[1 << 19];
node com(node a,node b) {
	node c;
	c.b = max(a.b,b.b),c.ac = max(a.ac,b.ac);
	c.ab = max(max(a.ab,b.ab),a.ac+b.b),c.bc = max(max(a.bc,b.bc),a.b+b.ac);
	c.abc = max(max(a.abc,b.abc),max(a.ac+b.bc,a.ab+b.ac));
	return c;
}
int prop(int s,int e,int i) {
	tree[i].b -= 2*lazy[i],tree[i].ac += lazy[i];
	tree[i].ab -= lazy[i],tree[i].bc -= lazy[i];
	if (s != e) lazy[2*i+1] += lazy[i],lazy[2*i+2] += lazy[i];
	lazy[i] = 0;
	return 0;
}
int build(int s,int e,int i) {
	if (s == e) {
		tree[i] = (node){-2*dist[s],dist[s],-dist[s],-dist[s],0};
		return 0;
	}
	
	int mid = (s+e) / 2;
	build(s,mid,2*i+1),build(mid+1,e,2*i+2);
	tree[i] = com(tree[2*i+1],tree[2*i+2]);
	return 0;
}
int update(int s,int e,int as,int ae,int i,LLI num) {
	prop(s,e,i);
	if ((s > ae) || (e < as)) return 0;
	else if ((s >= as) && (e <= ae)) {
		lazy[i] += num;
		prop(s,e,i);
		return 0;
	}
	
	int mid = (s+e) / 2;
	update(s,mid,as,ae,2*i+1,num),update(mid+1,e,as,ae,2*i+2,num);
	tree[i] = com(tree[2*i+1],tree[2*i+2]);
	return 0;
}
int main() {
	int i;
	int n,q,d;
	LLI w,e,last = 0;
	scanf("%d %d %lld",&n,&q,&w);
	for (i = 0; i < n-1; i++) {
		scanf("%d %d %lld",&a[i],&b[i],&c[i]);
		a[i]--,b[i]--;
		adjList[a[i]].pb(mp(b[i],c[i]));
		adjList[b[i]].pb(mp(a[i],c[i]));
	}
	doDFS(0,-1,0);
	build(0,num-1,0);
	for (i = 0; i < q; i++) {
		scanf("%d %lld",&d,&e);
		d = (d+last) % (n-1),e = (e+last) % w;
		if (disc[b[d]] < disc[a[d]]) swap(a[d],b[d]);
		update(0,num-1,disc[b[d]],fin[b[d]]-1,0,e-c[d]);
		c[d] = e,last = tree[0].abc;
		printf("%lld\n",last);
	}
	
	return 0;
}