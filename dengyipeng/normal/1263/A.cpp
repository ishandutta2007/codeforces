#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int T,a[4],sum;

int main(){
	scanf("%d",&T);
	while (T--){
		for(int i=1;i<=3;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+3);
		sum=a[1]+a[2]+a[3];
		int tmp=a[2]-a[1];
		a[2]-=tmp,a[3]-=tmp;
		tmp=min(min(a[3]-a[2],a[3]/2),a[2]);
		a[3]-=tmp*2,a[2]-=tmp,a[1]-=tmp;
		tmp=min(min(a[1],a[2]),a[3])/2;
		a[1]-=tmp*2,a[2]-=tmp*2,a[3]-=tmp*2;
		if (a[1]&&a[2]) a[1]--,a[2]--;
		if (a[2]&&a[3]) a[2]--,a[3]--;
		if (a[1]&&a[3]) a[1]--,a[3]--;
		printf("%d\n",(sum-a[1]-a[2]-a[3])/2);
	}
}