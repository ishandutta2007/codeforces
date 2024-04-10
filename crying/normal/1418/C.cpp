#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+10;
int t,n;
int f[MAXN][2],a[MAXN];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<=n+2;i++){
			a[i]=0;
		}
		for(int i=0;i<=n+2;i++){
			f[i][0]=f[i][1]=0;  
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=n;i>=1;i--){
			int x=a[i],y=a[i+1];
			int c1=(x)?1:0,c2=c1+((y)?1:0);
			f[i][0] = min(f[i+2][1]+c2,f[i+1][1]+c1);
			f[i][1] = min(f[i+2][0],f[i+1][0]);
		}
		printf("%d\n",f[1][0]);
	}
	
	return 0;
}