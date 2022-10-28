#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int x1, y1, z1, x2, y2, z2;
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		int ans=0;
		int val=min(y2, z1);
		ans=2*val;
		z1=z1-val;
		y2=y2-val;
		val=min(z1, z2);
		z1-=val;
		z2-=val;
		val=min(x2, z1);
		z1-=val;
		x2-=val;
		val=min(y1, y2);
		y1-=val;
		y2-=val;
		val=min(y1, x2);
		y1-=val;
		x2-=val;
		ans-=(2*(min(y1, z2)));
		cout<<ans<<endl;
	}
	return 0;
}