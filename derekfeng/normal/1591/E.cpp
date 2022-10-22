#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;
#define fi first
#define se second
namespace IO{
	const int SIZ=(1<<25);
	char buf1[SIZ],*p1=buf1,*p2=buf1;
	char buf2[SIZ],*p3=buf2,*p4=buf2;
	char gchar(){if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);return p1==p2?EOF:*p1++;}
	void pchar(char c){*p4++=c;if(p4-p3==SIZ)fwrite(buf2,1,SIZ,stdout),p4=buf2;}
	void output(){fwrite(buf2,1,p4-p3,stdout);}
}
using namespace IO;
int read(){int ret=0,c;while((c=gchar())>'9'||c<'0');ret=c-'0';while((c=gchar())>='0'&&c<='9')ret=ret*10+c-'0';return ret;}
void write(int x){if(x>9)write(x/10);pchar(x%10+'0');}
void Write(int x){if(x<0)pchar('-'),write(-x);else write(x);}
tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>tr;
int n,q;
int a[1000005],ans[1000005],num[1000005];
vector<pair<int,pii> >qry[1000005];
vector<int>g[1000005];
void dfs(int u){
	int x=a[u];
	tr.erase({num[x],x});
	num[x]++;
	tr.insert({num[x],x});
	for(auto A:qry[u]){
		int id=A.fi,l=A.se.fi,k=A.se.se;
		int b=tr.order_of_key({l,0})+k-1;
		if(b>=n)ans[id]=-1;
		else ans[id]=(*tr.find_by_order(b)).se;
	}
	for(auto v:g[u])dfs(v);
	tr.erase({num[x],x});
	num[x]--;
	tr.insert({num[x],x});
}
void sol(){
	tr.clear();
	n=read(),q=read();
	for(int i=1;i<=n;i++)g[i].clear(),qry[i].clear();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=2;i<=n;i++){
		int u=read();
		g[u].push_back(i);
	}
	for(int i=1;i<=q;i++){
		int v=read(),l=read(),k=read();
		qry[v].push_back({i,{l,k}});
	}
	for(int i=1;i<=n;i++)tr.insert({0,i});
	dfs(1);
	for(int i=1;i<=q;i++)Write(ans[i]),pchar(' ');pchar('\n');
}
int main(){
	int T=read();
	while(T--)sol();
	output();
}