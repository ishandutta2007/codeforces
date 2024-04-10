/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=500000;
int n,m;
vector<int> nei[N+1];
int a[N+1];
vector<int> buc[N+1];
bool cmp(int x,int y){return a[x]<a[y];}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		nei[x].push_back(y);nei[y].push_back(x);
	}
	for(int i=1;i<=n;i++)scanf("%d",a+i),buc[a[i]].push_back(i);
	for(int i=1;i<=n;i++)for(int j=0;j<nei[i].size();j++){
		int x=nei[i][j];
		if(a[i]==a[x])return puts("-1"),0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<nei[i].size();j++)nei[i][j]=a[nei[i][j]];
		sort(nei[i].begin(),nei[i].end());
		nei[i].resize(unique(nei[i].begin(),nei[i].end())-nei[i].begin());
		if(nei[i].size()<a[i]-1)return puts("-1"),0;
		for(int j=1;j<a[i];j++)if(nei[i][j-1]!=j)return puts("-1"),0;
	}
	for(int i=1;i<=n;i++)for(int j=0;j<buc[i].size();j++)printf("%d ",buc[i][j]);
	return 0;
}