#include <bits/stdc++.h>
const int MaxN = 1e5 + 5;
const int LIM = 1e5 + 1;

int mn[MaxN * 4], add[MaxN * 4], setv[MaxN * 4];

void Add(int k, int v) {mn[k] += v; add[k] += v;}
void Set(int k, int v) {mn[k] = v; add[k] = 0; setv[k] = v;}
void PushDown(int k)
{
	if(setv[k] != -1)
	{
		Set(k << 1, setv[k]);
		Set(k << 1 | 1, setv[k]);
		setv[k] = -1;
	}
	if(add[k])
	{
		Add(k << 1, add[k]);
		Add(k << 1 | 1, add[k]);
		add[k] = 0;
	}
}

#define Mid ((L + R) / 2)
template<class Func>
void Modify(int l, int r, int v, const Func &f, int k = 1, int L = 1, int R = LIM)
{
	if(l <= L && R <= r) return f(k, v);
	PushDown(k);
	if(l <= Mid) Modify(l, r, v, f, k << 1, L, Mid);
	if(Mid < r) Modify(l, r, v, f, k << 1 | 1, Mid + 1, R);
	mn[k] = std::min(mn[k << 1], mn[k << 1 | 1]);
}
#undef Mid

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::fill(std::begin(setv), std::end(setv), -1);
	int T; std::cin >> T;
	while(T--)
	{
		Modify(1, LIM, 0, Set);
		
		int n, m; std::cin >> n >> m;
		for(int i = 1, x; i <= n; ++i) std::cin >> x, Modify(1, x, 1, Add);
		
		std::vector<std::vector<int>> S(m + 1);
		
		for(int i = 1, k; i <= m; ++i)
		{
			std::cin >> k;
			int64_t sum = 0;
			for(int j = 0, x; j < k; ++j) std::cin >> x, sum += x, S[i].push_back(x);
			Modify(1, std::min(int((sum + k - 1) / k), LIM), -1, Add);
		}
		
		for(int i = 1; i <= m; ++i)
		{
			int64_t sum = std::accumulate(S[i].begin(), S[i].end(), int64_t(0));
			int k = S[i].size();
			for(int x : S[i])
			{
				Modify(1, std::min(int((sum + k - 1) / k), LIM), 1, Add);
				Modify(1, std::min(int((sum - x + (k - 1) - 1) / (k - 1)), LIM), -1, Add);
				std::cout << int(mn[1] >= 0);
				Modify(1, std::min(int((sum + k - 1) / k), LIM), -1, Add);
				Modify(1, std::min(int((sum - x + (k - 1) - 1) / (k - 1)), LIM), 1, Add);
			}
		}
		
		std::cout << "\n";
	}
	return 0;
}