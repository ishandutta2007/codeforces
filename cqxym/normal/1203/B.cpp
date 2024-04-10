#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[401];
int main(){
	int q,n,i,j,k,s;
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&n);
		n<<=2;
		for(j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		sort(a,a+n);
		if(a[0]!=a[1]||a[n-1]!=a[n-2]){
			printf("NO\n");
			continue;
		}
		s=a[0]*a[n-1];
		bool f=true;
		for(j=2;j<n/2;j+=2){
			if(a[j]!=a[j+1]||a[n-j-1]!=a[n-j-2]||s!=a[j]*a[n-j-1]){
				printf("NO\n");
				f=false;
				j=n/2;
			}
		}
		if(f==true){
			printf("YES\n");
		}
	}
	return 0;
}