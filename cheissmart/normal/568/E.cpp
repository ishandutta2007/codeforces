#include <bits/stdc++.h>
#define IO_OP ios::sync_with_stdio(0), cin.tie(0)
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

template<class T> string to_string(T t) {
	string s = "[";
	bool first = true;
	for(auto& i:t) {
		if(!first) s += ", ";
		first = false;
		s += to_string(i);
	}
	s += "]";
	return s;
}

void dbg() {
	cerr << "]" << endl;
}
template<class H, class ...T> void dbg(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t)) cerr << ", ";
	dbg(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", dbg(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int n; cin >> n;
	vi a(n); for(int& i:a) cin >> i;
	int m; cin >> m;
	vi b(m); for(int& i:b) cin >> i;
	sort(ALL(b), greater<int>());
	
	priority_queue<pi> pq;
	
	vi v;
	for(int i = 0; i < n; i++) {
		if(a[i] != -1) {
			if(v.empty() || a[i] > v.back())
				v.PB(a[i]);	
			else
				*lower_bound(ALL(v), a[i]) = a[i];
			int len = int(lower_bound(ALL(v), a[i]) - v.begin()) + 1;
			pq.push({len, i});
		} else {
			if(v.empty() || b[0] > v.back())
				v.PB(b[0]);	
			else
				*lower_bound(ALL(v), b[0]) = b[0];
			int k = SZ(v) - 1;
			for(int j = 1; j < SZ(b); j++) {
				while(k - 1 >= 0 && v[k - 1] >= b[j]) k--;
				assert(v[k] >= b[j]);
				v[k] = b[j];
			}
		}
		debug(v);
	}
	
	sort(ALL(b));
	vi unused;
	
	int pos = n, val = INF, len = SZ(v);
	while(len) {
		debug(pos, val, len);
		while(pq.size()) {
			if(pq.top().S >= pos || a[pq.top().S] >= val)
				pq.pop();
			else
				break;
		}
		if(pq.size() && pq.top().F == len) {
			pos = pq.top().S;
			val = a[pos];
			len--;
		} else {
			pos--;
			while(a[pos] != -1) pos--;
			while(b.back() >= val) {
				unused.PB(b.back());
				b.pop_back();	
			}
			val = a[pos] = b.back();
			b.pop_back();
			len--;
		}
	}
	
	unused.insert(unused.end(), ALL(b));
	
	for(int i = 0; i < n; i++) if(a[i] == -1) { 
		a[i] = unused.back();
		unused.pop_back();
	}
	
	for(int i = 0; i < n; i++)
		cout << a[i] << " \n"[i == n - 1];
	
}