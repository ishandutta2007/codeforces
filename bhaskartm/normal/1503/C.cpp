#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back


 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	
	vector<pair<int, int>>vec;
	int ans=0;
	for(int i=0; i<n; i++){
		int a, c;
		cin>>a>>c;
		vec.pb({a, a+c});
		ans+=c;
	}
	sort(vec.begin(), vec.end());
	int r=vec[0].s;
	int pt=1;

	while(pt<n){
		if(vec[pt].f<=r){
			r=max(r, vec[pt].s);
			pt++;
		}
		else{
			ans+=(vec[pt].f-r);
			r=vec[pt].s;
			pt++;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}