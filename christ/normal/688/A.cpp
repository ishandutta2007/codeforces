#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+4, MOD = 1e9+7, BASE = 31;
char s[105];
int main () { 
	int n,d;
	scanf ("%d %d",&n,&d); int cur = 0, best = 0;
	for (int i = 1; i <= d; i++) {
		scanf ("%s",s);
		bool lose = 1;
		for (int j = 0; j< n; j++) lose &= s[j] == '1';
		if (lose) {
			best = max(best,cur);
			cur = 0;
		} else ++cur;
	}
	best = max(best,cur);
	printf ("%d\n",best);
	return 0;
}