#include<bits/stdc++.h>
using namespace std;
int g[105][105],p[1000001];
vector<int>G;
int main()
{
	int n,m,i,j,k,ct=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			char c=getchar();
			while(c!='0'&&c!='1'){
				c=getchar();
			}
			g[i][j]=c-'0';
			if(i!=j&&g[i][j]==0){
				g[i][j]=2e6;
			}
		}
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&p[i]);
	}
	G.push_back(p[1]);
	for(i=2;i<m;i++){
		if(g[G[ct]][p[i]]+g[p[i]][p[i+1]]!=g[G[ct]][p[i+1]]){
			G.push_back(p[i]);
			ct++;
		}
	}
	G.push_back(p[m]);
	ct=G.size();
	printf("%d\n",ct);
	for(i=0;i<ct;i++){
		printf("%d ",G[i]);
	}
	return 0;
}