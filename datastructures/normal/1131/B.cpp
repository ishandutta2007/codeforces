#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#define int long long
using namespace std;
int n,a,b,la,lb,ans;
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	ans=1;
	cin>>n;
	while(n--){
		cin>>a>>b;
		if (la>lb){
			if (b>=la)ans+=min(b-la+1,a-la+1);
		}
		if (lb>la){
			if (a>=lb)ans+=min(a-lb+1,b-lb+1);
		}
		if (la==lb)ans+=min(a-la,b-lb);
		la=a,lb=b;
	}
	cout<<ans<<endl;
	return 0;
}