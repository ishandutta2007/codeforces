#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_prime(int x){
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0){
			return false;
		}
	}		
	return true;
}

int main(){
	map <int, int> mp;
	mp[1] = 1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		ll x;
		cin >> x;
		ll s = sqrt(x);
		if(s * s != x){
			cout << "NO" << endl;
			continue;
		}
		if(mp[s] == 1){
			cout << "NO" << endl;
		}else if(mp[s] == 2){
			cout << "YES" << endl;
		}else{
			if(is_prime(s)){
				mp[s] = 2;
				cout << "YES" << endl;
			}else{
				mp[s] = 1;
				cout << "NO" << endl;
			}
		}
	}
}