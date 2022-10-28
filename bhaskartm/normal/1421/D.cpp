#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=2e18;
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int x, y;
		cin>>x>>y;
		int c[7];
		for(int i=1; i<=6; i++){
			cin>>c[i];
		}
		int v1=min(c[1]+c[5], c[6]);
		int v2=min(c[2], c[1]+c[3]);
		int v3=min(c[1], c[2]+c[6]);
		int v4=min(c[3], c[2]+c[4]);
		int v5=min(c[5], c[4]+c[6]);
		int v6=min(c[4], c[3]+c[5]);
		int ans=N;
		if(x>=0 && y>=0){
			ans=min(x*v1+y*v2, ans);
			if(x>=y){
				ans=min(ans, y*v3+(x-y)*v1);
				ans=min(ans, x*v3+(x-y)*v5);
			}
			else{
				ans=min(ans, x*v3+(y-x)*v2);
				ans=min(ans, y*v3+(y-x)*v4);
			}
			cout<<ans<<endl;
			continue;
		}
		if(x<=0 && y<=0){
			ans=min(ans, v4*(-x)+v5*(-y));
			if((-x)>=(-y)){
				ans=min(ans, (-y)*v6+(y-x)*v4);
				ans=min(ans, (-x)*v6+(y-x)*v2);
			}
			else{
				ans=min(ans, (-x)*v6+(x-y)*v5);
				ans=min(ans, (-y)*v6+(x-y)*v1);
			}
			cout<<ans<<endl;
			continue;
		}
		if(x>=0 && y<=0){
			ans=min(ans, v1*x-y*v5);
			ans=min(ans, x*v3+(x-y)*v5);
			ans=min(ans, (-y)*v6+(x-y)*v1);
			cout<<ans<<endl;
			continue;
		}
		if(x<=0 && y>=0){
			ans=min(ans, y*v2+(-x)*v4);
			ans=min(ans, y*v3+(y-x)*v4);
			ans=min(ans, (-x)*v6+(y-x)*v2);
			cout<<ans<<endl;
			continue;
		}
		
	}
	return 0;
}