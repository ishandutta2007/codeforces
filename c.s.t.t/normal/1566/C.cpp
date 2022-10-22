#include<bits/stdc++.h>
using namespace std;
int T,n,res,las[100100][2],f[100100];
char s[2][100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,s[0]+1,s[1]+1);
		for(int i=1;i<=n;i++){
			las[i][0]=las[i-1][0];
			las[i][1]=las[i-1][1];
			las[i][s[0][i]-'0']=i;
			las[i][s[1][i]-'0']=i;
		}
		for(int i=1;i<=n;i++){
			f[i]=f[i-1];
			if(las[i][0])f[i]=max(f[i],f[las[i][0]-1]+1);
			if(min(las[i][0],las[i][1]))f[i]=max(f[i],f[min(las[i][0],las[i][1])-1]+2);
		}
		printf("%d\n",f[n]);
	}
	return 0;
}