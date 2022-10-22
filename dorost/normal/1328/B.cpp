#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int t; 
	cin >> t;
	while (t--){
		int n, k, an1, an2;
		cin >> n >> k;
		for (int i = 1; true; i++){
			if(k <= (i * (i + 1)) / 2){ 
			//	cout << (i * (i + 1)) / 2 << endl;
				an1 = i;
				an2 = k - ((i * (i + 1)) / 2 - i) - 1;
				break;
			}
		}
		string s;
		//cout << an1 << ' ' << an2 << endl; 
		for (int i = 0; i < n; i++)
			s += 'a';
		s[n - 1 - an1] = 'b';
		s[n - 1 - an2] = 'b';
		cout << s << endl;
	}
}