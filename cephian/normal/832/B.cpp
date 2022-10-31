#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

bool good[256]={};
string p,s;

int match_prefix() {
	int i = 0;
	for(; i < min(s.size(),p.size()); ++i) {
		if(p[i] == '*') return i;
		if(p[i] == '?' && !good[s[i]]) return i;
		if(p[i] != '?' && s[i] != p[i]) return i; 
	}
	return i;
}

int match_suffix() {
	int i = 0;
	for(; i < min(s.size(),p.size()); ++i) {
		if(p[p.size()-1-i] == '*') return i;
		if(p[p.size()-1-i] == '?' && !good[s[s.size()-1-i]]) return i;
		if(p[p.size()-1-i] != '?' && s[s.size()-1-i] != p[p.size()-1-i]) return i; 
	}
	return i;
}

int star() {
	for(int i = 0; i < p.size(); ++i)
		if(p[i] == '*')
			return i;
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> p;
	for(char c : p)
		good[c] = true;
	cin >> p;
	int loc = star();
	int n;
	cin >> n;
	while(n--) {
		cin >> s;
		if(loc == -1) {
			if(match_prefix() == s.size() && s.size() == p.size()) cout << "YES\n";
			else cout << "NO\n";
		} else {
			int a = match_prefix();
			int b = match_suffix();
			if(a != loc || b != p.size()-1-loc) cout << "NO\n";
			else {
				int i=a;
				for(; i <= (int)s.size()-1-b; ++i) {
					if(good[s[i]]) {
						cout << "NO\n";
						i=-1;
						break;
					}
				}
				if(i != -1) {
					if(a+b<=s.size())cout << "YES\n";
					else cout << "NO\n";
				} 
			}
		}
	}
}