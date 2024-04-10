#include<bits/stdc++.h>
using namespace std;
int n,m,a[210],b[210],res;
bool ok[210][210];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int j=1;j<=m;j++)scanf("%d",&b[j]);
	for(int k=8;k>=0;k--){
		bool fl=true;
		for(int i=1;i<=n;i++){
			bool fd=false;
			for(int j=1;j<=m;j++)if(!ok[i][j]&&!(a[i]&b[j]&(1<<k)))fd=true;
			fl&=fd;
		}
		if(!fl){res+=(1<<k);continue;}
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ok[i][j]|=((a[i]&b[j]&(1<<k))!=0);
	}
	printf("%d\n",res);
	return 0;
}