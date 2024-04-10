#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,a[N],cnt,p;LL sum;
void fail(){
	puts("cslnb");exit(0);
}
void win(){
	puts("sjfnb");exit(0);
}
int main(){
	scanf("%d",&n);a[0]=-1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)if(a[i]==a[i-1])cnt++,p=i-1;
	if(cnt>=2||a[p]==a[p-1]+1)fail();
	LL re=sum-1ll*n*(n-1)/2;
	if(re&1)win();
	fail();
	return 0;
}