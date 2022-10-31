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

//range update, point query, 0-indexed
template <class T>
struct bit {
	vector<T> b;
	void init(int n){b.resize(n+1);}
	bit(){}
	bit(int n){init(n);}
	inline void ud(int i, T v) {
		for(; i<b.size(); i+=i&-i)
			b[i] += v;
	}
	//update [l,r] with value v
	inline void update(int l, int r, T v) {
		ud(l+1,v);
		if(r+2<b.size())ud(r+2,-v);
	}

	//get value at i
	inline int query(int i) const {
		T a = 0;
		for(++i; i; i^=i&-i)
			a += b[i];
		return a;
	}
};

const int N = 1e5+5;
ll t[N],v[N],exc[N]={},pfx[N];
bit<ll> full;

int main() {	
	fio;
	int n;
	cin >> n;
	full = bit<ll>(n+2);
	for(int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
		pfx[i] = t[i] + pfx[i-1];
	}
	for(int i = 1; i <= n; ++i) {
		int lo = i-1, hi = n+1;
		while(hi-lo-1) {
			int md = (lo+hi)/2;
			if(pfx[md]-pfx[i-1] >= v[i])
				hi = md;
			else lo = md;
		}
		// cout << i << " is exceptional on day " << hi << endl;
		if(hi != i) {
			// cout << "add to " << i << " . " << hi-1 << "\n";
			full.update(i,hi-1,1);
		}
		exc[hi] += v[i] - (pfx[hi-1]-pfx[i-1]);
	}
	for(int i = 1; i <= n; ++i) {
		// cout << exc[i] << "+" << full.query(i) << "*" << t[i] << " ";
		cout << exc[i] + full.query(i)*t[i] << " ";
	}
	cout << "\n";

}