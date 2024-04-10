#include <bits/stdc++.h>

#define int long long

using namespace std;

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

const int MAXN = 110;

vector<int> L[MAXN];

int D[MAXN];

void precal(int nodo)
{
	for(auto v : L[nodo])
	{
		D[v] = D[nodo]+1;
		precal(v);
	}
}

int fin;

bool ok[MAXN];

void precal2(int nodo)
{
	if(nodo == fin)
	{
		ok[nodo] = true;
	}

	int tp = -1;

	for(auto v : L[nodo])
	{
		precal2(v);
		if(ok[v])
		{
			ok[nodo] = true;
			tp = v;
		}
	}

	if(tp != -1)
	{
		for(int i = 0 ; i < L[nodo].size() ; i++)
		{
			if(L[nodo][i] == tp)
			{
				L[nodo].erase(L[nodo].begin()+i);
				L[nodo].push_back(tp);
				break;
			}
		}
	}
}

int N, K;

vector<int> ans;

void DFS(int nodo)
{
	if(ok[nodo])
	{
		for(int i = 0 ; i < (int)L[nodo].size()-1 ; i++)
		{
			int v = L[nodo][i];
			if(K)
			{
				K--;
				ans.push_back(v);
				DFS(v);
				ans.push_back(nodo);
			}
		}
		if(nodo != fin)
		{
			ans.push_back(L[nodo].back());
			DFS(L[nodo].back());
		}
	}
	else
	{
		for(auto v : L[nodo])
		{
			if(K)
			{
				K--;
				ans.push_back(v);
				DFS(v);
				ans.push_back(nodo);
			}
		}
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
    	cin >> N >> K;

    	for(int i = 1 ; i <= N ; i++)
    	{
    		L[i].clear();
    		ok[i] = false;
    	}

    	for(int i = 2 ; i <= N ; i++)
    	{
    		int n;
    		cin >> n;
    		L[n].push_back(i);
    	}

    	D[1] = 1;

    	precal(1);

    	int may = 0;

    	for(int i = 1 ; i <= N ; i++)
    	{
    		may = max(may, D[i]);
    	}

    	may = min(may, K);

    	fin = -1;

    	for(int i = 1 ; i <= N ; i++)
    	{
    		if(D[i] == may)
    		{
    			fin = i;
    		}
    	}

    	precal2(1);

    	ans.clear();

    	ans.push_back(1);

    	K -= may;

    	DFS(1);

    	cout << ans.size()-1 << '\n';

    	for(auto x : ans)
    	{
    		cout << x << " ";
    	}
    	cout << '\n';
    }

    return 0;
}