#include <bits/stdc++.h>
std::vector<int> query(std::vector<int> d)
{
	std::cout << "? ";
	for(int x : d) std::cout << x << " ";
	std::cout.flush();
	
	std::string s; std::cin >> s;
	std::vector<int> res;
	for(char c : s) res.push_back(c == '0' ? 0 : 1);
	return res;
}

void report(std::vector<std::pair<int, int>> E)
{
	std::cout << "!\n";
	for(auto e : E) std::cout << e.first << " " << e.second << "\n";
}

void solve(int n)
{
	int L = 1;
	while(L < n) L <<= 1;
	
	std::vector<std::vector<int>> T(L), V(L);
	T[0].push_back(0);
	for(int i = 1; i < n; ++i) V[0].push_back(i);
	
	for(int i = L; i != 1; i /= 2)
	for(int st : { 0, i })
	{
		std::vector<int> d(n);
		for(int j = st; j < L; j += i * 2) for(int x : T[j]) d[x] = i / 2;
		auto res1 = query(d);
		
		d.assign(n, 0);
		for(int j = st; j < L; j += i * 2) for(int x : T[j]) d[x] = i / 2 - 1;
		auto res2 = query(d);
		
		for(int j = st; j < L; j += i * 2)
		{
			for(int x : V[j])
			{
				if(res1[x] == 1 && res2[x] == 0) T[j + i / 2].push_back(x);
				else if(!res1[x]) V[j + i / 2].push_back(x);
			}
			
			V[j].erase(std::remove_if(V[j].begin(), V[j].end(),
				[&](int x) { return !res2[x]; }), V[j].end());
		}
	}
	
	std::vector<int> fa(n);
	for(int i = 0; (1 << i) != L; ++i)
	for(int st : { 0, 1, 2 })
	{
		std::vector<int> d(n);
		for(int j = st; j < L; j += 3)
		for(int x : T[j]) if((x >> i) & 1) d[x] = 1;
		
		auto res = query(d);
		for(int j = st + 1; j < L; j += 3)
		for(int x : T[j]) if(res[x]) fa[x] |= (1 << i);
	}
	
	std::vector<std::pair<int, int>> ans;
	for(int i = 1; i < n; ++i) ans.emplace_back(fa[i] + 1, i + 1);
	report(ans);
}

int main()
{
	int n; std::cin >> n;
	solve(n);
	return 0;
}