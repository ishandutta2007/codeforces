#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

string s;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	bool f=0;
	for(int i = 0; i <= int(s.size())-26; ++i) {
		set<int> c;
		int nq = 0;
		for(int j = 0; j < 26; ++j) {
			if(s[i+j]=='?') ++nq;
			else c.insert(s[i+j]);
		}
		if(c.size()+nq == 26) {
			f=1;
			for(int j = 0; j < 26; ++j) {
				if(s[i+j]!='?') continue;
				for(char w = 'A'; ; ++w) {
					if(c.count(w)) continue;
					c.insert(w);
					s[i+j] = w;
					break;
				}
			}
			break;
		}
	}
	if(!f) cout << "-1\n";
	else {
		for(int i = 0; i < s.size(); ++i)
			if(s[i] == '?') s[i] = 'A';
		cout << s << "\n";
	}
}