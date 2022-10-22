#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;

int main(){
 	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int n = s.size() + 1;
		s += '@';
		int an = 1;
		vector <pair<int, int>> v;
		for (int i = 1; i < n; i++){
			if (s[i] != s[i - 1]){
				v.push_back({an, s[i - 1]});
				an = 1;
			}else{
				an ++;
			}
		}
		set <char> st;
		for (int i = 0; i < v.size(); i++){
			if (v[i].F % 2){
				st.insert(v[i].S);
			}
		}
		for (auto c : st){
			cout << c;
		}
		cout << endl;
	}
}