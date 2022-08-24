#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

pair<int, int> cand(int l, int r){
	int len = (r-l+1);
	if (len % 2 != 0){
		return {l+len/2, l+len/2};
	}
	return {l+len/2, l+len/2-1};
}

bool ask(int l, int r, int chosen){
	//cout << l << " " << r << " " << chosen << endl;
	int a = chosen+1, b = r;
	if (a <= b){
		pair<int, int> g = cand(a, b);
		bool res = false;
		//cout << chosen << " " << g.first << " " << g.second << endl;
		if ((g.first%2) == chosen%2){
			if (ask(a, b, g.first)) res = true;
		}
		if ((g.second%2) == chosen%2){
			if (ask(a, b, g.second)) res = true;
		}
		if (!res) return false;
	}

	a = l, b = chosen-1;
	if (a <= b){
		pair<int, int> g = cand(a, b);
		bool res = false;
		if ((g.first%2) != chosen%2){
			if (ask(a, b, g.first)) res = true;
		}
		if ((g.second%2) != chosen%2){
			if (ask(a, b, g.second)) res = true;
		}
		if (!res) return false;
	}
	return true;
}

int main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if (n==1){
		cout << 1;
		exit(0);
	}

	int ans = 0;

	ans += ask(0, n-1, n/2);

	if (n%2==0) ans += ask(0, n-1, n/2-1);

	cout << ans;




}