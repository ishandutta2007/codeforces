#include<bits/stdc++.h>
using namespace std;
#define ran 1111111
int n,root,sum2;
vector<int> e[ran];
int sum[ran],fat[ran],dep[ran];
bool ace[ran];
void dfs(int x){
	for(vector<int>::iterator it = e[x].begin(); it!=e[x].end(); it++){
		dep[*it] = dep[x] + 1;
		dfs(*it);
		sum[x] += sum[*it];
	}
}
bool process(){
	dep[root]=0;
	dfs(root);
	if(sum[root] % 3 != 0)return false;
	int sum2 = sum[root] / 3;
	int xx = -1;
	for(int i=1; i <= n; i++)
		if(sum[i] == sum2 && i != root){
			if(xx == -1 || dep[i] > dep[xx]){
				xx = i;
			}
		}
	if(xx == -1)return false;
	for(int y = xx; y != root; y = fat[y])
		ace[fat[y]] = true;
	ace[root] = false;

	for(int i=1; i<=n; i++){
		if(i == root || i == xx)continue;
		if(ace[i] && sum[i] == 2 * sum2 || !ace[i] && sum[i] == sum2){
			printf("%d %d\n",xx,i);
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&fat[i],&sum[i]);
		if(fat[i] == 0)root = i;else
			e[fat[i]].push_back(i);
	}
	if(!process())puts("-1");
	return 0;
}