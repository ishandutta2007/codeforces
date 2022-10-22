#include<cstdio>
#include<cstring> 
using namespace std;
int n,m,a[510],b[510],sum[510];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[a[i]]++;
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]),sum[b[i]]++;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(sum[a[i]+b[j]]==0){
				printf("%d %d",a[i],b[j]);
				return 0;
			}
		}
	}
	return 0;
}