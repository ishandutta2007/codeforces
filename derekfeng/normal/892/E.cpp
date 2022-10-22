#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,pii> piiii;
#define mkp make_pair
#define fi first
#define se second
int n,m,Q;
int u[500004],v[500004],w[500004];
bool ans[500004];
vector<int>V[500004];
vector<pii>g[500004];
stack<piiii>st;
int f[500004],h[500004];
int F(int x){
	while(x!=f[x])x=f[x];
	return x;
}
void merge(int x,int y){
	if(h[x]<h[y])swap(x,y);
	st.push(mkp(mkp(x,y),mkp(h[x],f[y])));
	f[y]=x;
	if(h[y]+1>h[x])h[x]=h[y]+1;
}
int main(){
	int N=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&u[i],&v[i],&w[i]),V[w[i]].push_back(i),N=max(N,w[i]);
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		ans[i]=1;
		int K;scanf("%d",&K);
		while(K--){
			int x;scanf("%d",&x);
			g[w[x]].push_back(mkp(i,x));
		}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=N;i++){
		while(!st.empty())st.pop();
		int cnt=0;
		for(int j=0;j<V[i].size();j++){
			int a=F(u[V[i][j]]),b=F(v[V[i][j]]);
			if(a==b)continue;
			cnt++;
			merge(a,b);
		}
		while(!st.empty()){
			piiii x=st.top();st.pop();
			h[x.fi.fi]=x.se.fi,f[x.fi.se]=x.se.se;
		}
		for(int j=0;j<g[i].size();){
			int k=j+1;
			while(k<g[i].size()&&g[i][j].fi==g[i][k].fi)k++;
			if(k-j>cnt||ans[g[i][j].fi]==0){
				ans[g[i][j].fi]=0,j=k;
				continue;
			}
			for(int l=j;l<k;l++){
				int a=F(u[g[i][l].se]),b=F(v[g[i][l].se]);
				if(a==b)ans[g[i][j].fi]=0;
				else merge(a,b);
			}
			while(!st.empty()){
				piiii x=st.top();st.pop();
				h[x.fi.fi]=x.se.fi,f[x.fi.se]=x.se.se;
			}
			j=k;
		}
		for(int j=0;j<V[i].size();j++){
			int a=F(u[V[i][j]]),b=F(v[V[i][j]]);
			if(a==b)continue;
			merge(a,b);
		}
	}
	for(int i=1;i<=Q;i++){
		if(ans[i])puts("YES");
		else puts("NO");
	}
}