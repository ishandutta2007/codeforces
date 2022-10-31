#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const ll M = 1e9+7;
int a,b;

struct state {
	int a1[2],a2[2];
	bool boat = 0;
	state(int a, int b, int c, int d, bool boat):boat(boat) {
		a1[0] = a;
		a2[0] = b;
		a1[1] = c;
		a2[1] = d;
	}
	bool operator<(const state& s) const {
		if(a1[0] != s.a1[0]) return a1[0] < s.a1[0];
		if(a2[0] != s.a2[0]) return a2[0] < s.a2[0];
		if(a1[1] != s.a1[1]) return a1[1] < s.a1[1];
		if(a2[1] != s.a2[1]) return a2[1] < s.a2[1];
		return boat < s.boat;
	}
};

ostream& operator<<(ostream& o, const state& s) {
	o << "(" << s.a1[0] << "," << s.a2[0] << ";" << s.a1[1] << "," << s.a2[1] << "|" << s.boat << ")";
	return o; 
}

map<state,int> dist;
map<state,ll> ways;
queue<state> Q;

void try_add(const state& s, ll w, ll d) {
	if(dist.count(s)) {
		if(dist[s] < d) return;
		ways[s] = (ways[s]+w)%M;
	} else {
		dist[s] = d;
		ways[s] = w;
		Q.push(s);
	}
}

ll fct[100];

ll pw(ll a, ll b) {
	if(!b) return 1;
	if(b&1) return a*pw(a,b-1)%M;
	ll t = pw(a,b/2);
	return t*t%M;
}

ll choose(ll a, ll b) {
	return (fct[a]*pw(fct[b]*fct[a-b]%M,M-2))%M;
}

int main() {
	fct[0] = 1;
	for(int i = 1; i < 100; ++i) {
		fct[i] = (fct[i-1]*i)%M;
	}
	int n,k;
	scanf("%d%d",&n,&k);
	k /= 50;
	int a1=0,a2=0;
	for(int i = 0; i < n; ++i) {
		int q;
		scanf("%d",&q);
		if(q == 50) ++a1;
		else ++a2;
	}
	state s(a1,a2,0,0,0);
	state e(0,0,a1,a2,1);
	Q.push(s);
	dist[s] = 0;
	ways[s] = 1;
	while(Q.size()) {
		state s = Q.front();
		Q.pop();
		int d = dist[s];
		ll w = ways[s];
		for(int m2 = 0; m2*2 <= k && m2 <= s.a2[s.boat]; ++m2) {
			for(int m1 = 0; m1 <= min(k-m2*2,s.a1[s.boat]); ++m1) {
				if(m1+m2 == 0) continue;
				state s2(s.a1[0],s.a2[0],s.a1[1],s.a2[1],s.boat);
				s2.a1[s2.boat] -= m1;
				s2.a2[s2.boat] -= m2;
				s2.boat ^= 1;
				s2.a1[s2.boat] += m1;
				s2.a2[s2.boat] += m2;
				try_add(s2,w*choose(s.a2[s.boat],m2)%M*choose(s.a1[s.boat],m1)%M,d+1);
			}
		}
	}
	if(!dist.count(e)) printf("-1\n0\n");
	else printf("%d\n%I64d\n",dist[e],ways[e]);


	return 0;
}