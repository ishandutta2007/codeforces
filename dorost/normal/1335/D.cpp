#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int n = 9;
string s[n];
vector <pair <int, int>> v = {{0, 0},{1, 4},{2, 8},{3, 1},{4, 5},{5, 6},{6, 2},{7, 3},{8, 7}};
void solve(){
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
	for (int i = 0; i < n; i++){
		 s[v[i].F][v[i].S] = s[v[i].F][v[i].S] + 1;
		 if (s[v[i].F][v[i].S] > '9')
			 s[v[i].F][v[i].S]  = '1';
	}
	for (int i = 0; i < n; i++){
		cout << s[i] << endl;
	}
}

int32_t main(){
	int t;
	cin >> t;
	while (t--)
		solve();
}