#include<iostream>
#include<string>
#include<algorithm>
#include<cassert>

using namespace std;

const int MAXN = 1e6 + 10;

int n, r;
string ans;

int cal(int a, int b, bool type = 0){
	int ret = 0, tot = 0;
	ans.clear();
	char cur = 'B';
	while (max(a, b) > 1 && min(a, b) >= 1){
		if (a < b)	swap(a, b);
		int z = a/b;
		if (b == 1){
			z = a - 1;
			a = 1;
		}
		else
			a %= b;
		ret += z-1;
		tot += z;

		if (type){
			while (z--)
				ans += cur;

			if (cur == 'B')
				cur = 'T';
			else
				cur = 'B';
		}
	}
	if (tot != n - 1 || min(a, b) < 1)	return -1;

	if (type){
		if (ans.size() && ans.back() == 'T')
			for (char &c:ans){
				if (c == 'T')	c = 'B';
				else	c = 'T';
			}
		ans += 'T';
	}

	if (a == b && a == 1)
		return ret;
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> r;
	if (n == 1){
		if (r > 1)
			cout << "IMPOSSIBLE\n";
		else
			cout << "0\nT\n";
		return 0;
	}

	int mn = 1e9, ind = -1;
	for (int i = 1; i < r; i++){
		int z = cal(i, r);
		if (~z && z < mn)
			mn = z, ind = i;
	}

	if (mn > 1e8)
		cout << "IMPOSSIBLE\n";
	else{
		cal(ind, r, 1);
		cout << mn << "\n";
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
	return 0;
}