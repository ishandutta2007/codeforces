#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		sort(s.begin(), s.end());
		string t = s;
		reverse(t.begin(), t.end());
		if(t == s){
			cout << -1;
		}else{
			cout << s;
		}
		cout << endl;
	}
}