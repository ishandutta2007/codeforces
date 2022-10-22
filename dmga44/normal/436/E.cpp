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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, W;
    cin >> N >> W;

    vector<int> vect;

    vector<int> r1(1);

    vector<pair<pair<int,int>,pair<int,int>>> vvv;

    vector<pair<int,int>> ans;

    for(int i = 1 ; i <= N ; i++)
    {
    	int a, b;
    	cin >> a >> b;

    	if(b-a >= a)
    	{
    		vect.push_back(a);
    		vect.push_back(b-a);
    		ans.push_back({a,i});
    		ans.push_back({b-a,i});
    	}
    	else
    	{
    		vvv.push_back({{b,i},{a,b-a}});
    	}
    }

    sort(vect.begin(), vect.end());
    sort(ans.begin(), ans.end());

    for(auto x : vect)
    {
    	r1.push_back(x);
    }

    for(int i = 1 ; i < r1.size() ; i++)
    {
    	r1[i] += r1[i-1];
    }

    sort(vvv.begin(), vvv.end());

    vector<int> r2(vvv.size()*2+1);
    vector<int> bt2(vvv.size()*2+1);

    for(int i = 0 ; i < vvv.size() ; i++)
    {
    	r2[(i+1)*2] = vvv[i].first.first+r2[(i)*2];
    }

    multiset<int> st1, st2;

    for(int i = 0 ; i < vvv.size() ; i++)
    {
    	st2.insert(vvv[i].second.first);
    }

    int sum = 0;

    for(int i = 0 ; i < vvv.size() ; i++)
    {
    	r2[i*2+1] = (*st2.begin())+sum;

    	bt2[i*2+1] = -1;

    	st2.erase(st2.find(vvv[i].second.first));

    	st1.insert(vvv[i].second.second);

    	sum += vvv[i].first.first;

    	if((sum - *(--st1.end())) < r2[i*2+1])
    	{
    		r2[i*2+1] = (sum - *(--st1.end()));
    		bt2[i*2+1] = 1;
    	}
    }

    // db(r1);
    // db(r2);

    int res = 1e18;

    int rt1 = -1;
    int rt2 = -1;

    for(int i = 0 ; i < r1.size() ; i++)
    {
    	int x = i;
    	int y = W-i;
    	if(0 <= y && y < r2.size())
    	{
    		if(r1[x]+r2[y] < res)
    		{
    			res = r1[x]+r2[y];

    			rt1 = x;
    			rt2 = y;
    		}
    		res = min(res, r1[x]+r2[y]);
    	}
    }

    cout << res << '\n';

    // db(rt1,rt2);

    vector<int> fres(N+1);

    for(int i = 0 ; i < rt1 ; i++)
    {
    	fres[ans[i].second]++;
    }

    if(rt2%2 == 0)
    {
    	for(int i = 0 ; i < rt2/2 ; i++)
    	{
    		fres[vvv[i].first.second] = 2;
    	}
    }
    else
    {
    	if(bt2[rt2] == -1)
    	{
    		for(int i = 0 ; i < rt2/2 ; i++)
    		{
    			fres[vvv[i].first.second] = 2;
    		}
    		int pos = -1;
    		int men = 1e18;
    		for(int i = rt2/2 ; i < vvv.size() ; i++)
    		{
    			if(vvv[i].second.first < men)
    			{
    				men = vvv[i].second.first;
    				pos = vvv[i].first.second;
    			}
    		}
    		fres[pos] = 1;
    	}
    	else
    	{
    		for(int i = 0 ; i < rt2/2+1 ; i++)
    		{
    			fres[vvv[i].first.second] = 2;
    		}

    		set<pair<int,int>> st;

    		for(int i = 0 ; i < rt2/2+1 ; i++)
    		{
    			st.insert({vvv[i].second.second,vvv[i].first.second});
    		}

    		int pos = (*(--st.end())).second;
    		fres[pos]--;
    	}
    }

    for(int i = 1 ; i <= N ; i++)
    {
    	cout << fres[i];
    }
    cout << '\n';

    return 0;
}