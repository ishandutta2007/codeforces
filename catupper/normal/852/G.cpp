#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

typedef unsigned long long ull;
const ull M = 1000000009;

map<ull, int> T;
int N, Q;
char s[60];

int main() {
	scanf("%d %d", &N, &Q);

	rep(i, N) {
		scanf("%s", s);
		int l = strlen(s);
		ull t = 0;
		rep(j, l) t = t * M + s[j];
		T[t]++;
	}

	rep(i, Q) {
		scanf("%s", s);
		int l = strlen(s);
		vector<ull> vec;
		vec.pb(0);

		rep(j, l) {
			vector<ull> nv;
			if (s[j] != '?') {
				for (auto x : vec)	{
					nv.pb(x * M + s[j]);
				}	
			} else {
				for (auto c : {'a', 'b', 'c', 'd', 'e'}) {
					for (auto x : vec)	{
						nv.pb(x * M + c);
					}					
				}
				for (auto x : vec) {
					nv.pb(x);
				}
			}
			sort(ALL(nv));
			nv.erase(unique(ALL(nv)), nv.end());
			vec.swap(nv);
		}

		int ret = 0;
		for (auto x : vec) {
			if (T.count(x)) {
				ret += T[x];
			}
		}
		printf("%d\n", ret);
	}

	return 0;
}