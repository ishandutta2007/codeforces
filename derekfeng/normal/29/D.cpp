#include <bits/stdc++.h>
using namespace std;
typedef pair<short,short> pii;
typedef pair<pii,short> piii;
#define mkp make_pair
#define fi first
#define se second
void read(short &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(short x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void outputno(){
	puts("-1");exit(0);
}
short n,ind[303],ld[303],rd[303],cnt;
vector<short>g[303],ans;
bool lvs[303];
void dfs(short x,short par){
	if (lvs[x]){
		ld[x]=rd[x]=ind[x];
		return;
	}
	ld[x]=300;
	for (short i=0;i<g[x].size();i++)if(g[x][i]!=par){
		dfs(g[x][i],x);
		ld[x]=min(ld[x],ld[g[x][i]]),rd[x]=max(rd[x],rd[g[x][i]]);
	}
}
void dfs2(short x,short par){
	ans.push_back(x); 
	if (lvs[x])return; 
	vector<piii>v;
	for (short i=0;i<g[x].size();i++)if(g[x][i]!=par)
		v.push_back(mkp(mkp(ld[g[x][i]],rd[g[x][i]]),g[x][i])); 
	sort (v.begin(),v.end());
	for (short i=0;i<v.size();i++){
		if (i!=0 && v[i].fi.fi<v[i-1].fi.se) outputno();
		dfs2(v[i].se,x);
		ans.push_back(x); 
	}
} 
int main(){
	read(n);
	for (short i=0;i<n-1;i++){
		short x,y;read(x),read(y);
		g[x].push_back(y),g[y].push_back(x);  
	}
	for (short i=2;i<=n;i++)
		if (g[i].size()==1)
			lvs[i]=1,cnt++;
	for (short i=1;i<=cnt;i++){
		short x;read(x),ind[x]=i;
	}
	dfs(1,-1);
	dfs2(1,-1);
	for (short i=0;i<ans.size();i++) write(ans[i]),putchar(' ');
}