#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	vector <int> v;
	for(int j = 1; j <= 9; j++){
		string t;
		for (int k = 0; k < 9; k++){
			t += '0' + j;
			v.push_back(stoi(t));
//			cout << t << endl;
		}
	}
	int t;
	cin >> t;
	while (t--){
		int k, ans = 0;
		cin >> k;
		for (int i = 0; i < v.size(); i++){
			if (k >= v[i])
				ans ++;
		}
		cout << ans << endl;
	}
}