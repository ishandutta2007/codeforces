#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
int n,k,x[100005],s,c[100005],ans;
priority_queue <int>h;
signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)cin>>x[i];
	cin>>s;
	for (int i=1;i<=n;i++)cin>>c[i];
	int flag=1;
	for (int i=1;i<=n&&flag;i++){
		h.push(-c[i]);
		while(k<x[i]&&!h.empty()){
			k+=s;
			ans+=-h.top();
			h.pop();
		}
		if (k<x[i])flag=0;
	}
	if (flag)cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}