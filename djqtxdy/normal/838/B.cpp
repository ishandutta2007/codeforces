#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;
// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=400005;
vector<pair<int,int> > G[Maxn];
int st[Maxn],ed[Maxn];
struct Segtree{
	long long tree[Maxn*4],tag[Maxn*4];
	Segtree(){
		for (int i=0;i<Maxn*4;i++) tree[i]=0,tag[i]=0;
	}
	void Push(int p){
		tag[p*2]+=tag[p];
		tag[p*2+1]+=tag[p];
		tag[p]=0;
	}
	void Pull(int p){
		tree[p]=min(tree[p*2]+tag[p*2],tree[p*2+1]+tag[p*2+1]);
	}
	void modify_range(int p,int l,int r,int lo,int hi,LL val){
		if (lo<=l && r<=hi){
			tag[p]+=val;
			return;
		}
		Push(p);
		int mid=(l+r)>>1;
		if (lo<=mid){
			modify_range(p*2,l,mid,lo,min(hi,mid),val);
		}
		if (hi>mid){
			modify_range(p*2+1,mid+1,r,max(lo,mid+1),hi,val);
		}
		Pull(p);
	}
	long long query(int p,int l,int r,int lo,int hi){
		if (lo<=l && r<=hi){
			return tree[p]+tag[p];
		}
		Push(p);
		int mid=(l+r)>>1;
		long long ans=1e15;
		if (lo<=mid){
			ans=min(ans,query(p*2,l,mid,lo,min(hi,mid)));
		}
		if (hi>mid){
			ans=min(ans,query(p*2+1,mid+1,r,max(lo,mid+1),hi));
		}
		Pull(p);
		return ans;
	}
}tr1,tr2;
int U[Maxn],V[Maxn],C[Maxn];
int cnt;
void dfs(int v){
//-	cout<<v<<endl;
	st[v]=++cnt;
	for (int i=0;i<G[v].size();i++){
		dfs(G[v][i].first);
	}
	ed[v]=cnt;
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for (int i=0;i<n-1;i++){
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		U[i]=u,V[i]=v,C[i]=c;
		G[u].push_back(mp(v,c));
	}
	dfs(1);
	for (int i=0;i<n-1;i++){
		tr1.modify_range(1,1,cnt,st[V[i]],ed[V[i]],C[i]);
		tr2.modify_range(1,1,cnt,st[V[i]],ed[V[i]],C[i]);
	}
	for (int i=0;i<n-1;i++){
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		U[i+n-1]=u,V[i+n-1]=v,C[i+n-1]=c;
		tr2.modify_range(1,1,cnt,st[U[i+n-1]],st[U[i+n-1]],C[i+n-1]);
	}
	for (int i=0;i<q;i++){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			int j,w;
			scanf("%d %d",&j,&w);
			j--;
			w-=C[j];
			if (j<=n-2){
				tr1.modify_range(1,1,cnt,st[V[j]],ed[V[j]],w);
				tr2.modify_range(1,1,cnt,st[V[j]],ed[V[j]],w);
			}
			else{
				tr2.modify_range(1,1,cnt,st[U[j]],st[U[j]],w);
			}
			C[j]+=w;
		}
		else{
			int u,v;
			scanf("%d %d",&u,&v);
			if (st[u]<=st[v] && ed[v]<=ed[u]){
				printf("%I64d\n",-tr1.query(1,1,cnt,st[u],st[u])+tr1.query(1,1,cnt,st[v],st[v]));
			}
			else{
				printf("%I64d\n",tr1.query(1,1,cnt,st[v],st[v])+tr2.query(1,1,cnt,st[u],ed[u])-tr1.query(1,1,cnt,st[u],st[u]));
			}
		}
	}
	return 0;
}