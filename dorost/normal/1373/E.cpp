/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 150;
	cin >> t;
	while (t--){
		int n = 150, k = 3;
		cin >> n >> k;
		if (k == 0){
			string s = "";
			if (n % 9)
				s += to_string (n % 9);
			while (n >= 9){
				s += "9";
				n -= 9;
			}
			cout << s << endl;
		}else if (k == 1){
			if(n == 1){
				cout << 0 << endl;
				continue;
			}
			if (n < 26){
				bool f = true;
				for (int i = 0; i <= 100; i ++){
					string t = to_string(i) + to_string(i + 1);
					int sum = 0;
					for (int j = 0; j < t.size(); j++){
						sum += (t[j] - '0');
					}
					if (sum == n){
						cout << i << endl;
						f = false;
						break;
					}
				}
				if (f){
					cout << -1 << endl;
				}
			}else{
				n -= 17;
				int x = n / 9;
				int y = n % 9;
				if (x % 2){
					x--;
					y += 9;
				}
				if (y % 2){
//					cerr << "hrr";
					n += 17;
					n -= 26;
					string s = "";
					n /= 2;
					if (n % 9)
						s += to_string (n % 9);
					while (n >= 9){
						s += "9";
						n -= 9;
					}
					s += "89";
					cout << s << endl;
					continue;
				}
				string s = "";
				if (y != 0)
					cout << y / 2;
				for (int i = 0; i < x / 2; i++){
					cout << 9;
				}
				cout << 8 << endl;
			}
		}else{
			int ans[51] = {-1, -1, 8997, -1, -1, 9997, -1, -1, 19997, -1, -1, 29997, -1, -1, 39997, -1, -1, 49997, -1, -1, 59997, -1, -1, 69997, -1, -1, 79997, -1, -1, 89997, -1, -1, 99997, -1, -1, 199997, -1, -1, 299997, -1, -1, 399997, -1, -1, 499997, -1, -1, 599997, -1, -1, 699997};
			if (n > 100 && k == 2){
				cout << ans[n - 100] << endl;
				continue;
			}
			int d[51] = {3988, 2987, 996, 5989, 4988, 3987, 1996, 6989, 5988, 4987, 2996, 7989, 6988, 5987, 3996, 8989, 7988, 6987, 4996, 9989, 8988, 7987, 5996, 19989, 9988, 8987, 6996, 29989, 19988, 9987, 7996, 39989, 29988, 19987, 8996, 49989, 39988, 29987, 9996, 59989, 49988, 39987, 19996, 69989, 59988, 49987, 29996, 79989, 69988, 59987, 39996};
			if (n > 100 && k == 3){
				cout << d[n - 100] << endl;
				continue;
			}
			bool f = true;
			for (int i = 0; i <= 10000; i++){
				int sum = 0;
				for (int j = i; j <= i + k; j++){
					string t = to_string(j);
					for (int k = 0; k < t.size(); k++){
						sum += t[k] - '0';
					}
				}
				if (sum == n){
					cout << i << endl;
					f = false;
					break;
				}
			}
			if (f){
				cout << -1 << endl;
			}
		}
	}
}