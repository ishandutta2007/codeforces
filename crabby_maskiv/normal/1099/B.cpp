#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=100005;
const int inf=0x3f3f3f3f;
int n,m;
int ans=inf;
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i*i<=n;i++)
	{
		ans=min(ans,(n+i-1)/i+i);
	}
	cout<<ans;
	return 0;
}