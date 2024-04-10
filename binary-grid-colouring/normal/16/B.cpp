#include<bits/stdc++.h>
using namespace std;
int a[23];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		a[y]+=x;
	}
	int ans = 0;
	for(int i=10;i>=0;--i)
	{
		int cur = min(n,a[i]);
		ans += i*cur;
		n -= cur;
	}
	cout<<ans<<endl;
	return 0;
}