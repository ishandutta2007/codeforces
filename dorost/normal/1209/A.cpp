#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(s) (int)s.size()
#define fast  ios_base::sync_with_stdio(false), cin.tie(), cout.tie()

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	map <int, bool> mp;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(mp[i]){
			continue;
		}
		for(int j = 0; j < n; j++){
			if(a[j] % a[i] == 0){
				mp[j] = true;
			}
		}
		ans++;
		bool f = true;
		for(int j = 0; j < n; j++){
			if(mp[j] == false){
				f = false;
				break;
			}
		}
		if(f){
			cout << ans;
			break;
		}
	}
}