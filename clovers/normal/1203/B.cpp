#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=10200;

int T,a[N],n,t[N];

int main()
{
	cin>>T;
	while(T--)
	{
		int bl=1;
		memset(t,0,sizeof(t));
		scanf("%d",&n);
		for(int i=1;i<=n*4;i++)
		{
			scanf("%d",&a[i]);
			t[a[i]]++;
		}
		for(int i=1;i<=10000;i++) if(t[i]%2!=0) bl=0;
		vector<int> v;
		for(int i=1;i<=10000;i++) while(t[i]%2==0&&t[i]) v.push_back(i),t[i]-=2;
		int now=-1;
		for(int i=0;i<(int)v.size()/2;i++)
		{
			int x=v[i];
			int y=v[(int)v.size()-i-1];
			if(now==-1) now=x*y;
			else if(now!=x*y) bl=0;
		}
		if(!bl) puts("NO");
		else puts("YES");
	}
	return 0;
}