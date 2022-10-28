#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int p, q;
		cin>>p>>q;
		if(p%q!=0){
			cout<<p<<endl;
			continue;
		}
		vector<pair<int, int>>f;
		int qq=q;
		for(int x=2; x*x<=qq; x++){
			int cnt=0;
			while(qq%x==0){
				qq=qq/x;
				cnt++;
			}
			if(cnt>0){
				f.pb({x, cnt});
			}
		}
		if(qq>1){
			f.pb({qq, 1});
		}
		
		int mini=1e18;
		for(auto u:f){
			int val=(u.f);
			int cnt=0;
			int pp=p;
			while(pp%val==0){
				pp=pp/val;
				cnt++;
			}
			int diff=cnt-u.s;
			int num=1;
			diff++;
			while(diff--){
				num=num*val;
			}
			mini=min(mini, num);
		}
		cout<<p/mini<<endl;
	}
	
	
	return 0;
}