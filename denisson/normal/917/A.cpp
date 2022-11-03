#include <bits/stdc++.h>
				   
using namespace std;
		   
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

string s;

int main(){
//	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++){
		int bal = 0;
		int cnt = 0;
		for (int j = i; j < s.size(); j++){
			if (s[j] == '('){
				bal++;
			} else if (s[j] == ')'){
				bal--;
				if (bal < 0){
					if (cnt > 0){
						cnt--;
						bal += 2;
					} else break;
				}
			} else {
				cnt++;
				bal--;
				if (bal < 0){
					if (cnt > 0){
						cnt--;
						bal += 2;
					} else break;
				}
			}
			if (bal == 0) ans++;
			//cout << j << ' ' << bal << endl;
		}
		//exit(0);
	}	
	cout << ans;
}