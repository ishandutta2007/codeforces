#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(LL i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (LL)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = (LL)INF * INF;

int n;
vector<pair<char, int> > path;

int turns(PII x)
{
	if (x == MP(8, 8))
		return 0;
	if (x.X == 8 || x.Y == 8)
		return 1;
	return 2;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("In.txt" , "r" , stdin);
    
    cin >> n;    
    for(char x = 'a'; x <= 'h'; ++x)
    {
    	if ((x - 'a') & 1)
    		path.PB({x, 2}), path.PB({x, 1});
    	else
    		path.PB({x, 1}), path.PB({x, 2});	
    }
    
    for(char x = 'h'; x >= 'a'; --x)
    {
    	if (('h' - x) & 1)
    		path.PB({x, 4}), path.PB({x, 3});
    	else
    		path.PB({x, 3}), path.PB({x, 4});
    }
    
    for(char x = 'a'; x <= 'h'; ++x)
	{
		if ((x - 'a') & 1)
			path.PB({x, 6}), path.PB({x, 5});
		else
			path.PB({x, 5}), path.PB({x, 6});	
	}
	
	for(char x = 'h'; x >= 'a'; --x)
		path.PB({x, 7});
		
	for(char x = 'a'; x <= 'h'; ++x)
		path.PB({x, 8});
		
    vector<pair<char, int> > ans;
    int she = n;
    pair<char, int> zara = path[0];
    ans.PB(zara);
    int now = 1;
    
    while(1)
    {
    	if (she == 2)
    	{
    		if (zara == MP('h', 7))
    		{
    			ans.pop_back();
    			ans.pop_back();
    			ans.PB(zara);
    			ans.PB({'g', 7});
    			ans.PB({'g', 8});
    			ans.PB({'h', 8});
    			break;
    		}
    		
    		if (zara.X == 'h')
    		{
    			ans.PB({'h', 7});
    			ans.PB({'h', 8});
    			break;
    		}
    		
    		if (zara.Y == 8)
    		{
    			ans.PB({'g', 8});
    			ans.PB({'h', 8});
    		}
    		else
    		{
    			ans.PB({zara.X, 8});
    			ans.PB({'h', 8});
    		}
    		
    		break;	
    	}
    	
    	zara = path[now];    			
    	ans.PB(zara);
		--she;
		++now;
    }
            
    FOR(i, 0, n + 1)
    {
    	if (i)
    		cout << " ";
    	cout << ans[i].X << ans[i].Y;
    }
    cout << endl;
    
	return 0;
}