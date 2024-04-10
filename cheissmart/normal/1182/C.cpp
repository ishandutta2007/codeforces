#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

string v = "aeiou";

vector<string> a[100005][5];

int main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		int k=0, l;
		for(char c:s)
			if(v.find(c) != string::npos) {
				k++;
				l = v.find(c);
			}
		a[k][l].PB(s);
	}
	int x = 0, y = 0;
	for(int i=0;i<100005;i++) {
		int t = 0;
		for(int j=0;j<5;j++) {
			y += a[i][j].size() / 2;
			t += a[i][j].size();
		}
		x += t / 2;
	}
	int ans = min(x/2, y);
	cout << ans << endl;
	vector<pair<string, string>> f, s;
	for(int i=0;i<100005;i++) {
		vector<string> tmp;
		for(int j=0;j<5;j++) {
			while(a[i][j].size() >= 2 && s.size() < ans) {
				string s1, s2;
				s1 = a[i][j].back();
				a[i][j].pop_back();
				s2 = a[i][j].back();
				a[i][j].pop_back();
				s.EB(s1, s2);
			}
			while(a[i][j].size()) {
				tmp.PB(a[i][j].back());
				a[i][j].pop_back();
			}
		}
		while(tmp.size() >= 2 && f.size() < ans) {
			string s1, s2;
			s1 = tmp.back();
			tmp.pop_back();
			s2 = tmp.back();
			tmp.pop_back();
			f.EB(s1, s2);
		}
	}
	for(int i=0;i<ans;i++) {
		cout << f[i].F << " " << s[i].F << endl;
		cout << f[i].S << " " << s[i].S << endl;
	}

}