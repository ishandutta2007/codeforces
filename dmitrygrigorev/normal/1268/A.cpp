#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	bool can = true;
	for (int i=k; i < n; ++i) {
		if (s[i] == s[i%k]) continue;
		if (s[i] > s[i%k]) {
			can = false;
			break;
		}
		for (int j=i; j < n; ++j) {
			s[j] = s[j%k];
		}
		break;
	}

	if (can) {
		cout << s.size() << endl;
		cout << s << endl;
		return 0;
	}

	bool nine = true;
	for (int i=0; i < k; ++i) {
		if (s[i] != '9') {
			nine = false;
		}
	}
	if (!nine) {
		s[k-1]++;
		for (int i=k-1; i >= 0; i--) {
			int T = 0;
			if (s[i] - '0' >= 10) {
				T++;
				s[i] -= 10;
			}
			if (i > 0) s[i-1] += T;
		}
		for (int i=k; i < n; ++i) {
			s[i] = s[i%k];
		}
		cout << s.size() << endl;
		cout << s;
		return 0;
	}
	else{
		cout << s.size()+1 << endl;
		for (int i=0; i < n+1; ++i) {
			if (i % k == 0) cout << 1;
			else cout << 0;
		} 
	}


}