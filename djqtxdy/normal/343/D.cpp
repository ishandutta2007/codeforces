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
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}

// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=500005;
struct segtree{
	vector<int> tree;
	int n;
	void resize(int val){
		tree.resize(4*val);
		n=val;
	}
	void modify(int p,int l,int r,int pos,int val){
		if (l==r){
			tree[p]=val;
			return ;
		} 
		int mid=(l+r)>>1;
		if (pos<=mid){
			modify(p*2,l,mid,pos,val);
		}else{
			modify(p*2+1,mid+1,r,pos,val);
		} 
		tree[p]=max(tree[p*2],tree[p*2+1]);
	}
	int query(int p,int l,int r,int lo,int hi){
		if (lo<=l && r<=hi){
			return tree[p];
		}
		int mid=(l+r)>>1;
		int ans=0;
		if (lo<=mid){
			ans=max(ans,query(p*2,l,mid,lo,min(hi,mid)));
		}
		if (hi>mid){
			ans=max(ans,query(p*2+1,mid+1,r,max(lo,mid+1),hi));
		}
		return ans;
	}
	void Modify(int pos,int val){
		modify(1,1,n,pos,val);
	}
	int Query(int lo,int hi){
		return query(1,1,n,lo,hi);
	}
}tree1;
struct chain{
	segtree tree;
	vector<int> vert;
	int chainbeg;
	void _(){
		tree.resize(vert.size());
		chainbeg=vert[0];
	}
	void modify(int pos,int val){
		tree.Modify(pos,val);
	}
	int query(int lo,int hi){
		return tree.Query(lo,hi);
	}
};
int cnt;
int st[Maxn],ed[Maxn];
int siz[Maxn];
bool vis[Maxn];
vector<int> G[Maxn];
int p[Maxn],belongchain[Maxn];
int chnum[Maxn];
vector<chain> chains;
void dfs(int x){
	st[x]=++cnt;
	vis[x]=true;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!vis[v]){
			dfs(v);
			siz[x]+=siz[v];
			p[v]=x;
		}
	}
	siz[x]++;
	ed[x]=cnt;
}
void heavy_light(int x,int chainnum,int id){
	chains[chainnum].vert.push_back(x);
	belongchain[x]=chainnum;
	chnum[x]=id;
	vis[x]=true;
	int mxsiz=0;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!vis[v]) mxsiz=max(mxsiz,siz[v]);
	}
	int xx;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!vis[v] && siz[v]==mxsiz){
			heavy_light(v,chainnum,id+1);
			xx=v;
			break;
		}
	}
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!vis[v] && v!=xx){
			chain tmp;
			chains.push_back(tmp);
			heavy_light(v,chains.size()-1,1);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	memset(vis,false,sizeof(vis));
	dfs(1);
	chain tmp;
	tree1.resize(cnt);
	chains.push_back(tmp);
	memset(vis,false,sizeof(vis));
	heavy_light(1,0,1);
	for (int i=0;i<chains.size();i++){
		chains[i]._();
		/* 
		for (int j=0;j<chains[i].vert.size();j++){
			printf("%d ",chains[i].vert[j]);
		}
		printf("\n");*/ 
	}
	/* 
	for (int i=1;i<=n;i++){
		cout<<belongchain[i]<<' '<<chnum[i]<<endl;
	}*/ 
	int q;
	scanf("%d",&q);
	for (int tim=1;tim<=q;tim++){
		int tp;
		scanf("%d",&tp);
		if (tp==2){
			int x;
			scanf("%d",&x);
			tree1.Modify(st[x],tim);
		}
		else if (tp==1){
			int x;
			scanf("%d",&x);
			int id=belongchain[x];
			chains[id].modify(chnum[x],tim);
		}
		else{
			int x;
			scanf("%d",&x);
			int Empty=tree1.Query(st[x],ed[x]);
		//	cout<<st[x]<<ed[x]<<endl;
			int Fill=0;
			while (1){
				int id=belongchain[x];
				if (id==belongchain[1]){
					Fill=max(Fill,chains[id].query(chnum[1],chnum[x]));
					break;
				}
				else{
					Fill=max(Fill,chains[id].query(1,chnum[x]));
					x=chains[id].chainbeg;
					x=p[x];
				}
			}
			//cout<<Fill<<Empty<<endl;
			if (Fill>Empty){
				printf("1\n");
			} 
			else{
				printf("0\n");
			}
		}
	}
}
/*
5
1 2
5 1
2 3
4 2
12
1 1
2 3
3 1
3 2
3 3
3 4
1 2
2 4
3 1
3 3
3 4
3 5
*/