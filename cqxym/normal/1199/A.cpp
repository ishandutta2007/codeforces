#include<cstdio>
int a[100001];
int Min(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,x,y,i,j,m1,m2;
	scanf("%d%d%d",&n,&x,&y);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		m1=m2=a[i];
		for(j=i-1;j>=i-x&&j>-1;j--){
			m1=Min(m1,a[j]);
		}
		for(j=i+1;j<=i+y&&j<n;j++){
			m2=Min(m2,a[j]);
		}
		if(m1==m2&&m1==a[i]){
			printf("%d",i+1);
			return 0;
		}
	}
}