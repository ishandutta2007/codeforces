#include <iostream>
#include <string>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int n;

void solve()
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n;
	string num[100] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve"};
	string prefix[100] = {"", "", "twen", "thir", "four", "fif", "six", "seven", "eigh", "nine"};
	string prefix2[100] = {"", "", "twen", "thir", "for", "fif", "six", "seven", "eigh", "nine"};
	if (n < 13) cout<<num[n];
	else if (n < 20) cout<<prefix[n % 10]<<"teen";
	else {cout<<prefix2[n / 10]<<"ty"; int r = n % 10; if (r > 0) cout<<"-"<<num[r];}
}

int main()
{
	solve();
	return 0;
}