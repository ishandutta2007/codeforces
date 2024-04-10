#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const int MAXN = 5e5 + 10;
const int MAGIC = 40;

int q, n, par[MAXN];
ld p[MAGIC][MAXN];

void go(int v, int u, int cur = 0){
	if (cur == MAGIC)	return;
	if (v == -1)	return;
	go(par[v], v, cur + 1);
	
	if (~v)
		for (int w = 1; w < MAGIC; w++)
			p[w][v] /= (0.5 + 0.5 * p[w - 1][u]);
}

int main(){
	//cout << sizeof(p) << endl;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	cin >> q;
	for (int i = 0; i < MAGIC; i++)	p[i][0] = 1;
	par[n++] = -1;

	for (int i = 1; i <= q; i++){
		int type;	cin >> type;
		if (type - 1){
			int v;	cin >> v, v--;
			ld ans = 0;
			for (int h = 1; h < MAGIC; h++)
				ans += (p[h][v] - p[h - 1][v]) * h;
			cout << ans << "\n";
		}
		else{
			int v = n++;
			cin >> par[v], par[v]--;
			for (int h = 0; h < MAGIC; h++)	p[h][v] = 1;

			int tt = v;
			int u = v;
			v = par[v];
			go(v, u);

			v = tt;
			u = v;
			v = par[v];
			for (int j = 0; ~v && j < MAGIC; j++){
				if (j == 0)
					p[0][v] *= 0.5;
				else
					for (int w = 1; w < MAGIC; w++)
						p[w][v] *= (0.5 + 0.5 * p[w - 1][u]);

				u = v;
				v = par[v];
			}
		}
	}
	return 0;
}