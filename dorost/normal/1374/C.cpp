/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		string s;
		cin >> n >> s;
		int an = 0, all = 0;
		for (int i = 0; i < n; i++){
			if (s[i] == ')' && an == 0){
				all ++;
			}else{
				an += (s[i] == '(' ? 1 : -1);
			}
		}
		cout << all << ' ';
	}
}