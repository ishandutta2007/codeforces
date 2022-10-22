#include <bits/stdc++.h>

#define int long long

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
    	string cad;
    	cin >> cad;

    	int N = cad.size();

    	vector<pair<int,int>> vect;

    	int x = 0, y = 0;

    	for(int i = 0 ; i < N ; i++)
    	{
    		if(cad[i] == 'L')x--;
    		if(cad[i] == 'R')x++;
    		if(cad[i] == 'D')y--;
    		if(cad[i] == 'U')y++;
    		vect.push_back({x,y});
    	}

    	int rx = 0, ry = 0;

    	for(auto pp : vect)
    	{
    		int x = 0, y = 0;
    		for(int i = 0 ; i < N ; i++)
	    	{
	    		int tx = x, ty = y;
	    		if(cad[i] == 'L')x--;
	    		if(cad[i] == 'R')x++;
	    		if(cad[i] == 'D')y--;
	    		if(cad[i] == 'U')y++;
	    		if(x == pp.first && y == pp.second)
	    		{
	    			x = tx, y = ty;
	    		}
	    	}

	    	if(!x && !y)
	    	{
	    		rx = pp.first;
	    		ry = pp.second;
	    	}
    	}

    	cout << rx << " " << ry << '\n';
    }

    return 0;
}