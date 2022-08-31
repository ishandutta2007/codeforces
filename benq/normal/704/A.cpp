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
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int sofar[300001], app[300001];

int main() {
	int n,q, maxt = 0, cur = 0, ans = 0; scanf("%d%d",&n,&q);
	vector<pii> note;
	note.reserve(q);
	F0R(i,q) {
		int type,x;scanf("%d%d",&type,&x); // type = rand() % 3+1; x = rand() % 300000+1;
		if (type == 1) {
			app[x] ++;
			note.pb(mp(x,app[x]));
			ans++;
		} else if (type == 2) {
			ans -= (app[x]-sofar[x]);
			sofar[x] = app[x];
		} else {
			if (x>maxt) {
				FOR(j,maxt,x) {
					if (note[j].s>sofar[note[j].f]) {
						sofar[note[j].f] ++;
						ans--;
					}
				}
			}
			maxt=max(maxt,x);
		}
		printf("%d\n",ans);
	}
}