#include <bits/stdc++.h>
           
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
map<int, int> was;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		int mask = 0;
		for (char c : s) mask ^= (1 << (c - 'a'));
		ans += was[mask];
		for (int j = 0; j < 26; j++) ans += was[mask ^ (1 << j)];
		was[mask]++;
	}
	cout << ans;
}