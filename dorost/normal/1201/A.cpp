#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main(){
	int n, m;
	cin >> n >> m;
	string s[n];
	int a[m], ans = 0, sum = 0;
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
	for (int i = 0; i < m; i++){
		cin >> a[i];
	}
	for (int i = 0; i < m; i++){
		string t;
		for (int j = 0; j < n; j++){
			t += s[j][i];
		}
		int cnt[5] = {};
		for (int j = 0; j < n; j++){
			cnt[t[j] - 'A'] ++;
		}
		sort (cnt, cnt + 5);
		sum += cnt[4] * a[i];
	}
	cout << sum;
}