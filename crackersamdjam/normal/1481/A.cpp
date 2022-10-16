#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;


int main(){
	int t, x, y;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>x>>y;
		swap(x, y);
		string s; cin>>s;
		map<char, int> mp;
		for(auto c: s)
			mp[c]++;
		
		int ok = 1;
		if(x > 0 and mp['U'] < x)
			ok = 0;
		if(x < 0 and mp['D'] < abs(x))
			ok = 0;
		if(y > 0 and mp['R'] < y)
			ok = 0;
		if(y < 0 and mp['L'] < abs(y))
			ok = 0;

		cout<<(ok?"YES":"NO")<<'\n';
	}
}