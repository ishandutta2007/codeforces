#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 1e5+5;


void run(){
	string s; cin>>s;
	int n = size(s);
	map<char, int> mp;
	for(auto c: s){
		mp[c]++;
	}
	sort(all(s));
	
	if(size(mp) == 1){
		cout<<s<<'\n';
	}
	else if(size(mp) == 2){
		pair<char, int> a = *mp.begin();
		pair<char, int> b = *next(mp.begin());

		if(a.second == 1){
			cout<<s<<'\n';
			return;
		}
		if(b.second == 1){
			reverse(all(s));
			cout<<s<<'\n';
			return;
		}
		// cout<<a.second<<' '<<b.second<<endl;
		if(a.second-b.second <= 2){
			cout<<a.first;
			cout<<a.first;
			a.second--;
			a.second--;
			while(b.second--){
				cout<<b.first;
				if(a.second){
					cout<<a.first;
					a.second--;
				}
			}
			cout<<'\n';
			return;
		}

		cout<<a.first;
		a.second--;
		while(b.second--)
			cout<<b.first;
		while(a.second--)
			cout<<a.first;
		// cout<<". more a";
		cout<<'\n';
		return;
	}
	else{
		// more than two
		//if any appears exactly once, use it first
		for(auto &[a, b]: mp){
			if(b == 1){
				cout<<a;
				b--;
				for(auto &[a, b]: mp){
					while(b--)
						cout<<a;
				}
				cout<<'\n';
				return;
			}
		}

		pair<char, int> a = *mp.begin();
		mp.erase(mp.begin());
		int rem = n-a.second;
		if(a.second-rem <= 2){
			//same technique of spacing out
			
			queue<char> rest;
			for(auto [a, b]: mp){
				while(b--)
					rest.emplace(a);
			}

			cout<<a.first;
			cout<<a.first;
			a.second--;
			a.second--;
			while(size(rest)){
				cout<<rest.front();
				rest.pop();
				if(a.second){
					cout<<a.first;
					a.second--;
				}
			}
			cout<<'\n';
			return;
		}
		
		auto it = next(mp.begin());
		char c = it->first;
		it->second--;
		queue<char> rest;
		for(auto [a, b]: mp){
			while(b--)
				rest.emplace(a);
		}

		cout<<a.first;
		a.second--;
		cout<<rest.front();
		rest.pop();
		while(a.second--)
			cout<<a.first;
		cout<<c;
		while(size(rest)){
			cout<<rest.front();
			rest.pop();
		}
		cout<<'\n';
		return;

		cout<<"idk"<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin>>t;
	while(t--){
		run();
	}
}