#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map> 
using namespace std;
const int MAXN=4010;
int f[MAXN][MAXN];//ij
int a[MAXN],n,ans;
map<int,int>g;
int main(){
	scanf("%d",&n);
	if(n<=2){
		printf("%d\n",n);return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ans=2;
	f[1][0]=1;
	f[2][1]=2;
	for(int i=3;i<=n;i++){
		int cnt=1;
		g[a[i]]=0;
		for(int j=1;j<i;j++){
			if(a[j]==a[i]){
				cnt++;
				g[a[i]]=j;
				f[i][j]=cnt;
			}else{
				if(g[a[i]]){
					f[i][j]=1+f[j][g[a[i]]];
				}else{
					f[i][j]=2;
				}
			}
			ans=max(ans,f[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}