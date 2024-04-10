#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<19;

set <P> S;
int mak[MAX];
vector <int> V[MAX];
int br=0;

int main()
{
	int n, q;

	scanf("%d%d", &n, &q);

	int kol = 0;
	for (int i=0; i<q; i++) {
		int st;
		scanf("%d", &st);
		if (st == 1) {
			int a;
			scanf("%d", &a);
			br++;
			V[a].push_back(kol);
			S.insert(P(kol, a));
			kol++;
		}
		else if (st == 2) {
			int a;
			scanf("%d", &a);
			for (auto it : V[a]) {
				if (!mak[it])
					br--;
				mak[it] = 1;
				S.erase(P(it, a));
			}

			V[a].clear();
		}
		else {
			int t;
			scanf("%d", &t);

			for (auto it = S.begin(); it != S.end(); ) {
				auto it2 = it++;
				if (it2->X >= t)
					break;

				if (!mak[it2->X])
					br--;
				mak[it2->X] = 1;
				S.erase(it2);
			}
		}

		printf("%d\n", br);
	}

	return 0;
}