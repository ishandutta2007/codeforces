#pragma GCC optimize("O3","Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510;

int D[MAXN][MAXN];

vector<int> L[MAXN];

int query(int nodo)
{
	cout << nodo << '\n';
	cout.flush();

	string cad;
	cin >> cad;

	if(cad == "FOUND")
	{
		return -1;
	}
	
	int num;
	cin >> num;

	return num;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i = 0 ; i < M ; i++)
    {
    	int K;
    	cin >> K;

    	vector<int> vect;

    	for(int j = 0 ; j < K ; j++)
    	{
    		int n;
    		cin >> n;
    		vect.push_back(n);
    	}

    	for(int i = 1 ; i < K ; i++)
    	{
    		int a = vect[i-1], b = vect[i];
    		L[a].push_back(b);
    		L[b].push_back(a);
    	}
    }

    for(int tc = 0 ; tc < N ; tc++)
    {
    	vector<vector<int>> ady(N+1);

    	vector<bool> ok(N+1);

    	vector<int> nodos;

    	for(int i = 1 ; i <= N ; i++)
    	{
    		ady[i] = L[i];
    		nodos.push_back(i);
    	}

    	vector<vector<int>> D(N+1, vector<int>(N+1));

    	vector<bool> mk(N+1);

    	while(1)
    	{
    		// db(nodos);
    		for(auto x : nodos)
    		{
    			for(auto y : nodos)
    			{
    				mk[y] = false;
    			}

    			queue<int> Q;
    			Q.push(x);
    			D[x][x] = 0;
    			mk[x] = true;

    			while(Q.size())
    			{
    				int nodo = Q.front();
    				Q.pop();

    				for(auto v : ady[nodo])
    				{
    					if(!mk[v])
    					{
    						mk[v] = true;
    						D[x][v] = D[x][nodo]+1;
    						Q.push(v);
    					}
    				}
    			}
    		}

    		int men = 1e18;
    		int root = -1;

    		for(auto nodo : nodos)
    		{
    			int may = 0; 
    			for(auto v : ady[nodo])
    			{
    				int sum = 0;
    				for(auto xxx : nodos)
    				{
    					if(D[v][xxx] < D[nodo][xxx])sum++;
    				}
    				may = max(may, sum);
    			}

    			if(may < men)
    			{
    				men = may;
    				root = nodo;
    			}
    		}

    		int qu = query(root);

    		if(qu == -1)
    		{
    			break;
    		}

    		vector<int> tempnodos;

    		// db(qu);

    		for(auto xxx : nodos)
    		{
    			// dbl(xxx,D[qu][xxx],D[root][xxx]);
    			if(D[qu][xxx] >= D[root][xxx])
    			{
    				ok[xxx] = true;
    			}
    			else
    			{
    				tempnodos.push_back(xxx);
    			}
    		}
    		// db(tempnodos);

    		nodos = tempnodos;

    		vector<pair<int,int>> edges;

    		for(auto nodo : nodos)
    		{
    			for(auto v : ady[nodo])
    			{
    				if(!ok[v])
    				{
    					edges.push_back({nodo,v});
    				}
    			}
    		}

    		for(auto nodo : nodos)
    		{
    			ady[nodo].clear();
    		}

    		for(auto x : edges)
    		{
    			ady[x.first].push_back(x.second);
    		}
    	}
    }

    return 0;
}