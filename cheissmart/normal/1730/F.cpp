#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
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


string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 5005;

int pos[N], a[N];

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
signed main()
{
	IO_OP;

	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		// a[i] = i + 1;
		pos[a[i]] = i;
	}
	int inv = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
			inv += pos[i] < pos[j];

	unordered_map<vi, int, VectorHasher> dp;
	dp[{}] = 0;
	for(int i = 1; i <= n; i++) {
		unordered_map<vi, int, VectorHasher> ndp;
		auto upd = [&] (vi v, int nw, int val) {
			if(SZ(v) && nw - v[0] > k) return false;
			int mx = i + SZ(v);
			for(int j = nw + 1; j <= mx; j++)
				val += pos[nw] < pos[j];
			for(int e:v) val -= pos[nw] < pos[e];
			// debug(i, v, nw, val);
			if(ndp.count(v)) ndp[v] = min(ndp[v], val);
			else ndp[v] = val;
			return true;
		};
		for(auto&[_he, be]:dp) {
			auto he = _he;
			int mx = i - 1 + SZ(he);
			// debug(i - 1, he, be);
			for(int j = 0; j < SZ(he); j++) {
				vi tt = he; tt.erase(tt.begin() + j);
				if(!upd(tt, he[j], be))
					break;
			}
			for(int nw = mx + 1; nw <= mx + k + 1 && nw <= n; nw++) {
				if(!upd(he, nw, be))
					break;
				he.PB(nw);
			}
		}
		swap(dp, ndp);
		debug(i, SZ(dp));
	}

	int ans = INF;
	for(auto&[he, be]:dp)
		ans = min(ans, be);
	cout << ans + inv << '\n';
}