#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	int n;scanf("%d",&n);
	for(int i=2;i*i<=n;i++)if(n%i==0&&__gcd(i,n/i)==1){
		for(int j=1,x;j<i;j++)if((n-1-n/i*j)%i==0){
			x=(n-1-n/i*j)/i;
			if(x>0&&x<n/i){
				puts("YES\n2");
				printf("%d %d\n%d %d\n",j,i,x,n/i);
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}