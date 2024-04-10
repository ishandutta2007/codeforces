#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int n;
int a[maxn];
bool z1,z0;
int main(){
	scanf("%d",&n); 
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if (a[i]%2==1) z1=1;
		if (a[i]%2==0) z0=1;
	}
	if (z1==0&&z0==1){
		for (int i=1;i<=n;++i)
		printf("%d ",a[i]);
		return 0;
	} else 
	if (z1==1&&z0==0){
		for (int i=1;i<=n;++i)
		printf("%d ",a[i]);
		return 0;
	} else {
		sort(a+1,a+1+n);
		for (int i=1;i<=n;++i)
		printf("%d ",a[i]);
	}
	return 0;
}