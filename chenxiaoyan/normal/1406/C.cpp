/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100000;
int n;
vector<int> nei[N+1];
int sz[N+1];
void dfs(int x=1,int fa=0){
	sz[x]=1;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa)continue;
		dfs(y,x);
		sz[x]+=sz[y];
	}
}
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)nei[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		nei[x].pb(y);nei[y].pb(x);
	}
	dfs();
	vector<int> cen;
	for(int i=1;i<=n;i++){
		bool flg=true;
		int sum=1;
		for(int j=0;j<nei[i].size();j++){
			int x=nei[i][j];
			if(sz[x]>sz[i])continue;
			flg&=sz[x]<=n/2;
			sum+=sz[x];
		}
		flg&=n-sum<=n/2;
		if(flg)cen.pb(i);
	}
	assert(cen.size()<=2);
	if(cen.size()==1)printf("%d %d\n%d %d\n",1,nei[1][0],1,nei[1][0]);
	else{
		int son=nei[cen[0]][0]==cen[1]?nei[cen[0]][1]:nei[cen[0]][0];
		printf("%d %d\n%d %d\n",cen[0],son,cen[1],son);
	}
}
int main(){
	int testnum=1;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}