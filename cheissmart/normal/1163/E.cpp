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

int s[200005],b[18],c[18];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> s[i];
	sort(s,s+n);
	int mx=-1;
	for (int i=0;i<n;i++) {
		int t = s[i];
		if (t == 0)
			continue;
		for (int j = 17; j >= 0; --j)
			if (t>>j&1)
				t ^= b[j];
		if (t != 0) {
			b[__lg(t)] = t;
			c[__lg(t)] = s[i];
			int x = __lg(s[i]);
			//cerr << "x " << x << endl;
			bool ok = true;
			for (int j = x; j >= 0; --j) {
				//cerr << j << ' ' << b[j] << " ok " << ok << endl;
				ok = ok && b[j]>0;
			}
			if (ok) {
				//cerr << "ok\n";
				mx=x;
			}
		}
		/*
		cerr << i << ' ' << s[i] << ' ' << mx << endl;
		for (int j = 0; j < 18; ++j)
			cerr << b[j] << ' ';
		cerr << endl;*/
	}
	vi v({0});
	cout << mx + 1 << endl;
	for(int i=0;i<=mx;i++) {
		for(int j=v.size()-1;j>=0;j--)
			v.PB(v[j]^c[i]);
	}
	for(int e:v)
		cout << e << " ";
}