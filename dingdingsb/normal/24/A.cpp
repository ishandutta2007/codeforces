#include<bits/stdc++.h>
using namespace std;
int f[120][120];
bool flag[120];
int n,a,b,c;
int dfs(int pos,int Z,int F,int l){
	//printf("%d %d %d %d\n",pos,Z,F,l);
	if(pos==1&&(Z!=0||F!=0)){
		printf("%d",min(Z,F));
		exit(0);
	}
	for(int i=1;i<=n;i++)
		if(!flag[i]&&(f[i][pos]||f[pos][i])||((f[i][pos]||f[pos][i])&&l>1&&i==1))
			flag[i]=true,dfs(i,Z+f[i][pos],F+f[pos][i],l+1);
}
int main(){
	flag[1]=true;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a,&b,&c),f[a][b]=c;
	dfs(1,0,0,0);
}