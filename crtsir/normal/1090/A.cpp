#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};
const long long llinf=9223372036854775807ll;
const int N=100005;
long long n,m,slr,maxv[200005];
long long ans,maxx;
vector<int> v[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			cin>>slr;
			v[i].push_back(slr);
		}
	}
	maxx=-llinf;
	for(int i=1;i<=n;i++)
	{
		maxv[i]=-llinf;
		for(int j=0;j<v[i].size();j++)
			maxv[i]=max(int(maxv[i]),v[i][j]);
		maxx=max(maxx,maxv[i]);
	}
	for(int i=1;i<=n;i++)
		ans+=(maxx-maxv[i])*(int(v[i].size()));
	cout<<ans;
	return 0;
}