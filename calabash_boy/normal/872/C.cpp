#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	scanf("%d",&q);
	while (q--){
		scanf("%d",&n);
		int k = n/4;
		int flag = n%4;
		if (flag==0){
			if (k>=1){
				printf("%d\n",k);
			}else{
				printf("-1\n");
			}
		}else if (flag==1){
			if (k>=2){
				printf("%d\n",k-1);
			}else{
				printf("-1\n");
			}
		}else if (flag==2){
			if (k>=1){
				printf("%d\n",k);
			}else{
				printf("-1\n");
			}
		}else if (flag==3){
			if (k>=3){
				printf("%d\n",k-1);
			}else{
				printf("-1\n");
			}
		}
	}
	return 0;
}