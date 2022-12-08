#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (x+z<=y){
			puts("0");
			continue;
		}
		int l=0,r=z,ans;
		while (l<=r){
			int mid=(l+r)/2;
			if (x+mid>y+z-mid){
				r=mid-1; ans=mid;
			} else l=mid+1;
		}
		printf("%d\n",z-ans+1);
	}
	return 0;
}