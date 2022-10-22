#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=100005;
const int inf=0x3f3f3f3f;
int n,m;
int a[maxn];
bool flag;
void dfs(int step,int k)
{
	if(step==n+1)
	{
		if(k%360==0)
			flag=1;
		return;
	}
	dfs(step+1,k+a[step]);
	dfs(step+1,k-a[step]);
}
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	if(flag) cout<<"YES";
	else cout<<"NO";
	return 0;
}