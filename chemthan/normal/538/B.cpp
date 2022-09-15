#include <iostream>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

char n[7];

void solve()
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n;
	int l = strlen(n);
	int nresult = 0;
	int result[100];
	memset(result, 0, 100 * sizeof(int));
	while (1) {bool check = false; FOR(i, l) if (n[i] > '0') {result[nresult] = result[nresult] * 10 + 1; n[i]--; check = true;} else if (check) result[nresult] *= 10; if (!check) break; else nresult++;}
	cout<<nresult<<"\n"; FOR(i, nresult) cout<<result[i]<<" ";
}

int main()
{
	solve();
	return 0;
}