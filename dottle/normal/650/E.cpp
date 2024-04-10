#include<bits/stdc++.h>
const int N=1020050;
using namespace std;

#define _to e[d][i].to
#define fore(k) for(int i=hd[d][k];i;i=e[d][i].nx)
struct edge{
    int to,nx;
}e[2][N];int hd[2][N],S[2];
void add(int k,int fr,int to){
    e[k][++S[k]]=(edge){to,hd[k][fr]},hd[k][fr]=S[k];
}
vector<vector<int>>ans;

int F[N];
int gf(int k){return k==F[k]?k:F[k]=gf(F[k]);}
void mrg(int x,int y){
	int fx=gf(x),fy=gf(y);
	if(fx!=fy)F[fx]=fy;	
}

int n,fa[2][N];

void dfs(int d,int k,int f){
	fa[d][k]=f;
	fore(k)if(_to!=f)dfs(d,_to,k);
}

void df5(int k,int f){
	int d=0;
	fore(k)if(_to!=f){
		df5(_to,k);
		if(fa[1][_to]!=k&&fa[1][k]!=_to)
			ans.push_back({k,_to,gf(_to),fa[1][gf(_to)]}),
			mrg(gf(_to),fa[1][gf(_to)]);
	}
}

int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(0,x,y),add(0,y,x);
	}
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(1,x,y),add(1,y,x);
	}
	dfs(0,1,0),dfs(1,1,0);
	for(int i=2;i<=n;i++){
		if(fa[0][fa[1][i]]==i||fa[0][i]==fa[1][i])
			F[i]=fa[1][i];
		else F[i]=i;
	}
	df5(1,0);
	cout<<ans.size()<<endl;
	for(auto x:ans){
		for(auto y:x)
			cout<<y<<' ';
		cout<<endl;
	}
}