#include <bits/stdc++.h>
#define INF 2147483647

using namespace std;

int main()
{
	int n, k;
	string s;
	int a[256] = {0};
	cin >> n >> k >> s;
	for(int i=0;i<s.size();i++)
		a[s[i]]++;
	int ans = INF;
	for(char c='A';c<'A'+k;c++) {
		ans = min(ans, a[c]);
	}
	cout << ans*k << endl;
}