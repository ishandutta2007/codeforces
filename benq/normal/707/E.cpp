#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second

vector<pair<pii,ll>> gar[2001];
ll cum[2001][2001];
int n,m,k,q;
bool state[2001], cha[2001];

ll sum(int x, int y) {
	ll s = 0;
	for (;x>0; x -= (x&-x)) 
		for (int y1 = y; y1>0;y1 -= (y1&-y1)) 
			s += cum[x][y1];
	return s;
}

void upd(int x, int y, ll val) {
	for (;x<= n; x += (x&-x)) 
		for (int y1 = y; y1 <= m; y1 += (y1&-y1)) 
			cum[x][y1] += val;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k;
	FOR(i,1,k+1) {
		int len; cin >> len;
		int x,y; ll w; 
		F0R(j,len) {
			cin >> x >> y >> w;
			gar[i].pb(mp(mp(x,y),w));
		}
		state[i] = cha[i] = 1;
	}
	
	cin >> q;
	F0R(i,q) {
		string s; cin >> s;
		if (s[0] == 'S') {
			int g; cin >> g;
			state[g] ^= 1;
			cha[g] ^= 1;
		} else {
			int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
			FOR(i,1,k+1) if (cha[i]) {
				if (state[i]) for (auto j: gar[i]) upd(j.f.f,j.f.s,j.s);
				else for (auto j: gar[i]) upd(j.f.f,j.f.s,-j.s);
				cha[i] = 0;
			}
			cout << sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1) << "\n";
		}
	}
}