#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
string r[N];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--){
		string s;
		int n, k;
		cin >> n >> k >> s;
		for (int i = 0; i < k; i++)
			r[i] = "";
		sort(s.begin(), s.end());
		for (int i = 0; i < k; i++){
			r[i] += s[i];
		}
		bool f = true;
		for (int i = 0; i < k - 1; i++){
			if (s[i] != s[i  + 1])
				f = false;
		}
		if (!f){
			cout << s[k - 1];
		}else{
			char c = s[k];
			bool f = true;
			for (int i = k; i < s.size(); i++){
				if (s[i] != c)
					f = false;
			}
			if (!f){
				for (int i = k - 1; i < s.size(); i++){
					cout << s[i];
				}
			}else{
				for (int i = k - 1; i < (n - k + k - 1) / k + k; i++){
					cout << s[i];
				}
			}
		}
		cout << endl;
	}
}