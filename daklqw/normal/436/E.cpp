#include <bits/stdc++.h>

const int MAXN = 3e5 + 10;
typedef long long LL;
int n, W;
struct info {
	int a, b, id;
	bool operator < (const info & x) const {
		return a < x.a;
	}
} ps[MAXN];
typedef std::multiset<int> M;
typedef M::iterator IT;
struct president_queue {
	M in, out;
	int cnt; LL sm;
	void ins(int x) {
		if (!in.empty() && x <= *in.rbegin()) {
			in.insert(x);
			++cnt, sm += x;
		} else {
			out.insert(x);
		}
	}
	void del(int x) {
		if (!in.empty() && x <= *in.rbegin()) {
			in.erase(in.lower_bound(x));
			--cnt, sm -= x;
		} else {
			out.erase(out.lower_bound(x));
		}
	}
	void pop() {
		IT it = in.end();
		--cnt, sm -= *--it;
		out.insert(out.begin(), *it);
		in.erase(it);
	}
	void push() {
		IT it = out.begin();
		++cnt, sm += *it;
		in.insert(in.end(), *it);
		out.erase(it);
	}
	int top(int t) {
		if (t == 0)
			return *in.rbegin();
		else return *out.begin();
	}
	int top2(int t) {
		int r = 0;
		if (t == 0) {
			IT it = in.end();
			r += *--it;
			r += *--it;
		} else {
			IT it = out.begin();
			r += *it++;
			r += *it;
		}
		return r;
	}
} q[2];

LL Ans = std::numeric_limits<LL>::max();
int Aat = -1, Acur = -1;
inline int calc() {
	return q[0].cnt + q[1].cnt * 2;
}
void query(int down, LL ans) {
	if (down > W) return ;
	int rest = W - down;
	while (q[1].cnt && calc() > rest) q[1].pop();
	while (q[0].cnt && calc() > rest) q[0].pop();
	while (!q[1].out.empty() && calc() + 2 <= rest) q[1].push();
	while (!q[0].out.empty() && calc() + 1 <= rest) q[0].push();
	if (calc() != rest) return ;
	while (q[1].cnt && q[0].out.size() > 1 && q[0].top2(1) < q[1].top(0))
		q[0].push(), q[0].push(), q[1].pop();
	while (q[0].cnt > 1 && !q[1].out.empty() && q[1].top(1) < q[0].top2(0))
		q[0].pop(), q[0].pop(), q[1].push();
	assert(calc() == rest);
	ans += q[0].sm + q[1].sm;
	if (ans < Ans) {
		Aat = down;
		Acur = q[0].cnt;
		Ans = ans;
	}
}
int main() {
#define OUTPUTSOL
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> W;
	for (int i = 1; i <= n; ++i)
		std::cin >> ps[i].a >> ps[i].b, ps[i].id = i;
	std::sort(ps + 1, ps + 1 + n);
	for (int i = 1; i <= n; ++i)
		q[1].ins(ps[i].b);
	query(0, 0);
	LL pre = 0;
	for (int i = 1; i <= n; ++i) {
		q[1].del(ps[i].b);
		pre += ps[i].a;
		q[0].ins(ps[i].b - ps[i].a);
		query(i, pre);
	}
	std::cout << Ans << std::endl;
#ifdef OUTPUTSOL
	static int ansl[MAXN];
	for (int i = 1; i <= Aat; ++i)
		ansl[ps[i].id] = 1;
	int lhs = Acur, rhs = (W - Aat - Acur) / 2;
	typedef std::pair<LL, int> pi;
	static pi li[MAXN]; int bak;
	bak = 0;
	for (int i = 1; i <= Aat; ++i)
		li[++bak] = pi(ps[i].b - ps[i].a, i);
	std::sort(li + 1, li + 1 + bak);
	for (int i = 1; i <= lhs; ++i)
		ansl[ps[li[i].second].id] = 2;
	bak = 0;
	for (int i = Aat + 1; i <= n; ++i)
		li[++bak] = pi(ps[i].b, i);
	std::sort(li + 1, li + 1 + bak);
	for (int i = 1; i <= rhs; ++i)
		ansl[ps[li[i].second].id] = 2;
	for (int i = 1; i <= n; ++i)
		std::cout << ansl[i];
	std::cout << '\n';
#endif
	return 0;
}