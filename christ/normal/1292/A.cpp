
// Problem : A. NEKO's Maze Game
// Contest : Codeforces Round #614 (Div. 1)
// URL : https://codeforces.com/contest/1292/problem/0
// Memory Limit : 256.000000 MB 
// Time Limit : 1500.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int MN = 1e5+3;
bool bad[MN][3];
int main () {
	int n,q;
	scanf ("%d %d",&n,&q); int cntbad = 0;
	while (q--) {
		int x,y;
		scanf ("%d %d",&x,&y); swap(x,y);
		int ny = y==1?2:1;
		int mult = bad[x][y];
		bad[x][y] = !bad[x][y];
		cntbad += (mult?-1:1) * (bad[x][ny]+bad[x-1][ny]+bad[x+1][ny]);
		printf(cntbad?"No\n":"Yes\n");
	}
	return 0;
}