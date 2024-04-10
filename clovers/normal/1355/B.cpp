#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

int t,a[N],n; 

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int now=0,pre=a[n],ans=0;
		for(int i=n;i>=1;i--)
		{
			if(pre-a[i]>now) now=0,pre=a[i];
			now++;
			if(now==pre) ans++,pre=a[i-1],now=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}