#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int xdir[8] = {1,1,0,-1,-1,-1,0,1};
int ydir[8] = {0,1,1,1,0,-1,-1,-1};

bool visit[301][301];
set<pair<pii,int>> cur, cur1;

void move(pair<pii,int> a, int t) {
	auto a1 = a;
	a.s--;
	if (a.s<0) a.s += 8;
	a1.s = (a1.s+1) % 8;
	F0R(i,t) {
		a.f.f += xdir[a.s];
		a.f.s += ydir[a.s];
		a1.f.f += xdir[a1.s];
		a1.f.s += ydir[a1.s];
		visit[a.f.f][a.f.s] = 1;
		visit[a1.f.f][a1.f.s] = 1;
	}
	cur1.insert(a);
	cur1.insert(a1);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n; 
	int x; cin >> x; 
	
	FOR(i,150,150+x) visit[150][i] = 1;
	cur.insert(mp(mp(150,150+x-1),2));
	
	F0R(i,n-1) {
		int t; cin >> t;
		cur1.clear();
		for (auto a: cur) move(a,t);
		cur = cur1;
	}
	int ans = 0;
	F0R(i,301) F0R(j,301) if (visit[i][j]) ans++;
	cout << ans;
}