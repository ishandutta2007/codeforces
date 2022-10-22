#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;

const int nax = 1000005;

int n;
int a[nax];
int ok[nax];
vector <int> res;
int ile = 0;
int last = 0;
int L[nax];
multiset <int> s;

int main() {
	scanf("%d", &n);
	FOR(i, n) scanf("%d", a + i);
	FOR(i, n) {
		if(a[i] > 0) {
			if(ss(s) > 0 && *s.begin() < L[a[i]]) {
				printf("-1");
				return 0;
			}
			if(ok[a[i]] == 1) {
				printf("-1");
				return 0;
			}
			ok[a[i]] = 1;
			ile += 1;
			s.insert(i);
			L[a[i]] = i;
		}
		else {
			int b = -a[i];
			if(ok[b] == 0) {
				printf("-1");
				return 0;
			}
			ok[b] = 0;
			s.erase(L[b]);
			ile -= 1;
		}
		if(ile == 0) {
			res.pb(i - last);
			last = i;
		}
	}
	if(ile > 0)
		printf("-1");
	else {
		printf("%d\n", ss(res));
		for(auto it : res)
			printf("%d ", it);
	}
			
		
	
	
	
	return 0;
}