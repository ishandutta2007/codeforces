#include<algorithm>
#include<stdio.h>
using namespace std;
long long a[200001];
int main(){
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int u=n>>1,v;
	a[n]=3e9;
	while(true){
		v=upper_bound(a+u,a+n,a[u])-a;
		if((a[v]-a[u])*(v-u)>=k){
			printf("%d",a[u]+k/(v-u));
			return 0;
		}
		k-=(a[v]-a[u])*(v-u);
		for(i=u;i<v;i++){
			a[i]=a[v];
		}
	}
}