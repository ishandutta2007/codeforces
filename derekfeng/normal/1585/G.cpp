#include<bits/stdc++.h>
using namespace std;
const int SIZ=(1<<24);
char buf1[SIZ],*p1=buf1,*p2=buf1;
char buf2[SIZ],*p3=buf2,*p4=buf2;
char gchar(){if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);return p1==p2?EOF:*p1++;}
void pchar(char c){*p4++=c;if(p4-p3==SIZ)fwrite(buf2,1,SIZ,stdout),p4=buf2;}
void output(){fwrite(buf2,1,p4-p3,stdout);}
int read(){int ret=0,c;while((c=gchar())>'9'||c<'0');ret=c-'0';while((c=gchar())>='0'&&c<='9')ret=ret*10+c-'0';return ret;}
int t,n,ls[500004],L[500004],*it,f[1000004];
int *dp[500004];
vector<int>tr[500004],RT;
void glen(int u){
	L[u]=1;
	for(auto v:tr[u]){
		glen(v);
		if(L[u]<L[v]+1)
			L[u]=L[v]+1,ls[u]=v;
	}
}
void arrg(int u){
	dp[u]=it,it++;
	if(ls[u])arrg(ls[u]);
	else it++;
	for(auto v:tr[u])if(v!=ls[u])
		arrg(v);
}
int rt[500004];
unordered_set<int>st[5000004];
void gdp(int u){
	L[u]=n+1;
	for(auto v:tr[u])gdp(v),L[u]=min(L[u],L[v]+1);
	if(tr[u].empty()){
		dp[u][0]=1,dp[u][1]=0,L[u]=1;
		rt[u]=u,st[u].insert(0),st[u].insert(1);
		return;
	}
	int s=ls[u];
	if(tr[u].size()==1){
		int mex=dp[s][0]+1;
		rt[u]=rt[s];
		while(st[rt[u]].find(mex)!=st[rt[u]].end())mex++;
		dp[u][0]=mex,st[rt[u]].insert(mex);
		return;
	}
	rt[u]=u;
	for(auto v:tr[u])if(v!=s)for(int j=0;j<L[u];j++)
		dp[s][j]^=dp[v][j];
	for(int j=0;j<L[u];j++)st[u].insert(dp[s][j]);
	int mex=0;
	while(st[u].find(mex)!=st[u].end())mex++;
	dp[u][0]=mex,st[u].insert(mex);
}
void sol(){
	n=read(),RT.clear();
	for(int i=1;i<=n;i++)tr[i].clear(),ls[i]=0,rt[i]=i,st[i].clear();
	for(int i=1,p;i<=n;i++){
		p=read();
		if(p)tr[p].push_back(i);
		else RT.push_back(i);
	}
	it=f;
	int F=0;
	for(auto x:RT)glen(x),arrg(x),gdp(x),F^=dp[x][0];
	if(F)pchar('Y'),pchar('E'),pchar('S'),pchar('\n');
	else pchar('N'),pchar('O'),pchar('\n');
}
int main(){
	t=read();
	while(t--)sol();
	output();
}