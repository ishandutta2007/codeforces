#include<bits/stdc++.h>
using namespace std;
const int N=5+1e3;
int s[N];
int main(){
	int n; scanf("%d",&n);
	for(int i=2;i<=n;++i){
		printf("? 1 %d\n",i);
		fflush(stdout);
		scanf("%d",&s[i]);
	}
	printf("? 2 %d\n",n);
	fflush(stdout);
	int x; scanf("%d",&x);
	s[1]=s[n]-x;
	printf("! ");
	for(int i=1;i<=n;++i)
		printf("%d ",s[i]-s[i-1]);
	puts("");
	fflush(stdout);
	return 0;
}