#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#define int long long
using namespace std; 
int t,p,a,b,c;
signed main(){
	cin>>t;
	while(t--){
		cin>>p>>a>>b>>c;
		int ans=1e18;
		if (p%a==0)ans=min(ans,0ll);
		else ans=min(ans,a-p%a);
		if (p%b==0)ans=min(ans,0ll);
		else ans=min(ans,b-p%b);
		if (p%c==0)ans=min(ans,0ll);
		else ans=min(ans,c-p%c);
		cout<<ans<<endl;
	}
	return 0;
}