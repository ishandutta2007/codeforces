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

map<string, int> m;
string mmm[3003],mmmmm[3003];
map<pair<pi, char>, int> mm;
int mmmm;
vector<string> ans;

string tos(int m)
{
	string ret;
	for(int i=0;i<4;i++)
		ret+=char('a'+m%26), m/=26;
	return ret;
}
string getname() {
	static int mmmmmm=0;
	while(m.count(tos(mmmmmm)))
		mmmmmm++;
	return tos(mmmmmm++);
}

void M(int x) {
	if (mmmmm[x].size())
		return;
	string s=mmm[x];
	if (isdigit(s[0])) {
		stringstream ss(s);
		int a,b;
		char op;
		ss >> a >> op >> b;
		M(a);
		M(b);
		if(x == m["res"])
			mmmmm[x] = "res";
		else
			mmmmm[x] = getname();
		ans.PB(mmmmm[x]+'='+mmmmm[a]+op+mmmmm[b]);
	} else {
		mmmmm[x] = s;
	}
}

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		string a = s.substr(0, s.find("="));
		string b = s.substr(s.find("=")+1);
		char op = 0;
		string ops = "$^#&";
		for(char c:ops)
			if(b.find(c) != string::npos)
				op = c;
		if(op) {
			string x = b.substr(0, b.find(op));
			string y = b.substr(b.find(op)+1);
			if(!m.count(x)) {
				mmm[mmmm] = x;
				m[x] = mmmm++;
			}
			if(!m.count(y)) {
				mmm[mmmm] = y;
				m[y] = mmmm++;
			}
			pair<pi, char> exp(pi(m[x],m[y]),op);
			if(!mm.count(exp)) {
				mmm[mmmm] = to_string(m[x])+op+to_string(m[y]);
				mm[exp] = mmmm++;
			}
			m[a] = mm[exp];
		} else {
			if(a == b) continue;
			if(!m.count(b)) {
				mmm[mmmm] = b;
				m[b] = mmmm++;
			}
			m[a] = m[b];
		}
	}
	if(!m.count("res")) {
		cout << 0 << endl;
		return 0;
	}
	M(m["res"]);
	if(ans.size() == 0) {
		if(mmmmm[m["res"]] == "res") cout <<"0\n";
		else cout << "1\nres=" << mmmmm[m["res"]] << endl;
		return 0; 
	}
	cout << ans.size() << endl;
	for(string s:ans)
		cout << s << endl;
}