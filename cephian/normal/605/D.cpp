#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;

struct spell {
	int a=0,b,c=0,d=0,ind;
	bool operator<(const spell& s) const {
		if(a!=s.a) return a < s.a;
		if(b!=s.b) return b < s.b;
		if(c != s.c) return c < s.c;
		return d < s.d;
	}
};

ostream& operator<<(ostream& o, const spell& s) {
	o << "[" << s.a << "," << s.b << "|" << s.c << "," << s.d << "]";
	return o;
}

spell sps[N];
int dist[N],prv[N],n;

queue<int> Q({0});
vi V;

vector<pii> fen[N];
int fen_lo[N]={};
void get_list(int c, int d) {
	//search for c
	int lo = 0, hi = n+1;
	while(hi-lo>1) {
		int md = (lo+hi)/2;
		if(sps[md].a <= c) lo = md;
		else hi = md;
	}
	for(int i = lo; i; i^=i&-i) {
		lo = fen_lo[i], hi = fen[i].size();
		if(lo==hi || fen[i][lo].fi > d) continue;
		while(hi-lo>1) {
			int md = (lo+hi)/2;
			// cout << lo << " " << hi << endl;
			if(fen[i][md].fi <= d) lo = md;
			else hi = md;
		}
		
		for(int j = fen_lo[i]; j <= lo; ++j) {
			V.pb(fen[i][j].se);
		}
		fen_lo[i] = lo+1;
	}
}

ostream& operator<<(ostream& o, const pii& p) {
	o << "(" << p.fi << "," << p.se << ")";
	return o;
}

void build() {
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j<=n; j+=j&-j) {
			fen[j].emplace_back(sps[i].b,i);
		}
	}
	for(int i = 1; i <= n; ++i)
		sort(fen[i].begin(),fen[i].end());
	// for(int i = 1; i <= n; ++i) {
	// 	cout << i << " ->";
	// 	for(int j = 0; j < fen[i].size(); ++j)
	// 		cout << " " << fen[i][j];
	// 	cout << endl;
	// }
}

vi ans;

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) {
		spell &s = sps[i];
		s.ind = i;
		scanf("%d%d%d%d",&s.a,&s.b,&s.c,&s.d);
	}
	sort(sps+1,sps+n+1);
	// for(int i = 0; i <= n; ++i) {
	// 	cout << sps[i] << " " << endl;
	// }
	fill(dist+1,dist+n+1,1e7);
	build();
	while(Q.size()) {
		int v = Q.front();
		Q.pop();
		int d = dist[v];
		// printf("at %d with %d\n",v,d);
		V.clear();
		get_list(sps[v].c,sps[v].d);
		for(int w : V) {
			// printf("%d is in the list!\n",w);
			if(dist[w]>dist[v]+1) {
				Q.push(w);
				dist[w] = dist[v]+1;
				prv[w] = v;
			}
		}
	}
	int k=0;
	for(int i = 1; i <= n; ++i) {
		if(sps[i].ind==n) {
			k=i;
			break;
		}
	}
	if(dist[k] == 1e7) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n",dist[k]);
	int v = k;
	while(v != 0) {
		ans.pb(sps[v].ind);
		v = prv[v];
	}
	for(int i = ans.size()-1; i >= 0; --i)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}