#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

int t,n,a[N];

int main()
{
	int t; cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int bl=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]!=a[i+1]) bl=0;
		}
		if(bl==1) printf("%d\n",n);
		else puts("1");
	}
	return 0;
}