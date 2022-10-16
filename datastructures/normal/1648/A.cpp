#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
#define int long long
using namespace std;
int n,m,a,ans;
vector<int> x[100005],y[100005];
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			scanf("%lld",&a);
			x[a].push_back(i);
			y[a].push_back(j);
		}
	for (int i=1;i<=100000;i++){
		sort(x[i].begin(),x[i].end());
		int s=0;
		for (int j=0;j<(int)x[i].size();j++){
			ans+=x[i][j]*j-s;
			s+=x[i][j];
		}
	}
	for (int i=1;i<=100000;i++){
		sort(y[i].begin(),y[i].end());
		int s=0;
		for (int j=0;j<(int)y[i].size();j++){
			ans+=y[i][j]*j-s;
			s+=y[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}