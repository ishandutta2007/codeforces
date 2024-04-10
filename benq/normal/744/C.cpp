#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define mp make_pair
#define pb push_back
#define f first
#define s second

map<int,int> rec[1<<16];
pii rb[1<<16];
pair<int,pii> cards[16];
int n; 

void dp(int cur) {
	if (rec[cur].size()) return;
	F0R(i,n) if (cur & (1<<i)) {
		int temp = cur^(1<<i); dp(temp);
		rb[cur] = rb[temp];
		if (cards[i].f == 0) rb[cur].f ++;
		else rb[cur].s ++;
		int c1 = max(0,cards[i].s.f-rb[temp].f), c2 = max(0,cards[i].s.s-rb[temp].s);
		for (auto a: rec[temp]) {
			if (rec[cur].find(a.f+c1)  == rec[cur].end()) rec[cur][a.f+c1] = a.s+c2;
			else rec[cur][a.f+c1] = min(rec[cur][a.f+c1],a.s+c2);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
		char c; cin >> c;
		if (c == 'B') cards[i].f = 1;
		cin >> cards[i].s.f >> cards[i].s.s;
	}
	rec[0][0] = 0;
	dp((1<<n)-1);
	int ans = 1000000007;
	for (pii x: rec[(1<<n)-1]) ans = min(ans,max(x.f,x.s));
	cout << (ans+n);
}