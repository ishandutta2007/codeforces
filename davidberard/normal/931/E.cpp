#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct node {
	unordered_set<int> paths;
	int count;
	char c;
	node() : count(0) {}
	node(char cc) : c(cc), count(0) {}
};

struct dag{
	vector<vector<node>> levels;
	int count;
	dag(int s) {
		count = 0;
		vector<node> base(26);
		for(int i=0;i<26;++i)
			base[i] = node('a'+i);
		levels = vector<vector<node>>(s, base);
	}
	void add(string s) {
		for(int i=0;i<s.length();++i) {
			int vv = s[i]-'a';
			levels[i][vv].count ++;
		}
		++count;
	}
	int best() {
		int bst = 0;
		for(int i=0;i<levels.size();++i) {
			int t = 0;
			for(int j=0;j<26;++j) {
				if(levels[i][j].count == 1) {
					//opts.insert(*(levels[i][j].paths.begin())); 
					++t;
					//cerr << *(levels[i][j].paths.begin()) <<  " level " << i <<endl;
				}
			}
			bst = max(bst, t);
		}
		//cerr << endl;
		return bst;
		//return false;
	}
};

/*
struct trie {
	vector<node> nodes;
	trie() {
		nodes.push_back(node('^'));
	}
	int addChild(int n, char c) {
		nodes[n].isEnd = false;
		if(nodes[n].children.count(c) == 0) {
			nodes[n].children[c] = nodes.size();
			nodes.push_back(node(c, n));
			nodes[nodes.size()-1].count++;
			return nodes.size()-1;
		} else {
			int ch= nodes[n].children[c];
			nodes[ch].count++;
			return ch;
		}
	}
	bool add(string s, int rot) {
		int p = 0;
		for(int i=0;i<s.length();++i) {
			bool 
			int p = addChild(p, s[(i+rot)%s.length()]);
		}
	}
	bool add(string s) {
		add(s, 0);
	}
};
*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	string s;
	cin >> s;
	vector<dag> dgs = vector<dag>(26, dag(s.length()));
	for(int i=0;i<s.length();++i) {
		int vv = s[i]-'a';
		string ss = s.substr(i+1, s.size()-i-1) + s.substr(0, i);
		//cerr << s[i] << ss << endl;
		dgs[vv].add(ss);
	}

	ld ans = 0;
	for(int i=0;i<26;++i) {
		//cerr << i << "::" << endl;
		ans += dgs[i].best();
	}
	ans /= s.length();
	cout << fixed << setprecision(10) << ans << endl;
	
	return 0;
}