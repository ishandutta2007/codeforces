#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
#define mkp make_pair
#define fi first
#define se second
const int M=1e6+1;
bool flg[1000004];
int prim[1000004],tot;
int n,q,a[150004];
vector<int>cr[1000004];
void init(){
	for(int i=2;i<=M;i++)if(!flg[i]){
		prim[++tot]=i;
		if(i<=1e3)for(int j=i*i;j<=M;j+=i)flg[j]=1;
	}
	for(int i=1;i<=tot;i++)
		for(int j=prim[i];j<=M;j+=prim[i])cr[j].push_back(i);
}
int fa[1000004],ans[300004];
int F(int x){return fa[x]==x?x:fa[x]=F(fa[x]);}
vector<pii>ask[1000004];
vector<int>node[1000004];
vector<int>qry[1000004];
int main(){
	init();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=tot+n;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(auto x:cr[a[i]]){
			int X=F(i+tot),Y=F(x);
			if(X!=Y)fa[X]=Y;
		}
	}
	fill(ans+1,ans+1+q,2);
	for(int i=1;i<=q;i++){
		int x,y;scanf("%d%d",&x,&y);
		x=F(x+tot),y=F(y+tot);
		if(x==y)ans[i]=0;
		else{
			ask[x].push_back(mkp(y,i));
			ask[y].push_back(mkp(x,i));
		}
	}
	vector<int>root;
	for(int i=1;i<=tot+n;i++){
		if(F(i)==i)root.push_back(i);
		node[fa[i]].push_back(i);
	}
	for(auto x:root){
		map<int,bool>mp;
		for(auto y:node[x])if(y>tot)
			for(auto z:cr[a[y-tot]+1])
				mp[F(z)]=1;
		for(auto y:ask[x])if(mp[y.fi])ans[y.se]=1;
	}
	for(int i=1;i<=n;i++)for(auto x:cr[a[i]+1])for(auto y:cr[a[i]+1])qry[F(x)].push_back(F(y));
	for(auto x:root){
		map<int,bool>mp;
		for(auto y:qry[x])mp[y]=1;
		for(auto y:ask[x])if(mp[y.fi])ans[y.se]=1;
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}