#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n, m;
	string s, t;
	cin >> n >> m;
	int x = n, y = m;
	if (y == 0 && x == 1)
		s = "0";
	while (y){
		if (x == 1){
			s += char('0' + y);
			y = 0;
		}else if (y >= 10){
			s += "9";
			y -= 9;
			x --;
		}else{
			if (y <= 10){
				s += char('0' + y - 1);
				y = 0;
				for (int i = 0; i < x - 2; i++){
					s += '0';
				}
				if (x >= 1)
					s += '1';
				x = 0;
			}
		}
	}
	if (s.size() != n){
		cout << "-1 -1\n";
		return 0;
	}
	int sum = 0;
	bool f = true;
	for (int i = 0; i < n; i++) {
		sum += s[i] - '0';
		if (s[i] < '0' || s[i] > '9')
			f = false;
	}
	if (sum != m || f == false){
		cout << "-1 -1\n";
		return 0;
	}
	reverse(s.begin(), s.end());
	cout << s << ' ';
	x = n, y = m;
	while (x){
		if (y >= 9){
			t += '9';
			x --;
			y -= 9;
		}else{
			t += ('0' + y);
			y = 0;
			x --;
		}
	}
	cout << t;
}