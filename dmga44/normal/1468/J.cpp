#include <bits/stdc++.h>

#define int long long

using namespace std;

struct DSU
{
    vector<int> DS;
    DSU(int N)
    {
        DS.resize(N);
        fill(DS.begin(),DS.end(),-1);
    }
    int find(int x)
    {
        if(DS[x] < 0)return x;
        return DS[x] = find(DS[x]);
    }
    void join(int a, int b)
    {
        a = find(a);
        b = find(b);
        if(a == b)return;
        if(DS[a] > DS[b])swap(a,b);
        DS[a] += DS[b];
        DS[b] = a;
    }
    bool con()
    {
    	int temp = DS.size();
    	if(DS[find(0)] == -temp)return true;
    	return false;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
    	int N, M, K;
    	cin >> N >> M >> K;

    	DSU ds(N);

    	vector<pair<int,pair<int,int>>> vect;

    	for(int i = 0 ; i < M ; i++)
    	{
    		int x, y, s;
    		cin >> x >> y >> s;
    		x--;
    		y--;
    		vect.push_back({s,{x,y}});
    	}

    	sort(vect.begin(), vect.end());

    	int res = 1e18;

    	int sum = 0;

    	bool flag = true;

    	for(int i = 0 ; i < M ; i++)
    	{
    		int a = vect[i].second.first;
    		int b = vect[i].second.second;
    		int c = vect[i].first;

    		if(c <= K)
    		{
    			ds.join(a,b);
    			if(ds.con())
    			{
    				res = min(res, K-c);
    			}
    		}
    		else
    		{
    			if(flag)
    			{
    				flag = false;

    				if(ds.find(a) != ds.find(b))
    				{
    					sum += c-K;
    				}

    				ds.join(a,b);

    				if(ds.con())
    				{
    					res = min(res, c-K);
    					break;
    				}
    			}
    			else
    			{
    				if(ds.find(a) != ds.find(b))
    				{
    					sum += c-K;
    				}
    				ds.join(a,b);
    				if(ds.con())
    				{
   					 	res = min(res, sum);
   					 	break;
    				}
    			}
    		}
    	}

    	cout << res << '\n';
    }

    return 0;
}