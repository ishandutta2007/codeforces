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
namespace MAX{
	long long ans=0,sz[N];
	int a[N],b[N],tot,dfn[N];
	void dfs(int u,int fa){
		sz[u]=1;dfn[++tot]=u;
		for(auto v:e[u])//I love C++11
			if(v!=fa)
				dfs(v,u),sz[u]+=sz[v];
		ans+=2*min(sz[u],n-sz[u]);
	}
	void work(){
		dfs(1,0);
		/*
		int dudeng=0,duda=0;
		for(int i=1;i<=n;i++)
			if(du[i]==2)dudeng++;
			else if(du[i]>2)duda++;//,cout<<i<<endl;
		bool A=!duda;
		bool B=(duda==1)&&(!dudeng);
		if(A){// 
			if(n%2==0){
				for(int i=1;i<=n;i++)
					if(du[i]==1)
						{dfs1(i,0);break;}
				for(int i=1;i<=n;i++)b[i]=tmp[i-1];
				for(int i=1;i<=n/2;i++)
					swap(a[b[i]],a[b[n-i+1]]);
			}else{
				for(int i=1;i<=n;i++)
					if(du[i]==1)
						{dfs1(i,0);break;}
				for(int i=1;i<=n;i++)b[i]=tmp[i-1];
				for(int i=1;i<n/2;i++)
					swap(a[b[i]],a[b[n-i+1]]);
				a[b[n/2]]=b[n/2+1];
				a[b[n/2+1]]=b[n/2+2];
				a[b[n/2+2]]=b[n/2];
			}
		}else if(B){
			//printf("fxxk chu ti rens");
			for(int i=1;i<=n;i++)
				a[i]=MIN::a[i];
		}*/
		for(int i=1;i<=n;i++)a[dfn[i]]=dfn[(i+n/2-1)%n+1];
	}
}
signed main(){
	//freopen("village.in","r",stdin);
	//freopen("village.out","w",stdout);
	read(n);
	for(int i=1,u,v;i<n;i++)
		read(u),read(v),du[u]++,du[v]++,
		e[u].push_back(v),e[v].push_back(u);
	MAX::work();
	write(MAX::ans);
	putchar('\n');
	for(int i=1;i<=n;i++)
		write(MAX::a[i]),putchar(' ');
}