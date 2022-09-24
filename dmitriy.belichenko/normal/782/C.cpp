
#include<math.h>
#include<algorithm>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#define ull unsigned long long
#define ll long long
#define ld long double
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)

ull INF = 1e9 + 7;

using namespace std;

int st[200005];
vector<vector<int>> g(200005);
vector<int> used(200005);
int color[200005];

int ans = 0;

void dfs(int u, int c, int p)
{
	used[u] = c;
    ans = max(ans,c);
    color[u] = used[u];
	int cs = 1;
	for (int i = 0; i < g[u].size(); i++)
	{
	    if (!used[g[u][i]]){
            while (c == cs || p == cs)    cs++;
            dfs(g[u][i], cs, c), cs++;
	    }
	}
}
int main(){

    int n;
    cin >> n;

int res = 0;
    for(int i = 0;  i < n -1 ; i++)
   {
        int u , v;
     cin >> u >> v;
     u--;
     v--;
     st[u]++;
     st[v]++;


     g[u].push_back(v);
     g[v].push_back(u);
    }

    dfs(0, 1 ,0); cout << ans << endl;
    for(int i = 0; i < n; i++) cout << color[i] << " ";


}