#include <bits/stdc++.h>

using namespace std;

int ans[1010101];
int n,a,b;

void make(int c,int d)
{
	int s=1,i;
	for(;c--;){
		for(i=0;i<a;i++) ans[s+i] = s+(i+1)%a;
		s += a;
	}
	for(;d--;){
		for(i=0;i<b;i++) ans[s+i] = s+(i+1)%b;
		s += b;
	}
}

int main()
{
	int i;
	
	scanf("%d%d%d",&n,&a,&b);
	
	for(i=0;i*a<=n;i++){
		if((n-i*a)%b == 0) break;
	}
	
	if((n-i*a) % b || n-i*a < 0){
		printf("-1\n");
		return 0;
	}
	
	make(i,(n-i*a)/b);
	
	for(i=1;i<=n;i++) printf("%d ",ans[i]);
	
	printf("\n");
	
	return 0;
}