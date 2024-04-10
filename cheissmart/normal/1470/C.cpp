#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b?"true":"false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(V<bool> v) {
	string res;
	for(int i=0;i<(int)v.size();i++) res+=char('0'+v[i]);
	return res;
}
template<class T1, class T2> string to_string(pair<T1, T2> p) {return "(" + to_string(p.F) + ", " + to_string(p.S) + ")";}
template<size_t S> string to_string(bitset<S> b) {
	string res;
	for(int i=0;i<S;i++) res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    for(auto x:v){
		if(!f) res+=' ';
		f=0; res+=to_string(x);
	}
    return res;
}

void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t)) cerr << ", ";
	DBG(t...);
}
#define debug(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

const int INF = 1e9 + 7;

int ask(int pos) {
	cout << "? " << pos + 1 << endl;
	int res;
	cin >> res;
	return res;
}

signed main()
{
	IO_OP;

	int n, k;
	cin >> n >> k;
	int b = sqrt(n) - 1;
	for(int i = 0; i < b; i++) ask(0);
	int x = 0, v = ask(x);
	while(v == k) {
		x = (x + b) % n;
		v = ask(x);
	}
	if(v < k) {
		while(ask((x + b) % n) < k) x = (x + b) % n;
		while(ask(x) < k) x = (x + 1) % n;
	} else {
		while(ask((x - b + n) % n) > k) x = (x - b + n) % n;
		while(ask(x) > k) x = (x + n - 1) % n;
	}
	cout << "! " << x + 1 << '\n';

}