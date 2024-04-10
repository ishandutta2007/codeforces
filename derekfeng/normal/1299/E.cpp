#include<bits/stdc++.h>
using namespace std;
#define ffs fflush(stdout)
int n,X,P[804];
int pos[804],ocur[5][2],md[804][4];
bool vis[804];
int id[3][5][7][8];
int main(){
	scanf("%d",&n),ffs;
	for(int i=1;i<=4&&i<=n/2;i++){
		int N=0;
		for(int j=1;j<=n;j++)if(!vis[j]){
			printf("? %d ",n-2*i+1);
			for(int k=1;k<=n;k++)if(!vis[k]&&j!=k)printf("%d ",k);
			puts(""),ffs;
			scanf("%d",&X),ffs;
			if(X==1)ocur[i][N++]=j;
		}
		if(i!=1){
			printf("? 2 %d %d\n",pos[1],ocur[i][0]),ffs;
			scanf("%d",&X),ffs;
			if(X^(i&1))swap(ocur[i][0],ocur[i][1]);
		}
		P[ocur[i][0]]=i,P[ocur[i][1]]=n-i+1;
		pos[i]=ocur[i][0],pos[n-i+1]=ocur[i][1];
		vis[ocur[i][0]]=vis[ocur[i][1]]=1;
	}
	if(n<=8){
		if(P[1]>n/2)for(int i=1;i<=n/2;i++)swap(P[pos[i]],P[pos[n-i+1]]);
		printf("! ");
		for(int i=1;i<=n;i++)printf("%d ",P[i]);
		return 0;
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		printf("? 3 %d %d %d\n",i,pos[1],pos[2]),ffs;
		scanf("%d",&X),ffs;
		if(X==1){
			md[i][0]=(30000-1-2)%3;
			continue;
		}
		printf("? 3 %d %d %d\n",i,pos[1],pos[3]),ffs;
		scanf("%d",&X),ffs;
		if(X==1){
			md[i][0]=(30000-1-3)%3;
			continue;
		}
		md[i][0]=(30000-2-3)%3;
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		printf("? 5 %d %d %d %d %d\n",i,pos[1],pos[2],pos[3],pos[n-3]),ffs;
		scanf("%d",&X),ffs;
		if(X==1){
			md[i][1]=(50000-1-2-3-(n-3))%5;
			continue;
		}
		printf("? 5 %d %d %d %d %d\n",i,pos[1],pos[2],pos[4],pos[n-3]),ffs;
		scanf("%d",&X),ffs;
		if(X==1){
			md[i][1]=(50000-1-2-4-(n-3))%5;
			continue;
		}
		printf("? 5 %d %d %d %d %d\n",i,pos[1],pos[3],pos[4],pos[n-3]),ffs;
		scanf("%d",&X),ffs;
		if(X==1){
			md[i][1]=(50000-1-3-4-(n-3))%5;
			continue;
		}
		printf("? 5 %d %d %d %d %d\n",i,pos[1],pos[3],pos[4],pos[n-2]),ffs;
		scanf("%d",&X),ffs;
		if(X==1){
			md[i][1]=(50000-1-3-4-(n-2))%5;
			continue;
		}
		md[i][1]=(50000-2-3-4-(n-2))%5;
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		printf("? 7 %d %d %d %d %d %d %d\n",i,pos[1],pos[2],pos[3],pos[n-3],pos[n-2],pos[n-1]),ffs;
		scanf("%d",&X),ffs;
		if(X==1){
			md[i][2]=(70000-1-2-3-(n-3)-(n-2)-(n-1))%7;
			continue;
		}
		printf("? 7 %d %d %d %d %d %d %d\n",i,pos[1],pos[2],pos[4],pos[n-3],pos[n-2],pos[n-1]),ffs;
		scanf("%d",&X),ffs;
		if(X==1){
			md[i][2]=(70000-1-2-4-(n-3)-(n-2)-(n-1))%7;
			continue;
		}
		printf("? 7 %d %d %d %d %d %d %d\n",i,pos[1],pos[3],pos[4],pos[n-3],pos[n-2],pos[n-1]),ffs;
		scanf("%d",&X),ffs;
		if(X==1){
			md[i][2]=(70000-1-3-4-(n-3)-(n-2)-(n-1))%7;
			continue;
		}
		printf("? 7 %d %d %d %d %d %d %d\n",i,pos[2],pos[3],pos[4],pos[n-3],pos[n-2],pos[n-1]),ffs;
		scanf("%d",&X),ffs;
		if(X==1){
			md[i][2]=(70000-2-3-4-(n-3)-(n-2)-(n-1))%7;
			continue;
		}
		printf("? 7 %d %d %d %d %d %d %d\n",i,pos[2],pos[3],pos[4],pos[n-3],pos[n-2],pos[n]),ffs;
		scanf("%d",&X),ffs;
		if(X==1){
			md[i][2]=(70000-2-3-4-(n-3)-(n-2)-n)%7;
			continue;
		}
		printf("? 7 %d %d %d %d %d %d %d\n",i,pos[2],pos[3],pos[4],pos[n-3],pos[n-1],pos[n]),ffs;
		scanf("%d",&X),ffs;
		if(X==1){
			md[i][2]=(70000-2-3-4-(n-3)-(n-1)-n)%7;
			continue;
		}
		md[i][2]=(70000-2-3-4-(n-2)-(n-1)-n)%7;
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		printf("? 2 %d %d\n",pos[1],i),ffs;
		scanf("%d",&X),ffs;
		if(!X){
			printf("? 4 %d %d %d %d\n",i,pos[1],pos[3],pos[4]),ffs;
			scanf("%d",&X),ffs;
			if(X==1){
				printf("? 8 %d %d %d %d %d %d %d %d\n",i,pos[1],pos[2],pos[3],pos[n-3],pos[n-2],pos[n-1],pos[n]),ffs;
				scanf("%d",&X),ffs;
				if(X==1)md[i][3]=0;
				else md[i][3]=4;
			}else{
				printf("? 8 %d %d %d %d %d %d %d %d\n",i,pos[1],pos[3],pos[4],pos[n-3],pos[n-2],pos[n-1],pos[n]),ffs;
				scanf("%d",&X),ffs;
				if(X==1)md[i][3]=6;
				else md[i][3]=2;
			}
		}else{
			printf("? 4 %d %d %d %d\n",i,pos[1],pos[2],pos[4]),ffs;
			scanf("%d",&X),ffs;
			if(X==1){
				printf("? 8 %d %d %d %d %d %d %d %d\n",i,pos[2],pos[3],pos[4],pos[n-3],pos[n-2],pos[n-1],pos[n]),ffs;
				scanf("%d",&X),ffs;
				if(X==1)md[i][3]=5;
				else md[i][3]=1;
			}else{
				printf("? 8 %d %d %d %d %d %d %d %d\n",i,pos[1],pos[2],pos[4],pos[n-3],pos[n-2],pos[n-1],pos[n]),ffs;
				scanf("%d",&X),ffs;
				if(X==1)md[i][3]=7;
				else md[i][3]=3;
			}
		}
	}
	for(int i=1;i<=n;i++)id[i%3][i%5][i%7][i%8]=i;
	for(int i=1;i<=n;i++)if(!vis[i]){
		int ans=id[md[i][0]][md[i][1]][md[i][2]][md[i][3]];
		P[i]=ans,pos[ans]=i;
	}
	if(P[1]>n/2)for(int i=1;i<=n/2;i++)swap(P[pos[i]],P[pos[n-i+1]]);
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",P[i]);
}