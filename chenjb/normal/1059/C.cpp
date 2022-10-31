#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define pb push_back
using namespace std;
#define ll long long
vector<int> ans;
void dfs(int n,int p)
{
	for (int i=1;i<=n;i++)
	{
		if ((n-i+1)*2>n){ ans.pb(p); continue; }
		int j; for(j=1;(n-i+1)*(j+1)<=n;j++);
		dfs(n-i+1,p*j);
		break;
	}
}
int main()
{
	int n;
	cin>>n;
	dfs(n,1);
	for(auto p:ans)printf("%d ",p); puts("");
}