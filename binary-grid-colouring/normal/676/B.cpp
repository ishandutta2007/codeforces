#include<bits/stdc++.h>
double glass[20][20];
int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	double flow;
	for(int k=1;k<=t;k++){
		glass[1][1]+=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(glass[i][j]>1){
					flow=glass[i][j]-1;
					glass[i][j]=1;
					glass[i+1][j]+=flow/2;
					glass[i+1][j+1]+=flow/2;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(glass[i][j]>1) ans++;
			if(1-glass[i][j]<0.0000001) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}