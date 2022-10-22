#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	scanf("%d",&n);
	fflush(stdout);
	for(int i=0;i<n;i++,puts(""))for(int j=0;j<n;j++)printf("%lld ",(i&1)?(1ll<<(i+j-1)):0);
	fflush(stdout);
	scanf("%d",&q);
	long long x;
	while(q--){
		scanf("%lld",&x);
		int xx=0,yy=0;
		fflush(stdout);
		puts("1 1");
		for(int i=0;i<2*n-2;i++){
			if((1ll<<i)&x){
				if(xx&1)yy++;
				else xx++;
			}else{
				if(xx&1)xx++;
				else yy++;
			}
			printf("%d %d\n",xx+1,yy+1);
		}
		fflush(stdout);
	}
}