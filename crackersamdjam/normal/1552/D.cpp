#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

int n, a[11];

void run(){
	map<int, int> mp;
	for(int i = 0; i < (1<<n); i++){
		int s = 0;
		for(int j = 0; j < n; j++){
			if(i&(1<<j))
				s += a[j];
		}
		if(mp[s]){
			cout<<"YES\n";
			return;
		}
		mp[s]++;
	}
	cout<<"NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		run();
	}
}
/*
duplicates yes
if a sum appears twice, yes?
*/