#pragma GCC optimize("O3","Ofast","no-stack-protector","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>

using namespace std;

struct satisfiability_twosat
{
	int n;
	vector<vector<int>> imp;

	satisfiability_twosat(int n) : n(n), imp(2 * n) {}

	void add_edge(int u, int v)
	{
		imp[u].push_back(v);
	}

	int neg(int u) { return (n << 1) - u - 1; }

	void implication(int u, int v)
	{
		add_edge(u, v);
		add_edge(neg(v), neg(u));
	}

	vector<bool> solve()
	{
		int size = 2 * n;
		vector<int> S, B, I(size);

		function<void(int)> dfs = [&](int u)
		{
			B.push_back(I[u] = S.size());
			S.push_back(u);

			for (int v : imp[u])
				if (!I[v]) dfs(v);
				else while (I[v] < B.back()) B.pop_back();

			if (I[u] == B.back())
				for (B.pop_back(), ++size; I[u] < S.size(); S.pop_back())
					I[S.back()] = size;
		};

		for (int u = 0; u < 2 * n; ++u)
			if (!I[u]) dfs(u);

		vector<bool> values(n);

		for (int u = 0; u < n; ++u)
			if (I[u] == I[neg(u)]) return {};
			else values[u] = I[u] < I[neg(u)];

		return values;
	}
};

#ifdef LOCAL 
#include "/media/brayand/BrayanD/debugger.h"
#else
#define db(...) false
#define dbl(...) false
#define dbg(...) false
#define dbm(...) false
#define dbs(...) false
#define dbas(...) false
#endif

const int MAXN = 4e5 + 100;

vector<pair<int,int>> L[MAXN];
vector<int> LLL[MAXN];

vector<int> arr[MAXN];

set<int> st;

int cont[MAXN];

int c0, c1, c2;

void sumar(int x)
{
	if(cont[x] == 0)c0--;
	if(cont[x] == 1)c1--;
	if(cont[x] == 2)c2--;

	cont[x]++;

	if(cont[x] == 0)c0++;
	if(cont[x] == 1)c1++;
	if(cont[x] == 2)c2++;
}

void restar(int x)
{
	if(cont[x] == 0)c0--;
	if(cont[x] == 1)c1--;
	if(cont[x] == 2)c2--;

	cont[x]--;

	if(cont[x] == 0)c0++;
	if(cont[x] == 1)c1++;
	if(cont[x] == 2)c2++;
}

bool mk[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, p, M, m;
    cin >> n >> p >> M >> m;

    c0 = n;

    for(int i = 1 ; i <= n ; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	L[a].push_back({b,i});
    	L[b].push_back({a,i});
    	mk[a] = true;
    	mk[b] = true;
    }

    for(int i = 1 ; i <= p ; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	if(mk[i])
    	{
	    	arr[a].push_back(i);
	    	arr[b+1].push_back(-i);
    	}
    }

    for(int i = 1 ; i <= m ; i++)
    {
    	int a, b;
    	cin >> a >> b;

    	if(mk[a] && mk[b])
    	{
	    	LLL[a].push_back(b);
	    	LLL[b].push_back(a);
    	}
    }

    vector<int> ans;
    int F = -1;

    set<int> st;

    for(int i = 1 ; i <= M ; i++)
    {
    	bool ok = false;
    	for(auto x : arr[i])
    	{
    		// db(x);
    		ok = true;
    		if(x > 0)
    		{
    			st.insert(x);
    			for(auto v : L[x])
    			{
    				sumar(v.second);
    			}
    		}
    		else
    		{
    			st.erase(-x);
    			for(auto v : L[-x])
    			{
    				restar(v.second);
    			}
    		}
    	}

    	if(ok == false)continue;

    	// db(i,c0,c1,c2);
    	// db(st);

    	if(c0 == 0)
    	{
    		satisfiability_twosat TS(p+1);
    		for(auto nodo : st)
    		{	
    			for(auto v : L[nodo])
    			{
    				if(st.find(v.first) != st.end())
    				{
    					TS.add_edge(TS.neg(nodo),v.first);
    					TS.add_edge(TS.neg(v.first),nodo);
    				}
    				else
    				{
    					TS.add_edge(TS.neg(nodo),nodo);
    					TS.add_edge(TS.neg(nodo),nodo);
    				}
    			}
    			for(auto v : LLL[nodo])
    			{
    				if(st.find(v) != st.end())
    				{
    					TS.add_edge(nodo,TS.neg(v));
    					TS.add_edge(v,TS.neg(nodo));
    				}
    			}
    		}

    		vector<bool> vect = TS.solve();

    		if(vect.size())
    		{
	    		for(auto x : st)
	    		{
	    			if(vect[x])
	    			{
	    				ans.push_back(x);
	    			}
	    		}
	    		F = i;
	    		break;
    		}
    	}
    }

    if(F == -1)
    {
    	cout << -1 << '\n';
    }
    else
    {
    	cout << ans.size() << " " << F << '\n';
    	for(auto x : ans)
    	{
    		cout << x << " ";
    	}
    	cout << '\n';
    }

    return 0;
}