#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int C = 32;

int q, tr[MAXN*C][2], cnt[MAXN*C], sz;

void insert(int x){
	int cur = 0;
	for (int w = 29; ~w; w--){
		if (!tr[cur][x>>w&1])
			tr[cur][x>>w&1] = ++sz;
		cur = tr[cur][x>>w&1];
		cnt[cur]++;
	}
}

void erase(int x){
	int cur = 0;
	for (int w = 29; ~w; w--){
		cur = tr[cur][x>>w&1];
		cnt[cur]--;
	}
}

int get(int x, int y){
	int ret = 0, cur = 0;
	for (int w = 29; ~w; w--){
		int yy = y>>w&1;
		int xx = x>>w&1;
		int z = xx^yy;
		
		if (yy)
			ret += cnt[tr[cur][!z]];
		cur = tr[cur][z];
		if (!cur) break;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	while (q--){
		int type; cin >> type;
		if (type == 1){
			int x;	cin >> x;
			insert(x);
		}
		else if (type == 2){
			int x;	cin >> x;
			erase(x);
		}
		else{
			int x, y; cin >> x >> y;
			cout << get(x, y) << "\n";
		}
	}
	return 0;
}