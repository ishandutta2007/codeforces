#include <iostream>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

char str[101];
int a[101];

void solve()
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>str;
	int n = strlen(str);
	char banner[] = "CODEFORCES";
	FOR(i, 11) if (strncmp(banner, str, i) == 0 && strncmp(banner + i, str + n - (10 - i), 10 - i) == 0) {cout<<"YES"; return;}
	cout<<"NO";
}

int main()
{
	solve();
	return 0;
}