#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int ctr = 1;

vector<pii> E;
vector<int> lens[200005];

pii build(int in, int out) {
	int v = ctr++;
	if(out == 1) {
		if(in == 0) return pii(v,0);
		pii p = build(in-1,out);
		E.emplace_back(v,p.fi);
		lens[ctr].pb(p.se+1);
		return pii(v,p.se+1);
	} else {
		int mx = 0;
		--in;
		int branch = out;
		vi si(branch,in/branch), so(branch,out/branch);
		in -= in/branch*branch;
		for(int i = 0; in ; ++i) {
			if(in) ++si[i],--in;
		}
		for(int i = 0; i < branch; ++i) {
			pii p = build(si[i],so[i]);
			E.emplace_back(v,p.fi);
			mx = max(mx,p.se+1);
			lens[v].pb(p.se+1);
		}
		return pii(v,mx);
	}
}

int main() {
	int n,k;
	scanf("%d %d",&n,&k);
	build(n-k,k);
	sort(lens[1].rbegin(),lens[1].rend());

	printf("%d\n",lens[1][0]+lens[1][1]);
	for(pii &p : E) {
		printf("%d %d\n",p.fi,p.se);
	}
}