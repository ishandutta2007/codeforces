#include<bits/stdc++.h>
using namespace std;
int n,m,k,num[20],g[100][100],f[100];
vector<pair<int,int> >v[200100];
vector<int>u[200100];
int cnt[100],res,a[20];
bool ok[100];
void dfs(int pos){
	if(pos==k+1){res++;return;}
	for(int i=0;i<pos;i++){
		if(ok[num[pos]+i])continue;
		bool fl=true;
		for(int j=1;j<pos;j++)fl&=g[a[j]][num[pos]+i];
		if(!fl)continue;
		a[pos]=num[pos]+i;
		dfs(pos+1);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=k+1;i++)num[i]=num[i-1]+i-1;
//	for(int i=1;i<=k;i++)printf("%d ",num[i]);puts("");
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),v[x].push_back(make_pair(z,y));
	for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
	for(int i=1;i<=n;i++)for(int j=0;j<v[i].size();j++)u[v[i][j].second].push_back(num[v[i].size()]+j);
	for(int i=1;i<=k;i++)for(int j=i+1;j<=k;j++)for(int k=0;k<i;k++)for(int l=0;l<j;l++)g[num[i]+k][num[j]+l]=true;
	for(int i=1;i<=n;i++){
		for(int j=0;j<num[k+1];j++)cnt[j]=0;
//		for(auto j:u[i])printf("%d ",j);puts("");
		for(auto j:u[i])cnt[j]++;
		vector<int>vv;
		for(int j=0;j<num[k+1];j++){
			if(cnt[j]>=2)ok[j]=true;
			else if(cnt[j]==1)vv.push_back(j);
		}
		for(auto j:vv)for(auto k:vv)g[j][k]=false;
	}
	dfs(1);
	printf("%d\n",res);
	return 0;
}