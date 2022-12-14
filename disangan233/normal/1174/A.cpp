#include<bits/stdc++.h>
using namespace std;
#define db double
#define re register int
#define ll long long
int n,m,ta,tb,k,a[200005],b[200005],ans;
int main()
{
	scanf("%d",&n);
	for(re i=1;i<=2*n;i++) scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	if(a[1]==a[2*n]) return puts("-1"),0;
	for(re i=1;i<=2*n;i++) printf("%d ",a[i]);
	return 0;
}