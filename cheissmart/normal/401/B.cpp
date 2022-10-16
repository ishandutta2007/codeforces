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

int m[4096];

int main()
{
	IO_OP;
	
	int x, k;
	cin >> x >> k;
	for(int i=0;i<k;i++) {
		int op;
		cin >> op;
		if(op == 1) {
			int a, b;
			cin >> a >> b;
			m[a] = m[b] = 1;
		} else {
			int a;
			cin >> a;
			m[a] = 1;
		}
	}
	vi v;
	for(int i=1;i<x;i++)
		if(m[i] == 0)
			v.PB(i);
	int mn = 0;
	bool f = true;
	for(int i=0;i<v.size();i++) {
		if(f) {
			mn++;
			f = 0;
		}
		else {
			if(v[i] == v[i-1] + 1)
				f = 1;
			else
				mn++;
		}
	}
	cout << mn << " " << v.size() << endl;
}