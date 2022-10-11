#include<iostream>
#include<map>
#include<tuple>
using namespace std;
int n, t[1000], u[1000], v[1000][1000];
map<tuple<int, int, int, int>, int>M;
int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
void rec(int x, int y, int pos, int dir, int I) {
	if (I == n)return;
	if (M[make_tuple(x, y, pos, dir)] == 1)return;
	M[make_tuple(x, y, pos, dir)] = 1; v[x + u[n - 1]][y + u[n - 1]] = 1;
	if (pos != u[I]) {
		rec(x + dx[dir], y + dy[dir], pos + 1, dir, I);
	}
	if (pos == u[I]) {
		rec(x + dx[(dir + 7) % 8], y + dy[(dir + 7) % 8], pos + 1, (dir + 7) % 8, I + 1);
		rec(x + dx[(dir + 1) % 8], y + dy[(dir + 1) % 8], pos + 1, (dir + 1) % 8, I + 1);
	}
}
int main() {
	cin >> n; for (int i = 0; i < n; i++) { cin >> t[i]; u[i] = t[i]; }
	for (int i = 1; i < n; i++)u[i] += u[i - 1];
	rec(0, 0, 1, 0, 0);
	int cnt = 0; for (int i = 0; i < 1000000; i++)cnt += v[i / 1000][i % 1000];
	cout << cnt << endl;
	return 0;
}