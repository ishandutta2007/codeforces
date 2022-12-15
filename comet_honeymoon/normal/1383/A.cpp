#include<bits/stdc++.h>
using namespace std;

int T,N;
char A[100005],B[100005]; 
int now[20][20],tgt[20];

int main(){
	scanf("%d",&T); 
	while(T--){
		for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
			now[i][j]=0,tgt[i]=0;
		scanf("%d",&N);
		scanf("%s",A+1);scanf("%s",B+1);
		bool flg=1;
		for(int i=1;i<=N&&flg;i++)
			if(A[i]>B[i]) flg=0;
			else now[A[i]-'a'][B[i]-'a']++,tgt[B[i]-'a']++;
		if(!flg){printf("-1\n");continue;}
		int ans=0;
		for(int v=0;v<20;v++)
		for(int u=0;u<v;u++)if(now[u][v]){
			for(int w=v;w<20;w++)
				now[v][w]+=now[u][w],now[u][w]=0;
			ans++;
		}
		printf("%d\n",ans);
	}
}