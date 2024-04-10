#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 2700;

int n, cnt[200], c[MAXN][MAXN], d[MAXN][MAXN];
string s, g;

void get(int l, int r, int nd){
	if (!nd)	return;
	if (d[l - 1][r] == nd)	get(l - 1, r, nd);
	else if (d[l][r - 1] == nd)	get(l, r - 1, nd);
	else{
		g += s[l - 1];
		get(l - 1, r - 1, nd - 2);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;	n = s.size();
	for (char c:s)
		cnt[c]++;
	for (int i = 'a'; i <= 'z'; i++)
		if (cnt[i] >= 100){
			for (int j = 0; j < 100; j++)
				cout << char(i);
			cout << "\n";
			return 0;
		}

	int mx = 1;
	for (int l = 1; l <= n; l++)
		for (int r = 1; r + l <= n; r++){
			d[l][r] = max({d[l][r], d[l - 1][r], d[l][r - 1]});
			if (s[l - 1] == s[n - r])
				d[l][r] = max(d[l][r], d[l - 1][r - 1] + 2);
			mx = max(mx, d[l][r]);
			c[l][r] = max(d[l - 1][r], d[l][r - 1]) + 1;
			mx = max(mx, c[l][r]);
		}
	if (mx == 1){
		cout << s[0] << "\n";
		return 0;
	}

	mx = min(mx, 100);
	for (int l = 1; l <= n; l++)
		for (int r = 1; r + l <= n; r++)
			if (d[l][r] == mx){
				get(l, r, mx);
				reverse(g.begin(), g.end());
				string t = g;
				reverse(t.begin(), t.end());
				g += t;
				cout << g << "\n";
				return 0;
			}
			else if (c[l][r] == mx){
				if (d[l - 1][r] == mx - 1){
					get(l - 1, r, mx - 1);
						reverse(g.begin(), g.end());
					string t = g;
					reverse(t.begin(), t.end());
					g += s[l - 1];
					g += t;
					cout << g << "\n";
				}
				else{
					get(l, r - 1, mx - 1);
					reverse(g.begin(), g.end());
					string t = g;
					reverse(t.begin(), t.end());
					g += s[n - r];
					g += t;
					cout << g << "\n";
				}
				return 0;
			}
	return 0;
}