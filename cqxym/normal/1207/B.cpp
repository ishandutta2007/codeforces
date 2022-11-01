#include<bits/stdc++.h>
using namespace std;
int a[51][51],ans[2][2501];
bool v[51][51];
int main(){
	int n,m,i,j,ct=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<n;i++){
		for(j=1;j<m;j++){
			if((v[i][j]==false||v[i-1][j-1]==false||v[i][j-1]==false||v[i-1][j]==false)&&a[i][j]==1&&a[i-1][j-1]==1&&a[i][j-1]==1&&a[i-1][j]==1){
				v[i][j]=v[i-1][j-1]=v[i][j-1]=v[i-1][j]=true;
				ans[0][ct]=i;
				ans[1][ct]=j;
				ct++;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j]==1&&v[i][j]==false){
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d\n",ct);
	for(i=0;i<ct;i++){
		printf("%d %d\n",ans[0][i],ans[1][i]);
	}
	return 0;
}