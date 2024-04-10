#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;

int main(){
	int n;
	cin >> n;
	pair<int, string> s[n];
	for (int i = 0; i < n; i++)
		cin >> s[i].S, s[i].F = s[i].S.size();
	sort(s, s + n);
	bool f = true;
	for (int i = 1; i < n; i++){
		bool h = false;
		if (s[i] == s[i - 1])
			continue;
		for (int j = 0; j < s[i].S.size(); j++){
			for (int k = j; k < s[i].S.size(); k++){
				if (s[i].S.substr(j , k) == s[i - 1].S){
					h = true;
					break;
				}
			}
		}
		if (h == false){
			f = false;
		}
	}
	cout << (f ? "YES" : "NO") << endl;
	if (f){
		for (int i = 0; i < n; i++){
			cout << s[i].S << endl;
		}
	}
}