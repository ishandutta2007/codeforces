#include<bits/stdc++.h>
using namespace std;
#define db double
#define re register int
#define ll long long
int n,a[100005],b[100005],num;
queue<int>p,q;
int main()
{
	scanf("%d",&n);
	for(re i=1;i<=n;i++) scanf("%d",&a[i]),num+=(a[i]&1);
	if(num!=n&&num!=0) sort(a+1,a+n+1);
	for(re i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}