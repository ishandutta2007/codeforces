#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
int n,ans,a[200005],pos[100005][2];
signed main(){
	cin>>n;
	pos[0][0]=pos[0][1]=1;
	for (int i=1;i<=2*n;i++){
		scanf("%lld",&a[i]);
		if (pos[a[i]][0]==0)pos[a[i]][0]=i;
		else pos[a[i]][1]=i;
	}
	for (int i=1;i<=n;i++)
		ans+=min(abs(pos[i][0]-pos[i-1][0])+abs(pos[i][1]-pos[i-1][1]),abs(pos[i][0]-pos[i-1][1])+abs(pos[i][1]-pos[i-1][0]));
	cout<<ans<<endl;
	return 0;
}