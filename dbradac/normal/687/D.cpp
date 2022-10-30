#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1005;

pair <P, P> e[MAX*MAX];
vector <int> Skup[MAX];
int boja[MAX];
int poz[MAX];

void Spoji(int a, int b)
{
	int cola = boja[a];
	int colb = boja[b];

	a = poz[a];
	b = poz[b];
	
	assert(a != b);

	if (Skup[a].size() < Skup[b].size())
		swap(a, b); //a veci

	for (auto it : Skup[b]) {
		Skup[a].push_back(it);
		poz[it] = a;
		boja[it] = cola ^ colb ^ boja[it] ^ 1;
	}
}

int main()
{
	int n, q, m;

	scanf("%d%d%d", &n, &m, &q);

	for (int i=0; i<m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c); a--; b--;
		e[i] = make_pair(P(c, i), P(a, b));
	}

	sort(e, e + m, greater<pair<P, P> >());

	for (int i=0; i<q; i++) {
		int l, r;
		scanf("%d%d", &l, &r); l--; r--;

		for (int j=0; j<n; j++) {
			Skup[j].clear();
			Skup[j].push_back(j);
			boja[j] = 0;
			poz[j] = j;
		}

		int rje = -1;
		for (int j=0; j<m; j++) {
			if (e[j].X.Y < l || e[j].X.Y > r)
				continue;

			if (poz[e[j].Y.X] == poz[e[j].Y.Y]) {
				if (boja[e[j].Y.X] == boja[e[j].Y.Y]) {
					rje = e[j].X.X;
					break;
				}
			}
			else
				Spoji(e[j].Y.X, e[j].Y.Y);
		}

		printf("%d\n", rje);
	}

	return 0;
}