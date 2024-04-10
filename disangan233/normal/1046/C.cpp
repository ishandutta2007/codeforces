#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
#define is_a *
#define inf 0x7ffffffffffff
ll d,n,a[200005],b[200005],ans;
char did;
priority_queue<int>q;
inline ll read()
{
	re chen_zhe=0,JK=1;did=getchar();
	while(!isdigit(did))JK=did=='-'?-1:JK,did=getchar();
	while(isdigit(did))chen_zhe=chen_zhe*10+did-'0',did=getchar();
	return chen_zhe is_a JK;
}
inline bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	n=read();d=read();
	for(re i=1;i<=n;i++)a[i]=read();
	for(re i=1;i<=n;i++)b[i]=read();
	sort(b+1,b+n+1,cmp);
	re bj=a[d]+b[1],cnt=n;
	a[d]=0;
	sort(a+1,a+n+1,cmp);
	for(re i=1;i<n;i++)
	{
		if(a[i]+b[cnt]>bj) ans++;
		else cnt--;
	}
	cout<<ans+1<<endl;
	return 0;
	
}