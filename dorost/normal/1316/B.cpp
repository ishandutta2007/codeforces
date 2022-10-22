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
		int n;
		string s;
		cin >> n >> s;
		string min = s + s + s + s + s;
		int an = n;
		for (int i = 0; i < n; i++){
			string t;
			for (int j = i; j < n; j++){
				t += s[j];
			}
			if ((n + i) % 2){
				for (int j = i - 1; j >= 0; j--){
					t += s[j];
				}
			}else{
				for (int j = 0; j < i; j++){
					t += s[j]; 
				}
			}
			if (t < min){
				min = t;
				an = i + 1;
//				cerr << an << ' ' << min << endl;
			}
		}
		cout << min << endl << an << endl;
	}
}