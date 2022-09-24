#include <bits/stdc++.h>
using namespace std;

inline int in() { int x; scanf("%d", &x); return x; }
const int N = 202;

int a[N][N];

int main()
{
	int n = in(), d = in();
	int ans = 0, cur = 0;
	for(int i = 0; i < d; i++)
	{
		string s;
		cin >> s;
		bool iff = 0;
		for(int j = 0; j < n; j++)
			iff |= (s[j] == '0');
		if(iff)
			cur++;
		else
			cur = 0;
		ans = max(ans, cur);
	}
	cout << ans << endl;
}