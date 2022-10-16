#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 0x3f3f3f3f, N = 2e5 + 7;

int l[N], r[N];
int bit[N];

void add(int pos, int val) {
	for(;pos < N;pos+=pos&-pos)
		bit[pos] = min(bit[pos], val);
}

int qry(int pos) {
	int mn = INF;
	for(;pos;pos-=pos&-pos)
		mn = min(mn, bit[pos]);
	return mn;
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	V<array<int, 3>> v;
	for(int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		v.PB({l[i], r[i], i});
	}
	sort(ALL(v));
	priority_queue<pi, V<pi>, greater<pi>> pq;
	vi p;
	for(int i = 1, j = 0; i <= n; i++) {
		while(j < v.size() && v[j][0] <= i)  {
			pq.push({v[j][1], v[j][2]});
			j++;
		}
		assert(pq.size()); // there exists at least one valid ordering 
		pi pp = pq.top(); pq.pop();
		p.PB(pp.S);
  	}
  	auto print = [&]() {
  		vi ans(n);
  		for(int i=0;i<n;i++) ans[p[i]] = i + 1;
  		for(int i:ans) cout << i << " ";
  		cout << endl;
  	};

  	memset(bit, 0x3f, sizeof bit);
  	for(int i = n - 1; i >= 0; i--) {
  		int qq = qry(i + 1);
  		if(qq <= r[p[i]]) {
  			cout << "NO" << endl;
  			print();
  			swap(p[i], p[qq - 1]);
  			print();
  			return 0;
  		}
  		add(l[p[i]], i + 1);
  	}
  	cout << "YES" << endl;
  	print();
}