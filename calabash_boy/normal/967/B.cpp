#include<bits/stdc++.h>
using namespace std;

int n,u,v,a[120000];

int main(){
	scanf("%d%d%d",&n,&u,&v);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+2,a+n+1);
	long long sum=a[1];
	for(int i=2;i<=n;i++){
		sum+=a[i];
		if(sum*v>(long long)a[1]*u){
			printf("%d\n",n-i+1);return 0;
		}
	}
	puts("0");
	return 0;
}