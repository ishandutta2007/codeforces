#include <iostream>
#include <math.h>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) > (b) ? (b) : (a)

int n;
char s[1001], t[1001];

void solve()
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n>>s>>t;
	int nMove = 0;
	FOR(i, n) nMove += MIN(abs(s[i] - t[i]), 10 - abs(s[i] - t[i]));
	cout<<nMove;
}

int main()
{
	solve();
	return 0;
}