#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=2e5+10;
vector<int>edge[MAXN];
int n,m,h,t,sz[MAXN],vis[MAXN];
int ansx,ansy;
int main(){
	scanf("%d%d%d%d",&n,&m,&h,&t);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
		sz[x]++;sz[y]++; 
	}
	for(int i=1;i<=n;i++){
		int len=edge[i].size();
		for(int l=0;l<len;l++){
			int j=edge[i][l];
			int sa=sz[i]-1,sb=sz[j]-1;
			if(sa<h)continue;
			if(sb<t)continue;
			if(sa>=h+t&&sb>=h+t){ansx=i;ansy=j;continue;}
			int cnt=0;
			for(int k=0;k<edge[i].size();k++){
				int d=edge[i][k];
				if(d==j)continue;
				vis[d]=i;
			}
			for(int k=0;k<edge[j].size();k++){
				int d=edge[j][k];
				if(d==i)continue;
				if(vis[d]==i)cnt++;
			}
			if(t-(sb-cnt) <= sa-h){
				ansx=i;ansy=j;
			}
		}
	}
	if(!ansx){
		printf("NO");return 0;
	}
	printf("YES\n");
	memset(vis,0,sizeof vis);
	for(int k=0;k<edge[ansx].size();k++){
		int d=edge[ansx][k];
		if(d==ansy)continue;
		vis[d]=1;
	}
	for(int k=0;k<edge[ansy].size();k++){
		int d=edge[ansy][k];
		if(d==ansx)continue;
		if(vis[d])vis[d]=-1;
		else vis[d]=2;
	}
	printf("%d %d\n",ansx,ansy);
	int tot=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			printf("%d ",i);
			tot++;
			vis[i]=0;
		}
		if(tot==h)break;
	}
	if(tot<h){
		for(int i=1;i<=n;i++){
			if(vis[i]==-1){
				printf("%d ",i);
				tot++;
				vis[i]=0;
			}
			if(tot==h)break;
		}
	}
	printf("\n");
	tot=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==2 || vis[i]==-1){
			printf("%d ",i);
			tot++;
		}
		if(tot==t)break;
	}
	return 0;
}