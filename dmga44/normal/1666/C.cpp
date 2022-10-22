#include <bits/stdc++.h>

#define int long long

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x1, y1;
    int x2, y2;
    int x3, y3;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

   	vector<pair<int,int>> vect;

   	vect.push_back({x1,y1});
   	vect.push_back({x2,y2});
   	vect.push_back({x3,y3});

   	int may = max({y1,y2,y3});
   	int miy = min({y1,y2,y3});

   	sort(vect.begin(), vect.end());

   	vector<vector<int>> vvv;

   	vvv.push_back({vect[1].first, miy, vect[1].first, may});
   	vvv.push_back({vect[0].first, vect[0].second, vect[1].first, vect[0].second});
   	// vvv.push_back({vect[1].first, vect[1].second, vect[1].first, vect[1].second});
   	vvv.push_back({vect[2].first, vect[2].second, vect[1].first, vect[2].second});

   
   	vector<vector<int>> ans;

   	for(auto x : vvv)
   	{
   		if(x[0] == x[2] && x[1] == x[3])
   		{

   		}
   		else
   		{
   			ans.push_back(x);
   		}
   	}

   	cout << ans.size() << '\n';

   	for(auto x : ans)
   	{
   		for(auto xxx : x)
   		{
   			cout << xxx << " ";
   		}
   		cout << '\n';
   	}

    return 0;
}