#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--){
		int b, t, p;
		cin >> b >> t >> p;
		string s;
		cin >> s;
		int n = s.size();
		bool f = true;
		vector <pair <int, int>> v; 
		for (int i = 0; i < n && f; i++){
			if ((i == n - 1 &&  s[i] == s[i - 1])){
				if(s[i] == 'A')
					v.push_back({b, i});
				else
					v.push_back({t, i});
			}
			if (i == n - 1)
				continue;
			if (s[i] != s[i + 1] || (i == n - 1 &&  s[i] == s[i - 1])){
				if (s[i] == 'A'){
					v.push_back({b, i});
				}else
					v.push_back({t, i});
			}
		}
		reverse (v.begin(), v.end());
		for (int i = 0; i < v.size(); i++){
			p -= v[i].F;
			if (p < 0){
				cout << min(n, v[i].S + 2);
				f = false;
				break;
			}
		}
		if (f){
			cout << 1;
		}
		cout << endl;
	}
}