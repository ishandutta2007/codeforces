#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <cstring>
#include <stdio.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, int> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<LD> VLD;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PDD> VPDD;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next
#define prev fake_prev
#define left fake_left
#define right fake_right

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i,0,t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-4;
const LL INF = 1e7 - 1;
const LL mod = 1000000007;
const LL LINF = 1e18 + 10;
const int MAXN = 100001;
const int MAXK = 101;

struct project
{
	string nazva;// 
	int version;//
	int cnt;//   
	int index = -1;// -      
	char name[10];//   
	vector<project> G;//   

	void just_this()//   
	{
		cnt = 0;
		char ch;
		while (ch = getchar())//  ' '  '\n'
		{
			if (ch >= 'a' && ch <= 'z')
				name[cnt++] = ch;
			else
			{
				if (cnt)
					break;
			}
		}
		
		nazva.clear();
		FOR(i, 0, cnt)
			nazva += name[i];// 

		scanf("%d", &version);
	}

	void read()
	{
		just_this();
		int x;
		scanf("%d", &x);	// 
		project pr;
		FOR(i, 0, x)
		{
			pr.just_this();
			G.push_back(pr);
		}
	}
};

int N;
project A[MAXN];//  
int dist[MAXN];// 
char used[MAXN];// 
vector<project> ANS;//,    ?
map<pair<int, string>, int> mp;//  -   (   )
map<string, int> best;// ,      
VI levels[MAXN];//  

VI solve(VI curr_level)//     
{
	map<string, int> ok;
	for (auto i : curr_level)
	{
		if (A[i].nazva == A[0].nazva)
			continue;

		if (best[A[i].nazva])
			continue;

		int now = ok[A[i].nazva];
		if (now == 0)
			ok[A[i].nazva] = i;
		else
		{
			if (A[now].version < A[i].version)
				ok[A[i].nazva] = i;
		}
	}

	VI res;
	for (auto i : ok)
		res.push_back(i.Y), best[i.X] = i.Y;

	return res;
}

void bfs()// - ()
{
	FILL(used, 0);
	FILL(dist, 0);
	queue<int> q;
	q.push(0);
	used[0] = 1;
	int curr = 1;
	VI level;
	int iter = 1;
	while (!q.empty())
	{
		while (!q.empty())
		{
			int t = q.front();
			q.pop();
			FOR(x, 0, SZ(A[t].G))
			{
				int i = A[t].G[x].index;
				if (used[i] == 0)
					level.push_back(i);
			}
		}

		if (SZ(level) == 0)//  
			continue;

		level = solve(level);//    
		for (auto i : level)
		{
			used[i] = 1;
			dist[i] = iter;
			q.push(i);
		}

		level.clear();
		++iter;
	}
}

int comp(project x, project y)//  
{
	int mi = min(x.cnt, y.cnt);
	FOR(i, 0, mi)
		if (x.name[i] > y.name[i])
			return 0;
		else
			if (x.name[i] < y.name[i])
				return 1;

	return x.cnt < y.cnt;
}

int main()
{
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	scanf("%d", &N);
	FOR(i, 0, N)
	{
		A[i].read();
		A[i].index = i;
		mp[MP(A[i].version, A[i].nazva)] = i;//          
	}

	FOR(i, 0, N)
	{
		for (auto& pr : A[i].G)
			pr.index = mp[MP(pr.version, pr.nazva)];//   
	}

	bfs();//
	for (auto i : best)
		ANS.push_back(A[i.Y]);

	sort(ALL(ANS), comp);
	cout << SZ(ANS) << endl;
	FOR(i, 0, SZ(ANS))
	{
		FOR(j, 0, ANS[i].cnt)
			printf("%c", ANS[i].name[j]);

		printf(" %d\n", ANS[i].version);		
	}

	return 0;
}