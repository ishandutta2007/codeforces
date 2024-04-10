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

int main() {	
	fio;
	string s;
	cin >> s;
	int n = s.size();
	s = s + s;
	int len = 1;
	int best = 1;
	for(int i = 1; i < s.size(); ++i) {
		if(s[i] != s[i-1])
			++len;
		else len = 1;
		best = max(best,len);
	}
	cout << min(best,n) << "\n";
}