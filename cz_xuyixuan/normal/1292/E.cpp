#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
char s[MAXN]; int n, k;
void answer(int n) {
	cout << '!' << ' ';
	for (int i = 1; i <= n; i++)
		cout << s[i];
	cout << endl;
}
bool get(int v) {
	read(k); if (k == -1) exit(0);
	bool ans = false;
	while (k--) {
		int x; read(x);
		if (v == x) ans = true;
	}
	return ans;
}
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++)
			s[i] = 0;
		cout << '?' << ' ' << "CH" << endl;
		read(k); if (k == -1) exit(0);
		while (k--) {
			int x; read(x);
			s[x] = 'C', s[x + 1] = 'H';
		}
		cout << '?' << ' ' << "CO" << endl;
		read(k); if (k == -1) exit(0);
		while (k--) {
			int x; read(x);
			s[x] = 'C', s[x + 1] = 'O';
		}
		cout << '?' << ' ' << "HO" << endl;
		read(k); if (k == -1) exit(0);
		while (k--) {
			int x; read(x);
			s[x] = 'H', s[x + 1] = 'O';
		}
		cout << '?' << ' ' << "HC" << endl;
		read(k); if (k == -1) exit(0);
		while (k--) {
			int x; read(x);
			s[x] = 'H', s[x + 1] = 'C';
		}
		int l = 0, r = 0;
		for (int i = 1; i <= n; i++)
			if (s[i]) l = r = i;
		if (l == 0) {
			cout << '?' << ' ' << "CCC" << endl;
			read(k); if (k == -1) exit(0);
			while (k--) {
				int x; read(x);
				s[x] = s[x + 1] = s[x + 2] = 'C';
			}
			cout << '?' << ' ' << "HHH" << endl;
			read(k); if (k == -1) exit(0);
			while (k--) {
				int x; read(x);
				s[x] = s[x + 1] = s[x + 2] = 'H';
			}
			if (s[n]) {
				for (int i = 1; i <= n; i++)
					if (s[i] == 0) s[i] = 'O';
			} else {
				cout << '?' << ' ' << "OOO" << endl;
				read(k); if (k == -1) exit(0);
				while (k--) {
					int x; read(x);
					s[x] = s[x + 1] = s[x + 2] = 'O';
				}
				if (s[1]) {
					for (int i = 1; i <= n; i++)
						if (s[i] == 0) s[i] = 'C';
					cout << '?' << ' ';
					for (int i = 1; i <= n; i++)
						cout << s[i];
					cout << endl;
					if (!get(1)) {
						for (int i = 1; i <= n; i++)
							if (s[i] == 'C') s[i] = 'H';
					}
				} else {
					assert(n == 4);
					cout << "? OOCC" << endl;
					if (get(1)) s[1] = s[2] = 'O', s[3] = s[4] = 'C';
					else s[1] = s[2] = 'O', s[3] = s[4] = 'H';
				}
			}
		} else {
			while (l != 1 || r != n) {
				if (l > 1 && s[l - 1]) l--;
				else if (l > 1) {
					if (s[l] == 'C') {
						cout << '?' << ' ' << 'O';
						for (int i = l; i <= r; i++)
							cout << s[i];
						cout << endl;
						if (get(l - 1)) s[l - 1] = 'O';
						else s[l - 1] = 'C';
					} else if (s[l] == 'H') {
						cout << '?' << ' ' << 'O';
						for (int i = l; i <= r; i++)
							cout << s[i];
						cout << endl;
						if (get(l - 1)) s[l - 1] = 'O';
						else s[l - 1] = 'H';
					} else s[l - 1] = 'O';
					l--;
				} else {
					if (s[r] == 'O') {
						cout << '?' << ' ';
						for (int i = l; i <= r; i++)
							cout << s[i];
						cout << 'O' << endl;
						if (get(l)) s[r + 1] = 'O';
						else {
							cout << '?' << ' ';
							for (int i = l; i <= r; i++)
								cout << s[i];
							cout << 'C' << endl;
							if (get(l)) s[r + 1] = 'C';
							else s[r + 1] = 'H';
						}
					} else s[r + 1] = s[r];
					r++;
				}
			}
		}
		answer(n);
		int res; read(res);
		if (!res) exit(0);
	}
	return 0;
}