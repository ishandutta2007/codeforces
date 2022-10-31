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

map<string,string> fwd;
map<string,string> bck;

set<string> small;

string trace(string s) {
	if(fwd.count(s) == 0) return s;
	return trace(fwd[s]);
}

int main() {	
	int n,x=0;
	cin >> n;
	while(n--) {
		string a,b;
		cin >> a >> b;
		fwd[a] = b;
		bck[b] = a;
	}
	for(auto p : fwd) {
		if(bck.count(p.first) == 0)
			small.insert(p.first);
	}
	cout << small.size() << "\n";
	for(string s : small) {
		cout << s << " " << trace(s) << "\n";
	}
}