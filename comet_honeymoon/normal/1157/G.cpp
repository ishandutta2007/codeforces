#include<bits/stdc++.h>
using namespace std;

int N,M;
bool a[205][205],b[205][205];
int ans1[205],ans2[205];

int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	for(int j=1;j<=M;j++)
		scanf("%d",&a[i][j]);
	for(int j=0;j<=M;j++)
	for(ans1[1]=0;ans1[1]<=1;ans1[1]++){
		for(int k=1;k<=M;k++){
			b[1][k]=(k>j);
			ans2[k]=b[1][k]^a[1][k]^ans1[1];
		}
		bool flg=(j==M),isans=1;
		for(int i=2;i<=N&&isans;i++){
			for(int k=1;k<=M;k++)
				b[i][k]=a[i][k]^ans2[k];
			if(!flg){
				ans1[i]=b[i][1]^1;
				for(int k=1;k<=M;k++) if((b[i][k]^ans1[i])==0){isans=0;break;}
			}
			else{
				ans1[i]=b[i][1];
				for(int k=1;k<=M;k++)
					if((b[i][k]^ans1[i])==0)
						{if(!flg){isans=0;break;}}
					else flg=0;
			}
		}
		if(isans){
			printf("YES\n");
			for(int k=1;k<=N;k++) printf("%d",ans1[k]);printf("\n");
			for(int k=1;k<=M;k++) printf("%d",ans2[k]);printf("\n");
			return 0;
		}
	}
	printf("NO\n");
}