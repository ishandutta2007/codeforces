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

char fff[8] = {'1','2','3','4','5','6','7','8'};
char ccc[8] = {'a','b','c','d','e','f','g','h'};

string f(int a, int b)
{
	string cad;
	cad += ccc[b];
	cad += fff[a];
	return cad;
}

bool mk[8][8];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int x = 0, y = 0;

    vector<string> res;

    res.push_back(f(0,0));

    if(N <= 50)
    {
    	N -= 2;
    	while(N--)
    	{
    		if(x%2==0)
    		{
    			if(y == 6)
    			{
    				x++;
    			}
    			else
    			{
    				y++;
    			}
    		}
    		else
    		{
    			if(y == 0)
    			{
    				x++;
    			}
    			else
    			{
    				y--;
    			}
    		}
    		
    		res.push_back(f(x,y));
    	}

    	x = 7;
    	res.push_back(f(x,y));
    	y = 7;
    	res.push_back(f(x,y));
    }
    else if(N <= 56)
    {
    	for(int i = 0 ; i < 48 ; i++)
    	{
    		if(x%2==0)
    		{
    			if(y == 6)
    			{
    				x++;
    			}
    			else
    			{
    				y++;
    			}
    		}
    		else
    		{
    			if(y == 0)
    			{
    				x++;
    			}
    			else
    			{
    				y--;
    			}
    		}
    		
    		res.push_back(f(x,y));
    	}

    	N -= 48;

    	N--;

    	y++;

    	for(int i = 0 ; i < N ; i++)
    	{
    		res.push_back(f(x,y));
    		x--;
    	}

    	x = 7;

    	res.push_back(f(x,y));
    }
    else
    {
    	for(int i = 0 ; i < 53 ; i++)
    	{
    		if(x%2==0)
    		{
    			if(y == 7)
    			{
    				x++;
    			}
    			else
    			{
    				y++;
    			}
    		}
    		else
    		{
    			if(y == 0)
    			{
    				x++;
    			}
    			else
    			{
    				y--;
    			}
    		}
    		
    		res.push_back(f(x,y));
    	}

    	y+=2;
    	res.push_back(f(x,y));
    	y-=1;
    	res.push_back(f(x,y));
    	x++;

        N -= 55;

    	N--;

    	for(int i = 0 ; i < N ; i++)
    	{
    		res.push_back(f(x,y));
    		y--;
    	}

    	y = 7;
    	res.push_back(f(x,y));
    }

    for(auto x : res)
    {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}