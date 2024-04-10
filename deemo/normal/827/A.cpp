#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e6 + 10;

int k, n;
string t[MAXN], s;
pii vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	for (int i = 0; i < MAXN; i++) vec[i] = {-1, -1};
	for (int i = 0; i < k; i++){
		int c;	cin >> t[i] >> c;
		while (c--){
			int pos; cin >> pos, pos--;
			n = max(n, pos+(int)t[i].size());
			vec[pos] = max(vec[pos], {(int)t[i].size(), i});
		}
	}

	for (int i = 0; i < n; i++)
		if (vec[i].F == -1){
			if (s.size() < i+1) s += 'a';
		}
		else{
			int x = (int)s.size() - i;
			for (int j = x; j < t[vec[i].S].size(); j++)
				s += t[vec[i].S][j];
		}

	cout << s << "\n";
	return 0;
}