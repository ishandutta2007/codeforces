#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 5;

int n, q;
ll fen[2][2][MAXN][MAXN];

void upd(int a, int b, ll x, bool ta, bool tb){
	if (a == 0 || b == 0)	return;
	for (; a < MAXN; a += a&-a)
		for (int bb = b; bb < MAXN; bb += bb&-bb)
			fen[ta][tb][a][bb] ^= x;
}

ll get(int a, int b){
	ll ret = 0;
	bool ta = a & 1, tb = b & 1;
	for (; a; a -= a&-a)
		for (int bb = b; bb; bb -= bb&-bb)
			ret ^= fen[ta][tb][a][bb];
	return ret;
}

int main(){
	scanf("%d %d", &n, &q);
	while (q--){
		int type;	scanf("%d", &type);
		if (type == 1){
			int a, b, c, d;	
			scanf("%d %d %d %d", &a, &b, &c, &d);
			ll ans = 0;
			ans ^= get(c, d);
			ans ^= get(a - 1, d);
			ans ^= get(c, b - 1);
			ans ^= get(a - 1, b - 1);
			printf("%I64d\n", ans);
		}
		else{
			int a, b, c, d;	ll x;	
			scanf("%d %d %d %d %I64d", &a, &b, &c, &d, &x);
			bool ta = a & 1, tb = b & 1;
			upd(a, b, x, ta, tb);
			if (((c - a + 1) & 1) == 0)	
				upd(c, b, x, ta, tb);
			if (((d - b + 1) & 1) == 0)
				upd(a, d, x, ta, tb);
			if (((c - a + 1) & 1) == 0 && ((d - b + 1) & 1) == 0)
				upd(c, d, x, ta, tb);

			if ((d - b + 1) & 1){
				upd(a, d, x, ta, !tb);
				if (((c - a + 1) & 1) == 0)
					upd(c, d, x, ta, !tb);
			}

			if ((c - a + 1) & 1){
				upd(c, b, x, !ta, tb);
				if (((d - b + 1) & 1) == 0)
					upd(c, d, x, !ta, tb);
			}

			if (((c - a + 1) & 1) && ((d - b + 1) & 1))
				upd(c, d, x, !ta, !tb);
		}
	}
	return 0;
}