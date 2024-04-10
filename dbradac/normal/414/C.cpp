#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = (1<<20) + 5, LOG = 24;

int n;
int p[MAX];
ll fen[MAX];
ll inv[2][LOG];
int prom[LOG];
vector <int> V;

vector <int> Rek(int lo, int hi, int st, int pot)
{
	if (lo + 1 == hi)
		return { p[lo] };

	vector <int> L = Rek(lo, (lo + hi) / 2, st, pot - 1);
	vector <int> R = Rek((lo + hi) / 2, hi, st, pot - 1);

	int sz = (hi - lo) / 2;
	vector <int> T;

	for (int ind1 = 0, ind2 = 0; ind1 < sz || ind2 < sz; ) {
		if (ind1 == sz)
			T.push_back(R[ind2++]);
		else if (ind2 == sz) {
			T.push_back(L[ind1++]);
			inv[st][pot] += ind2;
		}
		else if (L[ind1] <= R[ind2]) {
			T.push_back(L[ind1++]);
			inv[st][pot] += ind2;
		}
		else
			T.push_back(R[ind2++]);
	}

	return T;
}

int main()
{
	scanf("%d", &n);

	for (int i=0; i<(1<<n); i++) {
		scanf("%d", &p[i]);
		V.push_back(p[i]);
	}

	sort(V.begin(), V.end());

	for (int i=0; i<(1<<n); i++)
		p[i] = (int) (lower_bound(V.begin(), V.end(), p[i]) - V.begin());

	Rek(0, 1<<n, 0, n);

	for (int i=0; i<(1<<(n-1)); i++)
		swap(p[i], p[(1<<n)-i-1]);

	Rek(0, 1<<n, 1, n);

	int brq;
	scanf("%d", &brq);

	for (int i=0; i<brq; i++) {
		int tmp;

		scanf("%d", &tmp);
		prom[tmp] ^= 1;

		ll rje = 0;
		for (int j=n, st=0; j; j--) {
			st ^= prom[j];
			rje += inv[st][j];
		}

		printf("%lld\n", rje);
	}
	
	return 0;
}