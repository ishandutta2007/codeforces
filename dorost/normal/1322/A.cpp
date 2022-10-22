#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long ll;
typedef long double ld;

int main(){
	int n, x = 0, ans = 0;
	cin >> n;
	string s;
	cin >> s;
	int y = -1;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '('){
			x++;
		}else{
			x--;
		}
		if (x == 0){
			int b = 0;
			bool f = true;
			for (int j = y + 1; j <= i; j++){
				b += (s[i] == ')' ? 1 : -1);
				if (b < 0){
					f = false;
					break;
				}
			}
			if (f == false){
				ans += i - y;
			}
			y = i;
		}
	}
	if (x == 0)
		cout << ans;
	else
		cout << -1;
}