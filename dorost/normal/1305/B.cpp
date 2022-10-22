#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	string s;
	cin >> s;
	int n = s.size(), mx = 0, an = -1;
	for (int i = 0; i < n; i++){
		int x = 0, y = 0;
		for (int j = 0; j <= i; j++){
			if (s[j] == '(')
				x++;
		}
		for (int j = i + 1; j < n; j++){
			if (s[j] == ')'){
				y++;
			}
		}
		if (min(x, y) > mx){
			mx = min(x, y);	
			an = i;
		}
	}
	if (mx == 0){
		cout << "0\n";
		return 0;
	}else{
		cout << "1\n";
	}
	cout << mx * 2 << '\n';
	int h = 0;
	for (int i = 0; i <= an; i++){
		if (h >= mx)
			break;
		if (s[i] == '('){
			cout << i + 1 << ' ';
			h++;
		}
	}
	h = 0;
	vector <int> v;
	for (int i = n - 1; i >= an; i--){
		if (h >= mx)
			break;
		if (s[i] == ')'){
			v.push_back(i + 1);
			h++;
		}
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << ' ';
	}
}