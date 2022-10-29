#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=200010;

int a[N],n,ans=0,bl[N],c[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x); a[x]++; bl[x]++;
	}
	for(int i=1;i<=150000;i++)
	{
		if(a[i]&&!bl[i-1]&&i>1) 
		{
			bl[i-1]++,a[i]--,bl[i]--;
		}
		if(a[i]&&bl[i]>1) bl[i+1]++,a[i]--,bl[i]--;
	}
	for(int i=1;i<=150001;i++) if(bl[i]) ans++;
	cout<<ans<<endl;
	return 0;
}