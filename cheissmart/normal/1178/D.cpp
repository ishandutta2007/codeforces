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

int np[1024];

int main()
{
	IO_OP;
	
	for(int i=2;i<1024;i++) {
		if(np[i]) continue;
		for(int j=i*i;j<1024;j+=i)
			np[j] = 1;
	}
	vector<pi> v;
	int n, e;
	cin >> n;
	for(int i=1;i<n;i++)
		v.EB(i, i+1);
	v.EB(n, 1);
	int t = 1;
	while(np[v.size()]) {
		v.EB(t, n-t);
		t++;
	}
	cout << v.size() << endl;
	for(pi e:v)
		cout << e.F << " " << e.S << endl;
	
}