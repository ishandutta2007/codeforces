#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int LOG = 40;

int cnt[LOG * MAXN], sz;
int nxt[2][LOG * MAXN];

void insert(int x){
	int cur = 0;
	for (int i = 30; ~i; i--){
		bool z = ((x >> i) & 1);
		if (!nxt[z][cur])
			nxt[z][cur] = ++sz;
		cur = nxt[z][cur];
		cnt[cur]++;
	}
}

void remove(int x){
	int cur = 0;
	for (int i = 30; ~i; i--){
		bool z = ((x >> i) & 1);
		if (!nxt[z][cur])
			nxt[z][cur] = ++sz;
		cur = nxt[z][cur];
		cnt[cur]--;
	}
}

int get(int x){
	int cur = 0, ret = 0;
	for (int i = 30; ~i; i--){
		bool z = ((x >> i) & 1);
		if (cnt[nxt[!z][cur]])
			cur = nxt[!z][cur], ret |= 1<<i;
		else
			cur = nxt[z][cur];
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;	cin >> q;
	insert(0);
	while (q--){
		char type;	cin >> type;
		int x;	cin >> x;
		if (type == '+')
			insert(x);
		if (type == '-')
			remove(x);
		if (type == '?')
			cout << get(x) << "\n";
	}
	return 0;
}