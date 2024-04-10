#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
int read(){
    int res;
    scanf("%lld",&res);
    return res;
}
int n,a[N],ans[N];
signed main(){
	n=read();
	for(int i=1;i<n;i++){
		printf("? %lld %lld\n",i,i+1);
		fflush(stdout);
		a[i]=read();
	}
	printf("? 1 3\n");
	fflush(stdout);
	a[n]=read();
	ans[1]=a[n]-a[2];
	for(int i=2;i<=n;i++)
		ans[i]=a[i-1]-ans[i-1];
	printf("!");
	for(int i=1;i<=n;i++)
		printf(" %lld",ans[i]);
	fflush(stdout);
    return 0;
}