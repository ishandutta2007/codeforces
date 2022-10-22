#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n, m;
string s[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	pii a(-1, -1), b(-1, -1);
	for (int i = 0; a.F==-1 && i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == 'B'){
				a = {i, j};
				break;
			}
	for (int i = n-1; b.F == -1 && (~i); i--)
		for (int j = m-1; ~j; j--)
			if (s[i][j] == 'B'){
				b = {i, j};
				break;
			}
	pii c(a.F+b.F>>1, a.S+b.S>>1);
	cout << c.F+1 << " " << c.S+1 << endl;
	return 0;
}