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

struct str_hash {
	vector<ll> h,b;
	constexpr static ll B = 37;
	str_hash(const string& s):h(s.size()+1),b(s.size()+1,1) {
		for(int i = 0; i < s.size(); ++i) {
			h[i+1] = h[i]*B+s[i]-'a'+1;
			b[i+1] = b[i]*B;
		}
	}

	//inclusive range hash
	ll hash(int i, int j) {
		return h[j+1] - h[i]*b[j-i+1];
	}
};


int pal[5005][5005], f[5005];
string s;

int main() {
	fio;	
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; ++i) {
		pal[i][i] = 1;
		++f[1];
	}
	string t = s;
	reverse(t.begin(),t.end());
	str_hash S(s);
	str_hash T(t);
	for(int l = 2; l <= s.size(); ++l) {
		for(int i = 0; i+l <= s.size(); ++i) {
			int j = i+l-1;
			int hl = l/2;
			if(S.hash(i,j) == T.hash(n-1-j,n-1-i)) {
				pal[i][j] = 1 + min(pal[i][i+hl-1],pal[j-hl+1][j]);
			} else
				pal[i][j] = 0;
			++f[pal[i][j]];
		}
	}
	for(int i = n; i >= 1; --i) {
		f[i] += f[i+1];
	}
	for(int i = 1; i <= n; ++i)
		cout << f[i] << " ";
	cout << "\n";
}