
//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = 200002;

int s[N], g[N], l[N], r[N], res[N];

int main()
{
	int n = in();
	for(int i = 0; i < n; i++)
		cin >> s[i] >> g[i];
	l[0] = s[0] + g[0];
	for(int i = 1; i < n; i++)
		l[i] = min(s[i] + g[i], l[i - 1] + 1);
	r[n - 1] = s[n - 1] + g[n - 1];
	for(int i = n - 2; i >= 0; i--)
		r[i] = min(r[i + 1] + 1, s[i] + g[i]);
	long long tot = 0;
	for(int i = 0; i < n; i++)
	{
		res[i] = min(l[i], r[i]);
		if(res[i] < s[i])
		{
			cout << "-1\n";
			return 0;
		}
		tot += res[i] - s[i];
	}
	cout << tot << endl;
	for(int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}