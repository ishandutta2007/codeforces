#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=110;
int t,n,a[MAXN],l[MAXN],val[MAXN],tot;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(val,0,sizeof val);
		tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&l[i]);
			if(!l[i]){
				val[++tot]=a[i];
			}
		}
		sort(val+1,val+1+tot,greater<int>());
		for(int i=1,j=1;i<=n;i++){
			if(!l[i]){
				a[i]=val[j++];
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	
	return 0;
}