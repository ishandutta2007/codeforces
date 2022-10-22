#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 20;

int n, p[MAXN], pos[MAXN], fen[MAXN];
bool ss[MAXN];

int get(int v){
	int ret = 0;
	for (; v; v -= v & (-v))
		ret += fen[v];
	return	ret;
}

void add(int v, int val){
	for (v++; v < MAXN; v += v & (-v))
		fen[v] += val;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> p[i];	p[i]--;
		pos[p[i]] = i;
	}
	for (int i = 0; i < n - 1; i++)
		if (pos[i + 1] < pos[i]){
			ss[i] = 1;
			add(i, 1);
		}
	int q;	cin >> q;
	while (q--){
		int type, x, y;	cin >> type >> x >> y;	x--, y--;
		if (type == 1)
			cout << get(y) - get(x) + 1 << "\n";
		else{
			swap(p[x], p[y]);
			int tx = x, ty = y;
			x = p[ty], y = p[tx];
			if (x && ss[x - 1])
				ss[x - 1] = 0, add(x - 1, -1);
			if (ss[y - 1])
				ss[y - 1] = 0, add(y - 1, -1);
			if (ss[x])	
				ss[x] = 0, add(x, -1);
			if (ss[y])
				ss[y] = 0, add(y, -1);
			
			swap(pos[x], pos[y]);
			for (int i = x - 1; i <= x; i++)
				if (0 <= i && i < n - 1 && pos[i + 1] < pos[i] && ss[i] == 0)
					ss[i] = 1, add(i, 1);
			for (int i = y - 1; i <= y; i++)
				if (0 <= i && i < n - 1 && pos[i + 1] < pos[i] && ss[i] == 0)
					ss[i] = 1, add(i, 1);

		}
	}
	return	0;
}