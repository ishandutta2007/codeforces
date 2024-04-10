// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

const int nax = 1e6 + 11;
const int mod = 1e9 + 7;

stack <int> stos;

map <char, int> mapa;
int n;
char s[nax];
int ans;

void nie() {
	printf("Impossible\n");
	exit(0);
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	mapa['('] = 0;
	mapa[')'] = 1;
	mapa['<'] = 2;
	mapa['>'] = 3;
	mapa['{'] = 4;
	mapa['}'] = 5;
	mapa['['] = 6;
	mapa[']'] = 7;
	if(n & 1)
		nie();
	for(int i = 1; i <= n; ++i) {
		int c = mapa[s[i]];
		if((c & 1) && ss(stos) == 0) {
			nie();
		}
		if(c & 1) {
			if(stos.top() + 1 == c)
				;
			else
				ans += 1;
			stos.pop();
		}
		if(!(c & 1))
			stos.push(mapa[s[i]]);
	}
	if(stos.empty()) {
		printf("%d", ans);
	}
	else {
		nie();
	}
				
	
	return 0;
}