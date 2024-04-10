#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		int a[26] = {};
		for (int i = 0; i < n; i++){
			a[s[i] - 'a'] ++;
			a[t[i] - 'a'] ++;
		}
		bool f = true;
		for (int i = 0; i < 26; i++){
			if (a[i] % 2)
				f =  false;
		}
		if (!f){
			cout << "No\n";
			continue;
		}
		cout << "Yes\n" << 2 * n << endl;
		for (int i = 0; i < n; i++){
			if (s[i] == t[i]){
				cout << i + 1 << ' ' << i + 1 << endl << i + 1 << ' ' << i + 1 << endl;
			}else{
				for (int j = i + 1; j < n; j++){
					if (s[j] == s[i]){
						swap(s[j], t[i]);
						cout << j + 1 << ' ' << i + 1 << endl << i + 1 << ' ' << i + 1 << endl;
						break;
					}else if(s[i] == t[j]){
						swap(s[j], t[j]);
						swap(s[j], t[i]);
						cout << j + 1 << ' ' << j + 1 << endl << j + 1 << ' ' << i + 1 << endl; 
						break;
					}
				}
			}
		}
	}
}