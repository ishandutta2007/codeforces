#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

int t,n,a[N];

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int bl=0;
		for(int j=30;j>=0;j--)
		{
			int sum=0;
			for(int i=1;i<=n;i++) if(a[i]&(1<<j)) sum++;
			if(sum%2==1)
			{
				if(sum%4==1)
				{
					bl=1;
				}
				else
				{
					if(n%2==1) bl=-1;
					else bl=1;
				}
				break;
			}
		}
		if(bl==1) puts("WIN");
		else if(bl==-1) puts("LOSE");
		else puts("DRAW");
	}
	return 0;
}