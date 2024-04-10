#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ii pair<int, int>
#define mk make_pair

#define N 1000007 //10e6 + 7

ll n, k, A, a[N], c[N], ans;
multiset<int> s;


int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> A;
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < n; i++){
		s.insert(c[i]);
		while(k < a[i]){
			if(s.size() == 0){
				cout << -1;
				return 0;
			}
			ans += *s.begin();
			s.erase(s.begin());
			k += A;
		}
	}
	cout << ans;
	
	return 0;
}