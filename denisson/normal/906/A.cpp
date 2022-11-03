#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
#define sz(a) (int)a.size()

int n;
int was[26];
int gg[26];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int ans = 0;
	int can = -1;
	set<char> se;
	for (int i = 0; i < n; i++){
		//cout << "===" << can << endl;
		char c;
		string s;
		cin >> c >> s;
		if (c == '!'){
			se.clear();
			if (can != -1) ans++;
			for (char cc : s) se.insert(cc);
			for (char cc : se) was[cc - 'a']++;

		} else if (c == '.'){
			for (char cc : s) gg[cc - 'a'] = 1;
		} else {
			if (i + 1 != n){
				if (can != -1) ans++;
				gg[s[0] - 'a'] = 1;
			}
		}

		if (can == -1){
			int ma = -1, last = -1, cnt = 0;
			for (int j = 0; j < 26; j++) if (gg[j] == 0){
				if (was[j] > ma){
					ma = was[j];
					last = j;
					cnt = 1;
				} else if (was[j] == ma){
					cnt++;
				}
			}

			//cout << cnt << ' ' << last << ' ' << ma << endl;

			if (cnt == 1){
				can = last;
			}
		}
	}
	cout << ans;
}