#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

string inv(string s) {
	string res = "";
	for(char c:s) {
		if(c == '+')
			res += '*';
		else 
			res += '+';
	}
	return res;
}

vector<string> f(int k) {
	vector<string> res, t;
	if(k == 0) {
		res.PB("+");
		return res;
	}
	if(k == 1) {
		res.PB("++"), res.PB("+*");
		return res;
	}
	t = f(k - 1);
	for(int i=0;i<t.size();i++)
		res.PB(t[i]+t[i]);
	for(int i=0;i<t.size();i++)
		res.PB(t[i]+inv(t[i]));
	return res;
}

int main()
{
	IO_OP;
	
	int k;
	cin >> k;
	auto ans = f(k);
	for(auto s:ans)
		cout << s << endl;	
}