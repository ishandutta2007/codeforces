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

set<string> s;

int main() {	
	int n;
	cin >> n;
	while(n--) {
		string t;
		cin >> t;
		if(s.count(t)) cout << "YES\n";
		else {
			s.insert(t);
			cout << "NO\n";
		}
	}
}