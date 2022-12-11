#include <bits/stdc++.h>
int main()
{
	const int L = 1e6 + 5;
	
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
    int n, m, k, t; std::cin >> n >> m >> k >> t;
    std::vector<std::vector<std::vector<int>>> a(n, std::vector<std::vector<int>>(m));
    for(int i = 0; i < k; ++i)
	{
        int x, y, w; std::cin >> x >> y >> w; x--, y--;
        a[x][y].push_back(w > 0 ? std::min(w, k + 1) : std::max(w, -k - 1));
    }
    
    std::bitset<L> bp; bp.set(), bp[0] = 0;
    auto bn = bp;
    auto get = [&]() -> int { return bp._Find_first() + bn._Find_first() - 1; };
    
	std::vector<int> cp(k + 2), cn(k + 2);
    auto ins = [&](int x)
	{
        if(x > 0) (++cp[x] == 1 && (bp[x] = 0));
        else (++cn[-x] == 1 && (bn[-x] = 0));
    };
    
    auto del = [&](int x)
	{
		if(x > 0) (--cp[x] == 0 && (bp[x] = 1));
		else (--cn[-x] == 0 && (bn[-x] = 1));
    };
    
    int ans = 0;
    for(int s = 0; s < n + m - 1; ++s)
	{
        int lx = std::max(0, s - m + 1), rx = std::min(n - 1, s);
        for(int i = lx, j = lx - 1; i <= rx; ++i)
		{
            for( ; j < i || (j < rx && get() < t); ++j)
			{
                int x = j + 1, y = s - x;
                for(int p = i; p <= x; ++p) for(int z : a[p][y]) ins(z);
                for(int p = y + 1; p <= s - i; ++p) for(int z : a[x][p]) ins(z);
            }
            
            if(j < rx || get() >= t) ans += rx - j + 1;
            for(int p = i; p <= j; ++p) for(int z : a[p][s - i]) del(z);
            for(int p = s - j; p < s - i; ++p) for(int z : a[i][p]) del(z);
        }
    }
    std::cout << ans << "\n";
    return 0;
}