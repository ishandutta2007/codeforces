#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=100000;
vector<int> e[Maxn+5];
vector<int> level[Maxn+5];
vector<int> cnt[Maxn+5];
int dep[Maxn+5];
int depd[755],depc[755],tot;
int mdep;
bool f[755][Maxn+5];
int ccnt[Maxn+5];
int maxn[Maxn+5];
bool cmp(vector<int> x,vector<int> y){
	return x.size()<y.size();
}
void dfs(int x){
	for(int i=0;i<(int)e[x].size();i++){
		int to=e[x][i];
		dep[to]=dep[x]+1;
		mdep=max(mdep,dep[to]);
		cnt[dep[to]].push_back(to);
		dfs(to);
	}
}
int ans[Maxn+5];
void print(int layer,int re){
	if(re==0){
		return;
	}
	for(int i=0;i<=depc[layer]&&i*depd[layer]<=re;i++){
		if(f[layer-1][re-depd[layer]*i]){
			print(layer-1,re-depd[layer]*i);
			for(int j=0;j<i;j++){
				for(int k=0;k<(int)cnt[level[depd[layer]][j]].size();k++){
					ans[cnt[level[depd[layer]][j]][k]]=1;
				}
			}
			break;
		}
	}
}
int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=2;i<=n;i++){
		int a;
		scanf("%d",&a);
		e[a].push_back(i);
	}
	dfs(1);
	cnt[0].push_back(1);
	for(int i=0;i<=mdep;i++){
		level[cnt[i].size()].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(level[i].size()){
			depd[++tot]=i,depc[tot]=level[i].size();
		}
	}
	for(int i=0;i<=tot;i++){
		f[i][0]=1;
	}
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=x;j++){
			maxn[j]=-1;
			if(f[i-1][j]){
				maxn[j%depd[i]]=j;
			}
			if(maxn[j%depd[i]]!=-1&&(j-maxn[j%depd[i]])<=depd[i]*depc[i]){
				f[i][j]=1;
			}
		}
	}
	if(f[tot][x]){
		printf("%d\n",mdep+1);
		print(tot,x);
	}
	else{
		printf("%d\n",mdep+2);
		int re=x;
		int now=n;
		int tag=mdep;
		for(int i=0;i<mdep;i++){
			if(!re){
				break;
			}
			if((int)cnt[i].size()<re){
				for(int j=0;j<(int)cnt[i].size();j++){
					ans[cnt[i][j]]=1;
				}
				re-=cnt[i].size();
			}
			else if((int)cnt[i].size()>now-re){
				int nleaf=0;
				for(int j=0;j<(int)cnt[i].size();j++){
					if(e[cnt[i][j]].size()){
						nleaf++;
						ans[cnt[i][j]]=1;
					}
				}
				re-=nleaf;
				tag=i;
			}
			now-=cnt[i].size();
		}
		if(re){
			for(int i=0;i<(int)cnt[tag].size()&&re;i++){
				if(!ans[cnt[tag][i]]){
					ans[cnt[tag][i]]=1;
					re--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]){
			putchar('a');
		}
		else{
			putchar('b');
		}
	}
	puts("");
	return 0;
}