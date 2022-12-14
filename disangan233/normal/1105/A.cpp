#include<bits/stdc++.h>
using namespace std;
#define re register int
int n,a[1005];
int main()
{
	cin>>n;
	for(re i=1;i<=n;i++) cin>>a[i];
	re ans=0x7fffffff,anss,maxn;
	for(re i=1;i<=100;i++)
	{
		re now=0,noww=0;
		for(re j=1;j<=n;j++) if(abs(a[j]-i)>1) now+=abs(a[j]-i)-1;
		if(now<ans) ans=now,anss=i;
	}
	cout<<anss<<" "<<ans<<endl;
	return 0;
}