# include <bits/stdc++.h>
using namespace std;
const int N=10000;
int r[N],f[N];
bool b;
vector<pair<int,int> >Q[N];
void DFS(int x,bool p){
	f[x]=1;
	int u,i,l=Q[x].size();
	for(i=0;i<l;i++){
		u=Q[x][i].first;
		if(f[u]==1){
			b=true;
			r[Q[x][i].second]=(p^1)+1;
		}else{
			r[Q[x][i].second]=p+1;
		}
		if(f[u]==0){
			DFS(u,p);
		}
	}
	f[x]=2;
}
int main(){
	int n,m,x,y,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		Q[x].push_back({y,i});
	}
	for(i=1;i<=n;i++){
		if(f[i]==0){
			DFS(i,0);
		}
	}
	if(b==true){
		printf("2\n");
	}else{
		printf("1\n");
	}
	for(i=1;i<=m;i++){
		printf("%d ",r[i]);
	}
	return 0;
}