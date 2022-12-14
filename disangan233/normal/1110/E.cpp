#include<bits/stdc++.h>
using namespace std;
#define re register int
#define mp pair<int,int>
int cnt,n,a[100005],b[100005],s[100005],t[100005];
int main()
{
	scanf("%d",&n);
	for(re i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=a[i]-a[i-1];
	for(re i=1;i<=n;i++) scanf("%d",&b[i]),t[i]=b[i]-b[i-1];
	sort(s+1,s+n+1);sort(t+1,t+n+1);
	if(a[1]!=b[1]||a[n]!=b[n]) return puts("No"),0;
	for(re i=1;i<=n;i++) if(s[i]!=t[i]) return puts("No"),0;
	return puts("Yes"),0;
}