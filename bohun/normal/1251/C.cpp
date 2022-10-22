#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;

using namespace std;

const int N = 3e5 + 111;

int T, n;
char s[N];
deque <int> a[2];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		FOR(i, n) {
			int c = s[i] - '0';
			a[c % 2].pb(c);
		}
		FOR(i, n) {
			if(ss(a[0]) > 0 && (ss(a[1]) == 0 || a[0].front() < a[1].front())) {
				printf("%d", a[0].front());
				a[0].pop_front();
			}
			else {
				printf("%d", a[1].front());
				a[1].pop_front();
			}
		}
		printf("\n");
	}
		
	
	
	return 0;
}