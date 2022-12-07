#include<bits/stdc++.h>

using namespace std;

short D[501][501][501], PI[500], RPI[500][2];
string s, t;

void getPI(const string& s)
{
	int N = s.size(), j = 0;
	for (int i = 1; i < N; i++) {
		while (j && s[i] != s[j]) j = PI[j - 1];
		if (s[i] == s[j]) PI[i] = ++j;
	}
}

int get_pos(int p, char v)
{
	if (p == 0 || t[p] == v) return RPI[p][v - '0'] = p;
	if (RPI[p][v - '0'] > -1) return RPI[p][v - '0'];
	return RPI[p][v - '0'] = get_pos(PI[p - 1], v);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, M, m, v;
	cin >> N >> M >> s >> t; getPI(t); memset(RPI, -1, sizeof(RPI));
	memset(D, 0x7f, sizeof(D));
	if (s[0] == t[0]) {
		if (M == 1) D[0][0][1] = 0;
		else D[0][1][0] = 0;
		D[0][0][0] = 1;
	}
	else {
		if (M == 1) D[0][0][1] = 1;
		else D[0][1][0] = 1;
		D[0][0][0] = 0;
	}
	for (int i = 1; i < N; i++) for (int j = 0; j <= i; j++) for (int k = 0; k <= i; k++) if ((m = D[i - 1][j][k]) <= N) {
		v = j;
		if (v && s[i] != t[v]) v = get_pos(v, s[i]);
		if (s[i] == t[v]) {
			if (++v == M) D[i][PI[M - 1]][k + 1] = min(D[i][PI[M - 1]][k + 1], (short)m);
			else D[i][v][k] = min(D[i][v][k], (short)m);
		}
		else D[i][v][k] = min(D[i][v][k], (short)m);
		v = j;
		if (v && s[i] == t[v]) v = get_pos(v, '1' - s[i] + '0');
		if (s[i] != t[v]) {
			if (++v == M) D[i][PI[M - 1]][k + 1] = min(D[i][PI[M - 1]][k + 1], (short)(m + 1));
			else D[i][v][k] = min(D[i][v][k], (short)(m + 1));
		}
		else D[i][v][k] = min(D[i][v][k], (short)(m + 1));
	}
	for (int i = 0; i < N - M + 2; i++) {
		m = N + M;
		for (int j = 0; j < M; j++) m = min((short)m, D[N - 1][j][i]);
		cout << (m <= N ? m : -1) << ' ';
	}
	return 0;
}