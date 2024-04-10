#include <bits/stdc++.h>
#define data ghlfdkg
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;

int dst[5007][5007];
int n, m;

void bfs(int start) {
	vector<int> d(n,  1e9);

	d[start] = 0;
	queue<int> q;
	q.push(start);

	while (q.size()) {
		int W = q.front();
		q.pop();
		for (int i = 0; i < data[W].size(); ++i) {
			int to = data[W][i];
			if (d[W]+1 < d[to]) {
				d[to] = d[W]+1;
				q.push(to);
			}
		}
	}

	for (int i = 0; i < n; ++i) dst[start][i] = d[i];

}

int a, b, c, d = -1;
int q = -1;

void print() {
	cout << a+1 << " " << b+1 << " " << c+1 << endl;
	if (a==d || b==d || c==d) exit(0);
	q++;

}

void read() {
	cin >> d;
	d--;
	if (a==d || b==d || c==d) exit(0);
	assert(q < n);
}

void choice(vector<int> &pos) {

	for (int i = 0; i < 3; ++i) {
		pos[i] = data[d][rand()%data[d].size()];
	}
}

int main(){
#ifdef LOCAL
	//freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	srand(time(NULL));

	cin >> n >> m;

	data.assign(n, {});
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		data[u].push_back(v);
		data[v].push_back(u);
	}

	for (int i = 0; i < n; ++i) bfs(i);

	a = rand()%n, b = rand()%n, c = rand()%n;
	print();
	read();

	for (int i = 0; i < n; ++i) {


		vector<int> nm(3);
		choice(nm);

		if (dst[d][a] == 1 || dst[d][b] == 1 || dst[d][c] == 1) {
			nm = {d, d, d};
		}

		vector<int> sc = {a, b, c};

		for (int j = 0; j < 3; ++j) {
			int opt = 1e9, wh = -1;
			for (int e = 0; e < n; ++e) {
				if (dst[sc[j]][e] == 0 || dst[sc[j]][e] == 1) {
					if (dst[e][nm[j]] < opt) {
						wh = e;
						opt = dst[e][nm[j]];
					}
				}
			}

			//cout << nm[j] << " " << j << " " << opt << " " << wh << endl;

			nm[j] = wh;
		}
		a = nm[0], b = nm[1], c = nm[2];
		print() ;
		read();

	}



}