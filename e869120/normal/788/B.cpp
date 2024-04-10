#include<bits/stdc++.h>
using namespace std;
vector<int>x[1010000];int n,m,a,b,c[1010000],d[1010000],cnt;long long V;
void dfs(int pos){
	if(c[pos]!=0)return;
	c[pos]=cnt;
	for(int i=0;i<x[pos].size();i++)dfs(x[pos][i]);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		if(a==b){d[a]=1;V++;}
		x[a].push_back(b);
		x[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=0)continue;
		cnt++;dfs(i);
	}
	int W=0;
	for(int i=1;i<=n;i++){
		if(x[i].size()==0)continue;
		if(W==0)W=c[i];
		if(W!=c[i]){cout<<"0"<<endl;return 0;}
	}
	long long R=0,S=0;
	for(int i=1;i<=n;i++){
		long long T=0;
		for(int j=0;j<x[i].size();j++){if(x[i][j]!=i)T++;}
		R+=1LL*T*(T-1);
	}
	R/=2LL;
	if(V>=1)R+=V*(m-V);
	R+=V*(V-1)/2LL;
	cout<<R<<endl;
	return 0;
}