#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 111111;
const int INF = 1000000000;
const double eps = 1e-8;

int n, q, init[N];
vector<pair<pair<int, int>, double> > pairs;

struct Exp {
	int base;
	vector<double> prob;
	Exp(int base, vector<double> prob) : base(base), prob(prob) {}
	Exp(int _base) {
		base = _base;
		prob.clear();
		prob.push_back(1);
	}
	Exp() {
		base = -INF;
		prob.clear();

	}
	void show() {
		puts("");
		printf("base = %d\n", base);
		for(int i = 0; i < (int)prob.size(); i++) {
			printf("%f\n", prob[i]);
		}
	}
};

int iter;

Exp comb(Exp a, Exp b) {
	/*printf("comb !!! \n");
	a.show();
	printf("------");
	b.show();
	puts("");
	*/
	if (a.base < b.base) {
		swap(a, b);
	}
	Exp ret;
	ret.base = a.base;
	int limit = max(a.base + (int)a.prob.size() - 1, b.base + (int)b.prob.size() - 1);
	double downA = 0, downB = 0;
	for(int i = a.base, pa = 0, pb = 0; i <= limit; i++) {
		while(pa < (int)a.prob.size() && a.base + pa < i) {
			downA += a.prob[pa];
			pa++;
		}
		while(pb < (int)b.prob.size() && b.base + pb < i) {
			downB += b.prob[pb];
			pb++;
		}

		double curA = 0, curB = 0;
		if (i <= a.base + (int)a.prob.size() - 1) {
			curA = a.prob[i - a.base];
		}
		if (i <= b.base + (int)b.prob.size() - 1) {
			curB = b.prob[i - b.base];
		}
		ret.prob.push_back(curA * downB + curB * downA + curA * curB);
	}
	return ret;
}

Exp dfs(int l, int r, double p) {
	//printf("%d %d %f\n", l, r, p);
	Exp ret(-INF);
	int maxV = -INF;
	for(int i = l; i <= r; i++) {
		//printf("%d\n", i);
		if (iter < (int)pairs.size() && pairs[iter].first.first == i) {
			i = pairs[iter].first.second;
			iter++;
			Exp temp = dfs(pairs[iter - 1].first.first, pairs[iter - 1].first.second, pairs[iter - 1].second);
			ret = comb(ret, temp);
		} else {
			maxV = max(maxV, init[i]);
		}
	}
	ret = comb(ret, Exp(maxV));
	ret.prob.push_back(0);
	for(int i = (int)ret.prob.size() - 1; i >= 0; i--) {
		ret.prob[i] *= (1 - p);
		if (i > 0) {
			ret.prob[i] += ret.prob[i - 1] * p;
		}
	}
	//ret.show();
	//printf("over %d %d %f\n", l, r, p);
	return ret;
}

int main() {
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &init[i]);
	}

	for(int i = 1; i <= q; i++) {
		int a, b;
		double p;
		scanf("%d %d %lf", &a, &b, &p);
		pairs.push_back(make_pair(make_pair(a, -b), p));
	}
	sort(pairs.begin(), pairs.end());
	for(int i = 0; i < (int)pairs.size(); i++) {
		pairs[i].first.second *= -1;
	}

	iter = 0;
	Exp temp = dfs(1, n, 0);
	double answer = temp.base;
	for(int i = 0; i < (int)temp.prob.size(); i++) {
		answer += i * temp.prob[i];
	}
	printf("%.8f\n", answer);
	return 0;
}