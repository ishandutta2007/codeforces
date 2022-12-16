#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void add_one(vector<short>& v, int M) {
	for(int i=v.size()-1;i>=0;--i) {
		++v[i];
		if(v[i] != M) return;
		v[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, K;
	cin >> N >> K;
	set<char> st;
	string s;
	cin >> s;
	for(auto& c : s) st.insert(c);
	vector<int> compress(256, -1);
	int M = 0;
	vector<char> decompress(256, -1);
	for(auto& c : st) {
		compress[c] = M;
		decompress[M++] = c;
	}
	if(K > N) {
		cout << s;
		for(int i=N;i<K;++i) {
			cout << decompress[0];
		}
		cout << endl;
		return 0;
	}
	vector<short> str;
	for(int i=0;i<K;++i) {
		str.push_back(compress[s[i]]);
	}
	add_one(str, M);
	for(auto& ii : str) {
		cout << decompress[ii];
	}
	cout << endl;
	return 0;
}