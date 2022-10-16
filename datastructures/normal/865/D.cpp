#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
priority_queue<int> h;
int n,len,p[300005],ans;
signed main(){
	cin>>n;
	for (register int i=1;i<=n;i++)scanf("%lld",&p[i]);
	for (register int i=1;i<=n;i++){
		if ((!h.empty())&&(-h.top()<p[i]))ans+=p[i]-(-h.top()),h.pop(),h.push(-p[i]);
		h.push(-p[i]);
	}
	cout<<ans<<endl;
	return 0;
}