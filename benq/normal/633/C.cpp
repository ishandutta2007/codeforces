#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int tested[100000],n,m, ans[100000];
string ori, words[100000], code[100000];
vi k;
bool done = 0;

void finish() {
	int begin = 0;
	while (begin<n) {
		cout << words[ans[begin]] << " ";
		begin += words[ans[begin]].length();
	}
}

void addon (int pos) {
	if (done) return;
	if (pos == n) finish();
	F0R(i,m) {
		if (code[i].length()+pos <= n && !tested[code[i].length()+pos] && ori.substr(pos,code[i].length()) == code[i]) {
			ans[pos] = i;
			addon(pos+code[i].length());
		}
	}
	tested[pos] = 1;
}

int main() {
	cin >> n >> ori >> m;
	F0R(i,m) {
		cin >> words[i];
		code[i] = words[i];
		reverse(code[i].b(), code[i].e());
		F0R(j,code[i].length()) {
			if (int(code[i][j]-'a') < 0) {
				code[i][j] = char(int(code[i][j]-'A'+'a'));
			}
		}
	}
	// F0R(i,m) cout << code[i] << " ";
	addon(0);
	return 0;
}