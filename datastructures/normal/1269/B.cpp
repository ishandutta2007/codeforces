#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define int long long
using namespace std;
int n,m,a[2005],b[2005],ans=2e9;
int c[2005];
inline bool check(int x){
	for (register int i=1;i<=n;i++)c[i]=(a[i]+x)%m;
	sort(c+1,c+1+n);
	for (int i=1;i<=n;i++)
		if (b[i]!=c[i])return 0;
	return 1;
}
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int j=1;j<=n;j++)cin>>b[j];
	sort(b+1,b+1+n);
	for (int i=1;i<=n;i++){
		if (check((b[i]+m-a[1]%m)%m))ans=min(ans,(b[i]+m-a[1]%m)%m);
	}
	cout<<ans<<endl;
	return 0;
}