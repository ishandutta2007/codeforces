#include<cstdio>
int a[501][501],n,m;
int Min(int x,int y){
	return x<y?x:y;
}
bool Check(){
	for(int i=1;i<=n;i++){
		if(a[i][m]<=a[i-1][m]){
			return false;
		}
	}
	for(int i=1;i<=m;i++){
		if(a[n][i]<=a[n][i-1]){
			return false;
		}
	}
	return true;
}
int main(){
	int s=0,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			s+=a[i][j];
		}
	}
	bool x=true;
	for(i=n-1;i>0;i--){
		for(j=m-1;j>0;j--){
			if(a[i][j]==0){
				a[i][j]=Min(a[i+1][j],a[i][j+1])-1;
				s+=a[i][j];
			}
			if(a[i][j]<=a[i-1][j]||a[i][j]<=a[i][j-1]||a[i][j]>=a[i+1][j]||a[i][j]>=a[i][j+1]){
				x=false;
			}
		}
	}
	if(x==false||Check()==false){
		printf("-1");
	}else{
		printf("%d",s);
	}
	return 0;
}