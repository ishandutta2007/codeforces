//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int q;
string fix(string s){
	string t;
	int cnt = 0;
	for(char c : s){
		if(c == 'B') cnt++;
		else{
			t += c;
			if(Sz(t) > 1 && t[Sz(t) - 2] == t[Sz(t) - 1]){
				t.pop_back();
				t.pop_back();
			}
		}
	}
	if(cnt & 1) t += 'B';
	return t;
}


int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		string s, t;
		cin >> s >> t;
		if(fix(s) == fix(t)){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	
	return 0;
}