#include<bits/stdc++.h>
using namespace std;
int n,q,x,y;
struct node{
	double f[3][3];
	node(){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				f[i][j]=-998244353;
	}
}dat[524288];
node merge(node a,node b){
	node ret;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			ret.f[i][j]=max(ret.f[i][j],a.f[i][0]+b.f[0][j]);
			ret.f[i][j]=max(ret.f[i][j],a.f[i][0]+b.f[1][j]);
			ret.f[i][j]=max(ret.f[i][j],a.f[i][0]+b.f[2][j]);
			ret.f[i][j]=max(ret.f[i][j],a.f[i][1]+b.f[0][j]);
			ret.f[i][j]=max(ret.f[i][j],a.f[i][1]+b.f[1][j]);
			ret.f[i][j]=max(ret.f[i][j],a.f[i][2]+b.f[0][j]);
		}return ret;
}int a[200003];
double g[3];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>q>>x>>y;if(x>y)swap(x,y);
	g[1]=1.0/(x+y);g[2]=1.0/y;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<3;j++)
			dat[i+262144].f[j][j]=g[j]*a[i];
	}for(int i=262143;i>0;i--)
		dat[i]=merge(dat[i<<1],dat[i<<1|1]);	
	while(q--){
		int tp,X,Y;
		cin>>tp>>X>>Y;
		if(tp==1){
			X--;
			X+=262144;
			for(int i=0;i<3;i++)
				dat[X].f[i][i]=g[i]*Y;
			while(X>1)X>>=1,dat[X]=merge(dat[X<<1],dat[X<<1|1]);
		}else{
			X--;Y--;
			vector<int>V,G;
			for(int l=X+262143,r=Y+262145;l^r^1;l>>=1,r>>=1){
				if(~l&1)V.push_back(l^1);
				if(r&1)G.push_back(r^1);
			}while(G.size())V.push_back(G.back()),G.pop_back();
			node ans=dat[V[0]];
			for(int i=1;i<V.size();i++)
				ans=merge(ans,dat[V[i]]);
			double ret=0;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					ret=max(ret,ans.f[i][j]);
			cout<<fixed<<setprecision(13)<<ret<<'\n'; 
		}
	}
}