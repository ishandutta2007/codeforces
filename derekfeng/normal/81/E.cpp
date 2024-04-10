#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
pii operator + (const pii x,const pii y){
	return mkp(x.fi+y.fi,x.se+y.se);
}
pii operator += (pii &x,pii y){
	return x=x+y;
}
pii ans;
vector<pii>res;
vector<int>g[100004];
int a[100004],n,sex[100004];
bool ins[100004],vis[100004];
pii f[2][2][100004];
int fr[2][100004];
void dp(int x,pii *f0,pii *f1,int *fr,int n1,int n2){
	pii tot=mkp(0,0);
	for(auto y:g[x])dp(y,f0,f1,fr,n1,n2),tot+=max(f0[y],f1[y]);
	f0[x]=tot;
	if(n1==x||n2==x)return;
	for(auto y:g[x])if(n1!=y&&n2!=y){
		pii cur=mkp(1,(sex[x]!=sex[y])),tmp=max(f0[y],f1[y]);
		tot.fi-=tmp.fi,tot.se-=tmp.se;
		if(f1[x]<max(f1[x],tot+cur+f0[y])){
			f1[x]=max(f1[x],tot+cur+f0[y]),fr[x]=y;
		}
		tot.fi+=tmp.fi,tot.se+=tmp.se;
	}
}
void getans(int x,int col,pii *f0,pii *f1,int *fr){
	if(!col)for(auto y:g[x])getans(y,(f0[y]<f1[y]),f0,f1,fr);
	else{
		res.push_back(mkp(x,fr[x]));
		getans(fr[x],0,f0,f1,fr);
		for(auto y:g[x])if(y!=fr[x])getans(y,(f0[y]<f1[y]),f0,f1,fr);
	}
}
void sol(int x,int y){
	for(int i=0;i<g[y].size();i++)if(g[y][i]==x){
		swap(g[y][i],g[y][g[y].size()-1]); 
		g[y].pop_back();break;
	}
	dp(x,f[0][0],f[0][1],fr[0],0,0);
	dp(x,f[1][0],f[1][1],fr[1],x,y);
	pii cur=mkp(1,(sex[x]!=sex[y])),tmp;
	if(cur+max(f[1][0][x],f[1][1][x])<max(f[0][0][x],f[0][1][x])){
		tmp=max(f[0][0][x],f[0][1][x]);
		getans(x,(f[0][0][x]<f[0][1][x]),f[0][0],f[0][1],fr[0]);
	}else{
		res.push_back(mkp(x,y));
		getans(x,(f[1][0][x]<f[1][1][x]),f[1][0],f[1][1],fr[1]);
		tmp=cur+max(f[1][0][x],f[1][1][x]);
	}
	ans+=tmp;
}
void dfs(int x){
	vis[x]=ins[x]=1;
	if(ins[a[x]])sol(x,a[x]);
	else if(!vis[a[x]])dfs(a[x]);
	ins[x]=0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&sex[i]),g[a[i]].push_back(i);
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	printf("%d %d\n",ans.fi,ans.se);
	for(auto x:res)printf("%d %d\n",x.fi,x.se);
}