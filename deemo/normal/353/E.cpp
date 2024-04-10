#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 1e6 + 10;

int n;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;	n = s.size();
	if (n < 4){
		cout << "1\n";
		return	0;
	}

	int ans = 0;
	for (int i = 0; i < n; i++){
		int a = 0, b = 0;
		int j = i;
		while (a < 2 && s[(j + n - 1) % n] == '0')	j = (j + n - 1) % n, a++;
		if (a == 0)	continue;

		j = i;
		while (b < 2 && s[j] == '1')	j = (j + 1) % n, b++;
		if (b == 0)	continue;
		
		if (a > 1)	ans++;
		if (b > 1)	ans++;
	}

	int ind = 0;
	while (ind < n && s[ind] != s[(ind + 1) % n])	ind++;
	if (ind == n){
		cout << n/2 << "\n";
		return 0;
	}

	rotate(s.begin(), s.begin() + (ind + 1) % n, s.end());
	for (int i = 0; i < n;){
		int j = i + 1;
		while (j < n && s[j] != s[j - 1])	j++;
		ans += (j - i - 2)/2;
		i = j;
	}

	cout << ans << "\n";
	return	0;
}