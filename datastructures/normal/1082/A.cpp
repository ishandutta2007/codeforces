#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int t,n,x,y,d;
inline int work(int x){
	return (x-1)/d+1;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>x>>y>>d;
		int ans=2e9;
		if (x>y){
			if ((x-y)%d==0)ans=min(ans,(x-y)/d);
			if ((y-1)%d==0)ans=min(ans,work(x-1)+(y-1)/d);
			if ((n-y)%d==0)ans=min(ans,work(n-x)+(n-y)/d);
			if (ans==2e9)cout<<-1<<endl;
			else cout<<ans<<endl;
			continue;
		}
		if (x<=y){
			if ((y-x)%d==0)ans=min(ans,(y-x)/d);
			if ((y-1)%d==0)ans=min(ans,work(x-1)+(y-1)/d);
			if ((n-y)%d==0)ans=min(ans,work(n-x)+(n-y)/d);
			if (ans==2e9)cout<<-1<<endl;
			else cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}