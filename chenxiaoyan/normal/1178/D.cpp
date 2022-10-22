#include<bits/stdc++.h>
using namespace std;
bool ispr(int x){
	for(int i=2;i*i<=x;i++)if(x%i==0)return false;
	return true;
}
const int N=1000;
int n;
bool vis[N+1][N+1];
bool ok[N+1];
int main(){
	scanf("%d",&n);
	for(int i=n;;i++)if(ispr(i)){
		printf("%d\n",i);
		for(int j=1;j<=n;j++)printf("%d %d\n",j,j<n?j+1:1),vis[j][j+1]=vis[j+1][j]=true;
		for(int j=1;j<=i-n;j++){
			if(ok[j]){i++;continue;}
			for(int k=j+2;k<=n;k++)if(!vis[j][k]){
				printf("%d %d\n",j,k);
				vis[j][k]=vis[k][j]=ok[j]=ok[k]=true;
				break;
			}
		}
		return 0;
	}
}