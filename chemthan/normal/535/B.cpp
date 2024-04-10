#include <iostream>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

char n[10];

void solve()
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n;
	int l = strlen(n);
	int pow = 1;
	int result = 0;
	FOR(i, l){result += (n[l - i - 1] == '4' ? 0 : 1) * pow; pow *= 2;}
	cout<<result + pow - 1;
}

int main()
{
	solve();
	return 0;
}