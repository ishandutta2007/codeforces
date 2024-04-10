#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;
const int C = 30 +  2;

int n, a[MAXN], p[MAXN];
int tr[C*MAXN][2], cnt[C*MAXN], sz;

void insert(int x){
	int cur = 0;
	cnt[0]++;
	for (int i = 29; ~i; i--){
		int y = x>>i&1;
		if (!tr[cur][y])
			tr[cur][y] = ++sz;
		cur = tr[cur][y];
		cnt[cur]++;
	}
}

int go(int x){
	int cur = 0;
	int res = 0;
	for (int i = 29; ~i; i--){
		int y = x>>i&1, nxt;
		if (tr[cur][y] && cnt[tr[cur][y]])
			nxt = y;
		else
			nxt = !y, res |= 1<<i;
		cnt[cur]--;
		cur = tr[cur][nxt];
	}
	cnt[cur]--;
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++){
		cin >> p[i];
		insert(p[i]);
	}
	for (int i = 0; i < n; i++)
		cout << go(a[i]) << " ";
	cout << "\n";
	return 0;
}