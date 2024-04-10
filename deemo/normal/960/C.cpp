#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e4 + 10;

int X, d;
int n;
ll a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> X >> d;
	ll cur = 1;
	while (X){
		int cnt = 1;
		while ((1ll<<cnt+1)-1 <= X) cnt++;
		X -= (1ll<<cnt)-1;
		while (cnt--) a[n++] = cur;
		cur += d+1;
	}

	cout << n << "\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}