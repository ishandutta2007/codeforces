#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define debug(code) ((void)0)
#define fori(i,s,e) for (int i = s; i < e; i++)

int nCoins, nBags;
typedef struct bag {
	int id;
	int cs;
	public:
		bag(int ii, int cc): id(ii), cs(cc) {}
		bool operator< (const bag & b) const {
			return cs > b.cs;
		}
} bag;
vector<bag> bags;
int bagcs[70004];

const int BITS_N = 2200;
struct bits {
	unsigned int xs[BITS_N];
	bits() {
		fill(xs, xs + BITS_N, 0);
	}
	bits(const bits & o)           { copy(o.xs, o.xs + BITS_N, xs); }
	void operator=(const bits & o) { copy(o.xs, o.xs + BITS_N, xs); }
	void operator<<=(int d) {
		int bd = d / 32, sd = d % 32;
		for (int i = BITS_N - 1 - bd; i >= 0; i--) {
			xs[i + bd] = xs[i] << sd | ((i && sd) ? (xs[i-1] >> (32 - sd)) : 0);
		}
	}
	void operator|=(const bits & o) { fori (i, 0, BITS_N) xs[i] |= o.xs[i]; }
	void operator&=(const bits & o) { fori (i, 0, BITS_N) xs[i] &= o.xs[i]; }
	void setAndNot(const bits & o) { fori (i, 0, BITS_N) xs[i] &= ~o.xs[i]; }
	void invert() { fori (i, 0, BITS_N) xs[i] = ~xs[i]; }
	void getOnes(vector<int> & out) {
		out.clear();
		fori (i, 0, BITS_N) {
			unsigned int x = xs[i];
			while (x) {
				int c = __builtin_ctz(x);
				out.push_back(i * 32 + c);
				x &= ~(1u << c);
			}
		}
	}
	void set(int ix) {
		int bix = ix / 32, six = ix % 32;
		xs[bix] |= (1u << six);
	}
};

void readInput() {
	scanf("%d%d", &nBags, &nCoins);
	for (int i = 1; i <= nBags; i++) {
		int x;
		scanf("%d",&x);
		bagcs[i] = x;
		bags.push_back(bag(i, x));
	}
}
vector<int> v;
void outputAnswer() {
	sort(bags.begin(), bags.end());

	int rcs = nCoins - bags[0].cs;
	debug(printf("rcs: %d", rcs));
	if (rcs < 0) {
		printf("-1\n"); return;
	}
	bits dp, dp2;
	dp.set(0);
	int dpp[70700];
	memset(dpp, 0, sizeof(dpp));
	dpp[0] = -1;
	bool done = false;
	for (int i = 1; i < bags.size() && !done; i++){
		const bag & b = bags[i];
		dp2 = dp;
		dp2 <<= b.cs;
		dp2.setAndNot(dp);
		dp |= dp2;
		dp2.getOnes(v);
		fori (j, 0, v.size()) {
			dpp[v[j]] = bags[i].id;
			if (v[j] == rcs) { done = true; break; }
		}
	}
	if (dpp[rcs] != 0) {
		// we did it
		bool solo[70004];
		int contains[70004];
		for (int j = 1; j <= nBags; j++) {
			// every bag in the chain except (an arbitrarily designated) biggest
			solo[j] = false;
		}

		int s = rcs;
		while (s > 0) {
			solo[dpp[s]] = true;
			s -= bagcs[dpp[s]];
		}

		int bigid = bags[0].id;
		int stackid = bigid;
		fori (j, 1, bags.size()) {
			if (!solo[bags[j].id]) {
				contains[stackid] = bags[j].id;
				stackid = bags[j].id;
			}
		}

		fori (j, 1, nBags + 1) {
			// j contains something iff j is in the chain (!solo[j]) and is not the last one (!= stackid)
			if (!solo[j] && j != stackid) {
				int inside = contains[j];
				printf("%d 1 %d\n", bagcs[j] - bagcs[inside], inside);
			} else {
				// j has nothing inside
				printf("%d 0\n", bagcs[j]);
			}
		}
		return;
	}
	printf("-1\n");
	return;
}

int main() {
	readInput();
	outputAnswer();
}