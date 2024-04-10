#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define int long long int
#define endl '\n'
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<pair<int, int>>ans;
	ans.pb({2, 2});
	ans.pb({3, 2});
	ans.pb({4, 2});
	ans.pb({4, 3});
	ans.pb({4, 4});
	ans.pb({3, 4});
	ans.pb({2, 4});
	ans.pb({2, 3});
	ans.pb({2, 1});
	ans.pb({2, 0});
	ans.pb({1, 0});
	ans.pb({0, 0});
	ans.pb({0, 1});
	ans.pb({0, 2});
	ans.pb({1, 2});
	int cnt=1;
	vector<pair<int, int>>ad;
	ad.pb({1, 0});
	ad.pb({2, 0});
	ad.pb({2, 1});
	ad.pb({2, 2});
	ad.pb({1, 2});
	ad.pb({0, 2});
	ad.pb({0, 1});
	int val=4;
	while(cnt!=n){
		for(auto u:ad){
			int fi=u.f+val;
			int se=u.s+val;
			ans.pb({fi, se});
		}
		cnt++;
		val+=2;
	}
	cout<<ans.size()<<endl;
	for(auto u:ans){
		cout<<u.f<<" "<<u.s<<endl;
	}
	return 0;
}