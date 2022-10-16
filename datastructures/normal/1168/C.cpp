#include <iostream>
#include <cstdio>
using namespace std;
int n,q,a[300005],f[300005][35],last[35];
int main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		for (int j=0;j<30;j++){
			if ((a[i]&(1<<j))==0)continue;
			if (last[j]!=0){
				for (int k=0;k<30;k++)
					f[i][k]=max(f[i][k],f[last[j]][k]); 
			}
			last[j]=i;
			f[i][j]=i; 
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int fg=0;
		for (int i=0;i<30;i++)
			if (((a[x]&(1<<i))!=0)&&(f[y][i]>=x))fg=1;
		if (fg==1)puts("Shi");
		else puts("Fou");
	}
	return 0;
}