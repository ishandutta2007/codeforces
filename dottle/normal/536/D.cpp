#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
const int N=2005,M=400050,inf=1e17;
using namespace std;

int n,m,s,t,w[N];
int F[N],G[N],f[N][N],g[N][N],S[N][N],X[N],Y[N];

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx,w;
}e[M];int hd[N],Sz;
void add(int fr,int to,int w){
    e[++Sz]=(edge){to,hd[fr],w},hd[fr]=Sz;
}
vi lsh(vi&a){
	vi b=a;
	sort(b.begin(),b.end());
	b.end()=unique(b.begin(),b.end());
	for(auto&x:a)x=lower_bound(b.begin(),b.end(),x)-b.begin();
	return b; 
}
vi dij(int s){
	vi dis(n+1,inf);
	priority_queue<pair<int,int>>q;
	dis[s]=0;q.push({0,s});
	while(q.size()){
		auto x=q.top();q.pop();
		if(dis[x.second]!=-x.first)continue;
		fore(x.second)
			if(dis[_to]>dis[x.second]+e[i].w){
				dis[_to]=dis[x.second]+e[i].w;
				q.push({-dis[_to],_to});
			}
	}
	for(auto&x:dis)x=-x;
	return dis;
}
main(){
	cin>>n>>m>>s>>t;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		add(x,y,z),add(y,x,z); 
	}
	auto a=dij(s),b=dij(t);
	auto A=lsh(a),B=lsh(b);
	int x=A.size(),y=B.size();
	for(int i=1;i<=n;i++)
		S[a[i]][b[i]]+=w[i];
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++){
			X[i]=Y[j]=1;
			if(i)S[i][j]+=S[i-1][j];
			if(j)S[i][j]+=S[i][j-1];
			if(i&&j)S[i][j]-=S[i-1][j-1];
		}
	memset(f,-2,sizeof(f)),memset(g,-2,sizeof(g));
//	auto S=[&](int a,int b,int c,int d){
//		int ans=s[c][d];
//		if(a)ans-=s[a-1][d];
//		if(b)ans-=s[c][b-1];
//		if(a&&b)ans+=s[a-1][b-1];
//		return ans;
//	}
	for(int i=1;i<=x+1;i++)
		for(int j=1;j<=y+1;j++){
			while(X[i]<=j&&S[i][j]!=S[i][X[i]]){
				G[i]=max(-f[i][X[i]]-S[i][X[i]],G[i]);
				X[i]++;
			}
			while(Y[j]<=i&&S[i][j]!=S[Y[j]][j]){
				F[j]=max(-g[Y[j]][j]-S[Y[j]][j],F[j]);
				Y[j]++;
			}
			f[i][j]=F[j]+S[i][j];
			g[i][j]=G[i]+S[i][j];
		} 
//	cout<<f[x][y];
	if(f[x][y]==0)cout<<"Flowers";
	if(f[x][y]>0)cout<<"Break a heart";
	if(f[x][y]<0)cout<<"Cry";
}