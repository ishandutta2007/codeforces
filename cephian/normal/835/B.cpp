#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int f[10],ds = 0, k;
string s;
char first;

int main() {	
	fio;
	cin >> k >> s;
	bool fs = false;
	for(char c : s) {
		++f[c-'0'];
		ds += c-'0';
		fs = true;
	}
	int ctr = 0, ans = 0;
	while(ds < k) {
		while(f[ctr] == 0) {
			++ctr;
		}
		--f[ctr];
		ds += 9-ctr;
		++ans;
	}
	cout << ans << "\n";
}