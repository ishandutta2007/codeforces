#include<cstdio>
using namespace std;
int n,a[400][400];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) a[i][j]=i*j%n;
	for(int i=0,b;i<n;++i){
		scanf("%d",&b);b=(b+n-a[i][i])%n;
		for(int j=0;j<n;++j) a[i][j]=(a[i][j]+b)%n;
	}
	for(int i=0;i<n;++i,putchar('\n')) for(int j=0;j<n;++j) printf("%d ",a[i][j]);
	return 0;
}