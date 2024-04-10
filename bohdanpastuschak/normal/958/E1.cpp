#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-6;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 2e5 + 47;
int R , B;
struct pt{
	int x , y;
};
pt p1[10] , p2[10];
int permut[10];
 
inline int area (pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
inline bool intersect_1 (int a, int b, int c, int d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
bool intersect (pt a, pt b, pt c, pt d) {
	return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& area(a,b,c) * area(a,b,d) <= 0
		&& area(c,d,a) * area(c,d,b) <= 0;
}
int bad[10][10][10][10];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	cin >> R >> B;
	if(R != B)
	{
		cout << "No";
		return 0;
	}
	for(int i = 0; i < R; i++)
	{
		cin >> p1[i].x >> p1[i].y;
	}
	for(int i = 0; i < B; i++)
	{
		cin >> p2[i].x >> p2[i].y;
	}
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < R; j++)
		{
			for(int k = 0; k < R; k++)
			{
				for(int l = 0; l < R; l++)
				{
					bad[i][j][k][l] = intersect(p1[i] , p2[j] , p1[k] , p2[l]);
				}
			}
		}	
	}
	for(int i = 0; i < R; i++)
		permut[i] = i;
	do
	{
		bool good = true;
		for(int i = 0; i < B && good; i++)
		{
			for(int j = i + 1; j < B && good; j++)
			{
				if(bad[i][permut[i]][j][permut[j]])
				{
					good = false;
				}
			}
		}
		if(good)
		{
			cout << "Yes";
			return 0;
		}
	}while(next_permutation(permut , permut + R));
	cout << "No";
	return 0;
}