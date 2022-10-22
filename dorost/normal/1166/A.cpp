/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102, M = 26;
string s[N];
int cnt[M];

int C(int x){
	return (x * (x - 1)) / 2;
}

int32_t main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		cnt[s[i][0] - 'a'] ++;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++){
		ans += C(cnt[i] / 2) + C(cnt[i] - cnt[i] / 2);
	}
	cout << ans;
}