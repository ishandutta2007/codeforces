#include <bits/stdc++.h>
#define function dslgfldg
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<int> colour;

vector<vector<int> > glob;

struct Vertex{
	int f; int r; int x; int y; int necessary; int type;
};

vector<Vertex> snm;
int get(int v) {
	if (snm[v].f != v) snm[v].f = get(snm[v].f);
	return snm[v].f;
}

void change(int index) {
	if (index == -1) return;
	for (int i = 0; i < glob[index].size(); ++i) {
		int to = glob[index][i];
		colour[to] = 1 - colour[to];
	}
}

int combine(int a, int b) {
	if (b==-1) return a;
	if (a==-1) return b;
	for (int i = 0; i < glob[b].size(); ++i) {
		glob[a].push_back(glob[b][i]);
	}
	return a;
}

int get_size(int x) {
	if (x==-1) return 0;
	return glob[x].size();
}

int unite(int u, int v, bool equal_colours) {
	if (snm[u].r > snm[v].r) swap(u, v);
	snm[u].f = v;
	if (snm[u].r == snm[v].r) snm[v].r++;

	int A = get_size(snm[u].x) + get_size(snm[u].y);
	int B = get_size(snm[v].x) + get_size(snm[v].y);

	if (A <= B) {

		if (!equal_colours) {
			swap(snm[u].x, snm[u].y);
			change(snm[u].x);
			change(snm[u].y);
		}

		snm[v].x = combine(snm[v].x, snm[u].x);
		snm[v].y = combine(snm[v].y, snm[u].y);
	}

	else{

		if (!equal_colours) {
			swap(snm[v].x, snm[v].y);
			change(snm[v].x);
			change(snm[v].y);
		}

		snm[v].x = combine(snm[u].x, snm[v].x);
		snm[v].y = combine(snm[u].y, snm[v].y);

	}

	if (snm[u].necessary != -1) {
		snm[v].necessary = snm[u].necessary;
		snm[v].type = snm[u].type;
	}

	return v;
}

int function(int x) {
	int G = get(x);

	int A = get_size(snm[G].x), B = get_size(snm[G].y);

	//cout << A << " " << B << endl;

	if (snm[G].necessary == -1) return min(A, B);
	if (colour[snm[G].necessary] == snm[G].type) return B;
	return A; 
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	colour.assign(k, 0);

	vector<vector<int> > cover(n);

	int f = 0;
	for (int i = 0; i < k; ++i) {
		vector<int> t = {i};
		glob.push_back(t);
		snm.push_back({i, 1, glob.size() - 1, -1, -1, -1});
	}

	for (int i = 0; i < k; ++i) {
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			x--;
			cover[x].push_back(i);
		}
	}


	for (int i = 0; i < n; ++i) {
		if (cover[i].size() == 1) {
			int X = cover[i][0];
			f -= function(X);
			int G = get(X);
			snm[G].necessary = X, snm[G].type = 1 - (s[i] - '0');
			f += function(X);
		}
		else if (cover[i].size() == 2) {
			int X = cover[i][0], Y = cover[i][1];
			int a = get(X), b = get(Y);
			if (a != b) {
				f -= function(a);
				f -= function(b);

				int A = colour[X] ^ colour[Y];

				unite(a, b, (s[i] - '0') ^ A);

				//cout << " == " << function(a) << endl;

				f += function(a);
			}
		}
		cout << f << "\n";
		//if (i==0) exit(0);
		//cout << i << endl;
	}

}