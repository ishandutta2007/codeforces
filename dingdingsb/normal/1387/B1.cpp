#include<bits/stdc++.h>
using namespace std;
template<typename __readdatatype>
void read(__readdatatype &x){
	x=0;char c=getchar();for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
}
template<typename __writedatatype>
void write(__writedatatype x){
	if(x>=10)write<__writedatatype>(x/10);
	putchar(x%10+'0');
}
const int N=1e5+100;
int n,du[N];
vector<int>e[N];
namespace MIN{
	int ans,can[N];
	int a[N];
	void dfs(int u,int fa){
		vector<int>p;
		for(auto v:e[u])
			if(v!=fa){
				dfs(v,u);
				if(!a[v])p.push_back(v);
			}
		if(!p.size())return;
		for(int i=0;i<p.size()-1;i++)a[p[i]]=p[i+1];
		a[p.back()]=u,a[u]=p.front(),ans+=2*p.size();
	}
	void work(){
		dfs(1,0);
		if(!a[1])a[1]=a[e[1][0]],a[e[1][0]]=1,ans+=2;
	}
}
signed main(){
	//freopen("village.in","r",stdin);
	//freopen("village.out","w",stdout);
	read(n);
	for(int i=1,u,v;i<n;i++)
		read(u),read(v),du[u]++,du[v]++,
		e[u].push_back(v),e[v].push_back(u);
	MIN::work();
	//MAX::work();
	write(MIN::ans);
	putchar('\n');
	for(int i=1;i<=n;i++)
		write(MIN::a[i]),putchar(' ');
}