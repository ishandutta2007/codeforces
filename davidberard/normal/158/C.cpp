#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<string> split(string s,string sep)
{
	int p = 0;
	int tp = 0;
	vector<string> ans;
	while((tp = s.find(sep, p)) != string::npos)
	{
		ans.push_back(s.substr(p, tp-p));
		p = tp+sep.size();
	}
	ans.push_back(s.substr(p, s.size()-p));
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	string line;
	getline(cin, line);
	vector<string> q;
	for(int i=0;i<N;++i) {
		getline(cin, line);
		vector<string> parts = split(line, " ");
		if(parts[0][0] == 'p') {
			for(auto& x : q) {
				cout << "/" << x;
			}
			cout << "/\n";
		}
		else {
			parts = split(parts[1], "/");
			if(parts.back().size() == 0 && parts.size() != 1) parts.pop_back();
			for(auto& x:parts) {
				if(x == "") q = vector<string>();
				else if(x == "..") q.pop_back();
				else q.push_back(x);
			}
		}
	}
	return 0;
}