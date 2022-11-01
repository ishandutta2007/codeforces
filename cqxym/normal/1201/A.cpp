#include<cstdio>
int c[1001][5],a[1001];
int Max(int x,int y){
	return x>y?x:y;
}
int main(){
	int n,m,i,j,ans=0;
	scanf("%d%d",&n,&m);
	char s;
	for(i=0;i<n;i++){
		scanf("%c",&s);
		for(j=0;j<m;j++){
			scanf("%c",&s);
			c[j][s-65]++;
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<5;j++){
			a[i]=Max(a[i],c[i][j]);
		}
	}
	for(i=0;i<m;i++){
		scanf("%d",&n);
		ans+=a[i]*n;
	}
	printf("%d",ans);
	return 0;
}