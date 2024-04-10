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
int dp[6][12][201][201];
pair<int , pair<int , int> > p[6][12][201][201];
int zsuv = 5;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    //freopen("In.txt" , "r" , stdin);
    for(int i = 0; i < 6; i++)
    {
    	for(int diff = 0; diff <= 10; diff++)
		{
    		for(int j = 0; j <= 200; j++)
			{
				for(int k = 0; k <= 200; k++)
				{
					dp[i][diff][j][k] = 0;
				}
			}
		}
	}
	
	dp[0][5][0][0] = 1;
	int mns = -3;
	for(int i = 0; i < 5; i++)
	{
		for(int diff = zsuv - i; diff <= zsuv + i; diff++)
		{
			for(int j = 0; j <= 200; j++)
			{
				for(int k = 0; k <= 200; k++)
				{
					if(dp[i][diff][j][k] == 0 || (i >= 3 && ((diff == zsuv - (3 - mns)) || (diff == zsuv + (3 - mns)))))
						continue;
					int bound = 23 - 10 * (i == 4);
					for(int lScore = 0; lScore <= bound; lScore++)
					{
						if(j + bound + 2 <= 200 && k + lScore <= 200)
						{
							dp[i + 1][diff + 1][j + (bound + 2)][k + lScore] = 1;
							p[i + 1][diff + 1][j + (bound + 2)][k + lScore] = {diff , {j , k}};
						}
						if(k + bound + 2 <= 200 && j + lScore <= 200)
						{
							dp[i + 1][diff - 1][j + lScore][k + (bound + 2)] = 1;
							p[i + 1][diff - 1][j + lScore][k + (bound + 2)] = {diff , {j , k}};
						}
					}
					for(int smaller = bound + 1; smaller <= 200; smaller++)
					{
						if(k + smaller + 2 <= 200 && j + smaller <= 200)
						{
							dp[i + 1][diff - 1][j + smaller][k + (smaller + 2)] = 1;
							p[i + 1][diff - 1][j + smaller][k + (smaller + 2)] = {diff , {j , k}};
						}
						if(j + smaller + 2 <= 200 && k + smaller <= 200)
						{
							dp[i + 1][diff + 1][j + smaller + 2][k + smaller] = 1;
							p[i + 1][diff + 1][j + smaller + 2][k + smaller] = {diff , {j , k}};
						}
					}
				}
			}
		}
		mns++;
	}
	//cout << clock() / 1000000.0 << endl;
	int q;
	cin >> q;
	while(q--)
	{
		int a , b;
		cin >> a >> b;
		
		int bst = -100;
		int mns = 0;
		pair<int , int> wher;
		for(int i = 3; i <= 5; i++)
		{
			if(dp[i][zsuv - (3 - mns)][a][b])
			{
				if(zsuv - (3 - mns) > bst)
				{
					bst = zsuv - (3 - mns);
					wher = {i , bst};
				}
			}
			if(dp[i][zsuv + (3 - mns)][a][b])
			{
				if(zsuv + (3 - mns) > bst)
				{
					bst = zsuv + (3 - mns);
					wher = {i , bst};
				}
				
			}
			mns++;
		}
		if(bst == -100)
		{
			cout << "Impossible" << endl;
			continue;
		}
		bst -= 5;
		if(bst < 0)
		{
			cout << 3 + bst << ":3" << endl;
		}
		else
		{
			
			cout << "3:" << 3 - bst << endl;
		}
		bst += 5;
		int level = wher.X;
		pair<int , pair<int , int> > go = {bst , {a , b}}; 
		vector<pair<int , int> > v;
		while(level != 0)
		{
			pair<int , pair<int , int> > newGo;	
			newGo = p[level][go.X][go.Y.X][go.Y.Y];
			level--;
			
			int score1 = go.Y.X - newGo.Y.X;
			int score2 = go.Y.Y - newGo.Y.Y;
			v.PB({score1 , score2});
			//cout << score1 << ":" << score2 << " ";
			go = newGo;
		}
		reverse(v.begin() , v.end());
		for(int i = 0; i < v.size(); i++)
			cout << v[i].X << ":" << v[i].Y << " ";
		cout << endl;
		
	}
	return 0;
}