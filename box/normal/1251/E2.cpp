// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)

pair<int,int> xd[200005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;cin>>t;
	while(t--) {
		int n;cin>>n;
		rep(i, n)
			cin>>xd[i].first>>xd[i].second;
		sort(xd, xd+n);
		xd[n].first = 1e9; int c=0;
		priority_queue<int> z;
		rep(i, n) {
			while(xd[c].first == i) z.push(xd[c++].second);
			if(z.size()) z.pop();
		}
		long long sm=0;
		while(z.size()) sm+=z.top(),z.pop();
		cout<<sm<<endl;
	}
}