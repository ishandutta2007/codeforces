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
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
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
const int Maxn=100005;
vector<int> G[Maxn];
int p[Maxn];
int par[Maxn];
int n,m,d;
bool vis[Maxn];
int mdist[Maxn];
bool hav[Maxn];
bool hav2[Maxn];
int mdd[Maxn];
struct tree{
	int num;
	vector<int> v;
	vector<int> tr;
	int siz;
	void build_tree(int l,int r,int p){
		if (l==r){
			tr[p]=v[l];
			return;
		}
		int mid=(l+r)>>1;
		build_tree(l,mid,p*2);
		build_tree(mid+1,r,p*2+1);
		tr[p]=max(tr[p*2],tr[p*2+1]);
	}
	void _init(vector<int> x,int nb){
		v.resize(x.size()+2,0);
		num=nb;
		for (int i=1;i<=x.size();i++){
			if (x[i-1]!=par[num])
				v[i]=mdist[x[i-1]];
			else{
				v[i]=-1;
			}
		}
	//	cerr<<"initok"<<endl;
		tr.resize(x.size()*4,0);
		siz=x.size();
		//cout<<siz<<endl;
		build_tree(1,siz,1);
	}
	int query(int l,int r,int p,int lo,int hi){
		if (lo<=l && r<=hi){
			return tr[p];
		}
		int mid=(l+r)>>1;
		int ans=-3;
		if (lo<=mid){
			ans=max(ans,query(l,mid,p*2,lo,min(hi,mid)));
		} 
		if (hi>mid){
			ans=max(ans,query(mid+1,r,p*2+1,max(lo,mid+1),hi));
		}
		return ans;
	}
	int query(int x,int y){
		if (x>y) return -1;
		if (x>siz) return -1;
		return query(1,siz,1,x,y);
	}
}GTr[Maxn];
void dfs1(int u,int pr){
//	cout<<u;
	par[u]=pr;
	vis[u]=true;
	hav2[u]=hav[u];
	//if (hav2[u]) return;
	for (int i=0;i<G[u].size();i++){
		if (!vis[G[u][i]]){
		//cout<<u<<' '<<G[u][i]<<endl;
			dfs1(G[u][i],u);
			hav2[u]|=hav2[G[u][i]];
		}
	}
}
void dfs2(int u){
	vis[u]=true;
	bool flag=false;
	for (int i=0;i<G[u].size();i++){
		if (!vis[G[u][i]]){
			flag=true;
			if (hav2[G[u][i]]){
				dfs2(G[u][i]);
				if (mdist[G[u][i]]!=-1)
				mdist[u]=max(mdist[u],mdist[G[u][i]]+1);
			}
		}
	}
	if (hav[u]){
		mdist[u]=max(mdist[u],0);
	}
}
void solve(int u,int mxv){
	for (int i=0;i<G[u].size();i++){
		if (G[u][i]!=par[u]){
			int v=G[u][i];
			int lf=GTr[u].query(1,i),rg=GTr[u].query(i+2,G[u].size());
			int mx=max(lf,rg);
			if (mx>=0) mx+=2;
			if (hav[u]) mx=max(mx,1);
			if (mxv!=-1) mx=max(mx,mxv+1);
			//if (v==3) cout<<"debug"<<mx<<endl;
			mdd[v]=max(mx,mdist[v]);
		//	cout<<v<<' '<<mdd[v]<<' '<<mx<<endl;
			solve(v,mx);
		}
	}
}
int main(){
	memset(mdist,-1,sizeof(mdist));
	scanf("%d %d %d",&n,&m,&d);
	for (int i=0;i<m;i++){
		
		scanf("%d",&p[i]);
		hav[p[i]]=true;
	}
	for (int i=0;i<n-1;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		G[x].pb(y);
		G[y].pb(x);
		//cout<<x<<y<<endl;
	}
	//	cerr<<G[6].size()<<endl;
	memset(vis,false,sizeof(vis));//cerr<<"OK"<<endl;
	dfs1(1,-1);
	
	memset(vis,false,sizeof(vis));
	dfs2(1);//cerr<<"OK"<<endl
	/*
	for (int i=1;i<=n;i++){
		cout<<mdist[i]<<' ';
	}
	cout<<endl;*/
	for (int i=1;i<=n;i++){
		GTr[i]._init(G[i],i);
	}
	memset(vis,false,sizeof(vis));
	solve(1,-1);//cerr<<"OK"<<endl;
	
	int ans=0;
	for (int i=2;i<=n;i++){
		if (mdd[i]<=d && mdd[i]!=-1){
		//	cout<<i<<endl;
			ans++;
		}
	}
	if (mdist[1]<=d) ans++; 
	printf("%d\n",ans);
	return 0; 
} 
/*
6 2 3
1 2
1 5
2 3
3 4
4 5
5 6
*/
/*
8 1 2
4
1 2
2 3
3 4
4 5
6 5
6 7
7 8
/*
2 2 1
2 1
1 2
*/
/*
50 2 5
9 14
46 34
40 35
44 30
32 16
1 38
48 2
17 14
50 25
6 1
45 19
21 15
22 11
15 33
8 28
2 32
10 22
37 3
43 39
25 16
9 19
16 3
28 32
20 45
24 32
4 18
49 39
13 45
26 4
11 33
14 37
42 19
31 45
38 3
34 8
18 29
35 34
29 16
7 46
19 28
27 33
30 9
33 16
36 45
47 1
41 39
23 13
3 39
5 34
12 43
*/