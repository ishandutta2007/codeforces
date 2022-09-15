#include <iostream>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) > (b) ? (b) : (a)

int n, m;
int a[100000];
int b[100000];

void solve()
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n>>m;
	FOR(i, m) {cin>>a[i]>>b[i]; a[i]--;}
	int maxh = 0;
	maxh = MAX(maxh, b[0] + a[0]);
	maxh = MAX(maxh, b[m - 1] + n - 1 - a[m - 1]);
	FOR(i, m - 1){
		if (abs(b[i + 1] - b[i]) > a[i + 1] - a[i]) {cout<<"IMPOSSIBLE"; return;}
		maxh = MAX(maxh, (MAX(b[i + 1], b[i])) + (a[i + 1] - a[i] - abs(b[i + 1] - b[i])) / 2);
	}
	cout<<maxh;
}

int main()
{
	solve();
	return 0;
}