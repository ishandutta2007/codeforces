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

const int MAXN = 1e5 + 100;

int arr[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string cad;
    cin >> cad;

    int N = cad.size();

    for(int i = 0 ; i < N ; i++)
    {
    	if(cad[i] == '#')
    	{
    		arr[i] = 1;
    	}
    }

    arr[N] = 1;

    vector<int> temp;

    if(arr[0] == 1)
    {
    	temp.push_back(0);
    }

    int cont = 0;
    bool in = false;

    for(int i = 0 ; i < N+1 ; i++)
    {
    	if(arr[i] == 0)
    	{
    		if(in == false)
    		{
    			in = true;
    			cont = 1;
    		}
    		else
    		{
    			cont++;
    		}
    	}
    	else
    	{
    		if(in == true)
    		{
    			temp.push_back(cont);
    			in = false;
    			cont = 0;
    		}
    	}
    }

    if(arr[N-1] == 1)
    {
    	temp.push_back(0);
    }

    int men = 1e18;

    for(auto x : temp)
    {
    	men = min(men, x);
    }

    vector<pair<int,int>> vvv;

    arr[N] = 0;

    cont = 0;
    in = false;

    for(int i = 0 ; i < N+1 ; i++)
    {
    	if(arr[i] == 1)
    	{
    		if(in == false)
    		{
    			in = true;
    			cont = 1;
    		}
    		else
    		{
    			cont++;
    		}
    	}
    	else
    	{
    		if(in == true)
    		{
    			vvv.push_back({i-1,cont});
    			in = false;
    			cont = 0;
    		}
    	}
    }

    if(vvv.size() == 0)
    {
    	cout << 0 << '\n';
    	return 0;
    }

    int res = -1;

    for(int D = 0 ; D <= men ; D++)
    {
    	int last = 0;

    	bool ok = true;

    	for(auto x : vvv)
    	{
    		int pos = (x.first-x.second+1)-D;
    		if(last > pos)
    		{
    			ok = false;
    			break;
    		}

    		int dist = pos-last;

    		// db(D,dist);

    		if(D == 0)
    		{
    			if(dist > 0)
    			{
    				ok = false;
    				break;
    			}
    		}
    		if(D == 1)
    		{
    			if(dist%2)
    			{
    				ok = false;
    				break;
    			}
    		}
    		if(D >= 2)
    		{
    			if(dist == 1)
    			{
    				ok = false;
    				break;
    			}
    		}

    		last = x.first+2;
    	}

    	int dist = temp.back();
    	dist -= D;

    	if(D == 0)
		{
			if(dist > 0)
			{
				ok = false;
			}
		}
		if(D == 1)
		{
			if(dist%2)
			{
				ok = false;
			}
		}
		if(D >= 2)
		{
			if(dist == 1)
			{
				ok = false;
			}
		}
		if(ok)
		{
			res = D;
			break;
		}
    }

    if(res == -1)
    {
    	cout << -1 << '\n';
    	return 0;
    }

    int D = res;

    int last = 0;

	bool ok = true;

	vector<int> ans;

	for(auto x : vvv)
	{
		int pos = (x.first-x.second+1)-D;

		int dist = pos-last;

		if(D == 0)
		{
			
		}
		if(D == 1)
		{
			for(int i = 0 ; i < dist/2 ; i++)
			{
				ans.push_back(1);
			}
		}
		if(D >= 2)
		{
			if(dist%2 == 0)
			{
				for(int i = 0 ; i < dist/2 ; i++)
				{
					ans.push_back(1);
				}
			}
			else
			{
				for(int i = 0 ; i < dist/2-1 ; i++)
				{
					ans.push_back(1);
				}
				ans.push_back(2);
			}
		}

		ans.push_back(x.second+D);

		last = x.first+2;
	}

	int dist = temp.back();
	dist -= D;

	if(D == 0)
	{
		
	}
	if(D == 1)
	{
		for(int i = 0 ; i < dist/2 ; i++)
		{
			ans.push_back(1);
		}
	}
	if(D >= 2)
	{
		if(dist%2 == 0)
		{
			for(int i = 0 ; i < dist/2 ; i++)
			{
				ans.push_back(1);
			}
		}
		else
		{
			for(int i = 0 ; i < dist/2-1 ; i++)
			{
				ans.push_back(1);
			}
			ans.push_back(2);
		}
	}

	cout << ans.size() << '\n';

	for(auto x : ans)
	{
		cout << x << " ";
	}

	cout << '\n';

    return 0;
}