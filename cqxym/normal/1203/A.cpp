#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[401];
int main(){
	int q,n,i,j,k;
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		for(j=n;j<n+n;j++){
			a[j]=a[j-n];
		}
		bool f,r;
		for(j=0;j<n;j++){
			f=true;
			for(k=0;k<n;k++){
				if(a[j+k]!=k+1){
					f=false;
					break;
				}
			}
			if(f==true){
				break;
			}
		}
		for(j=n+n-1;j>=n;j--){
			r=true;
			for(k=0;k<n;k++){
				if(a[j-k]!=k+1){
					r=false;
					break;
				}
			}
			if(r==true){
				break;
			}
		}
		if((f|r)==true){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}