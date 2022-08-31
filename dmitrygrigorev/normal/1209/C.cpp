#include <bits/stdc++.h>
#define ll long long
 
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int first = 0; first < 10; first++){
		string a = "", b = "";
		for (int i=0; i < n; ++i){
			if ((s[i] - '0') < first){
				a += s[i];
			}
			else if ((s[i] - '0') > first){
				b += s[i];
			}
			else{
				if (!b.size() || b.back() == s[i]) b += s[i];
				else a += s[i];
			}
		}
		a += b;
		bool good = true;
		for (int i=1; i < n; ++i) if (a[i] < a[i-1]) good = false;
		if (good){
			a = "", b = "";
			for (int i=0; i < n; ++i){
				if ((s[i] - '0') < first){
					a += s[i];
					cout << 1;
				}
				else if ((s[i] - '0') > first){
					b += s[i];
					cout << 2;
				}
				else{
					if (!b.size() || b.back() == s[i]){
						b += s[i];
						cout << 2;
					}
					else{
						a += s[i];
						cout << 1;
					}
				}
			}
			cout << endl;
			return;
		}
	}
	cout << "-\n";
}

int main()
{
	#ifdef LOCAL
	    freopen("H_input.txt", "r", stdin);
	    //freopen("B_output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	for (int i=0; i < t; ++i) solve();

}