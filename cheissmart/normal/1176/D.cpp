#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int N = 3e6 + 3.14;

int sd[N], m[N], nth[N];

int32_t main()
{
	IO_OP;

	for(int i=2;i<N;i++) {
		if(sd[i]) continue;
		sd[i] = i;
		for(int j=i*i;j<N;j+=i)
			if(sd[j] == 0)
				sd[j] = i;
	}
	int ct = 0;
	for(int i=2;i<N;i++)
		if(sd[i] == i)
			nth[i] = ++ct;
	vi a;
	int n;
	cin >> n;
	for(int i=0;i<n*2;i++) {
		int t;
		cin >> t;
		m[t]++;
	}
	for(int i=N-1;i>=0;i--) {
		while(m[i]) {
			if(sd[i] == i) {
				m[i]--;
				m[nth[i]]--;
				a.PB(nth[i]);
			} else {
				m[i]--;
				m[i/sd[i]]--;
				a.PB(i);
			}
		}	
	}
	for(int i:a)
		cout << i << " ";
}