#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#pragma GCC optimize(2)
#define int long long
using namespace std;
const int N=2e5+3;
int n,m,x[N],p[N];
map<int,int> h;
signed main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		h.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>x[i]>>p[i];
			h[x[i]+p[i]+1]++,h[x[i]+1]-=2,h[x[i]-p[i]+1]++;
		}
		int now=0,k=0,lst=-1e15,kx=-1e15,ky=-1e15;
		for(auto v:h)
		{
			now+=k*(v.first-lst);
			k+=v.second;
			if(now>m)
			{
				kx=max(kx,now-v.first+1);
				ky=max(ky,now+v.first-1);
			}
			lst=v.first;
		}
		for(int i=1;i<=n;i++)
		{
			if(m>=kx+x[i]-p[i] && m>=ky-x[i]-p[i])	cout<<1;
			else	cout<<0;
		}
		cout<<"\n";
	}
	return 0;
}