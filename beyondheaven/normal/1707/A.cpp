#include <bits/stdc++.h>
const int MaxN = 1e5 + 5;
const int inf = 1e9;

int n, q, a[MaxN], ans[MaxN];
std::vector<int> V[MaxN]; 

#define mid ((l + r) / 2)
#define ls (k << 1)
#define rs (k << 1 | 1)

int add[MaxN * 4];
std::array<int, 2> mx[MaxN * 4];
void build(int k = 1, int l = 1, int r = n)
{
	add[k] = 0;
	if(l == r) return mx[k] = { a[l], l }, void();
	build(ls, l, mid); build(rs, mid + 1, r);
	mx[k] = std::max(mx[ls], mx[rs]); 
}

void apply(int k, int v)
{
	add[k] += v;
	mx[k][0] += v;
}

void pushdown(int k)
{
	if(add[k])
	{
		apply(ls, add[k]);
		apply(rs, add[k]);
		add[k] = 0;
	}
}

void modify(int ql, int qr, int v, int k = 1, int l = 1, int r = n)
{
	if(ql <= l && r <= qr) return apply(k, v);
	pushdown(k);
	if(ql <= mid) modify(ql, qr, v, ls, l, mid);
	if(mid < qr) modify(ql, qr, v, rs, mid + 1, r);
	mx[k] = std::max(mx[ls], mx[rs]);
}

void update(int p, int k = 1, int l = 1, int r = n)
{
	if(l == r) return mx[k] = { -inf, 0 }, void();
	pushdown(k);
	if(p <= mid) update(p, ls, l, mid);
	else update(p, rs, mid + 1, r);
	mx[k] = std::max(mx[ls], mx[rs]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T; std::cin >> T;
	while(T--)
	{
		std::cin >> n >> q;
		for(int i = 1; i <= n; ++i) V[i].clear();
		for(int i = 1; i <= n; ++i) std::cin >> a[i];
		build();
		
		if(q >= n) { std::cout << std::string(n, '1') << "\n"; continue; }
		
		std::priority_queue<int> cand;
		std::fill(ans + 1, ans + n + 1, 1);
		
		int cur = n, tim = 0;
		while(mx[1][0] > q)
		{
			--cur;
			cand.push(mx[1][1]);
			ans[mx[1][1]] = 0;
			update(mx[1][1]);
		}
		
		std::array<int, 2> best = { cur, 0 };
		
		while(cand.size() && tim < q)
		{
			int x = cand.top(); cand.pop();
			if(x < n) modify(x + 1, n, 1);
			
			++tim;
			++cur;
			V[tim].push_back(x);
			
			while(mx[1][0] > q)
			{
				--cur;
				cand.push(mx[1][1]);
				V[tim].push_back(mx[1][1]);
				update(mx[1][1]);
			}
			
			best = std::max(best, { cur, tim });
		}
		
		for(int i = 1; i <= best[1]; ++i)
		for(int x : V[i]) ans[x] ^= 1;
		
		std::copy(ans + 1, ans + n + 1, std::ostream_iterator<int>(std::cout, ""));
		std::cout << "\n";
	}
	
	return 0;
}