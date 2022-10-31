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

string t;
string s[105];

bool st[1000]={},ed[1000]={};

int main() {	
	fio;
	cin >> t;
	int n;
	cin >> n;
	bool ok = false;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		if(s[i] == t) ok = true;
		st[s[i][0]] = true;
		ed[s[i][1]] = true;
	}
	if(ed[t[0]] && st[t[1]])
		ok = true;
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}