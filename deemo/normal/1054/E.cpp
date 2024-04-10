#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 300 + 3;
const int XX = 1e5 + 10;

int n, m;
string s[2][MAXN][MAXN];
pair<pii, pii> ans[XX*4]; int sz;
bool fl;
int cnt[2][MAXN][2];

void move(int a, int b, int c, int d){
	ans[sz++] = {{a, b}, {c, d}};
}

void ref(int w){
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			if (make_pair(i, j) < make_pair(j, i))
				swap(s[w][i][j], s[w][j][i]);
}

void reflect(){
	ref(0);
	ref(1);

	fl = true;
	swap(n, m);
}

void showAns(){
	cout << sz << "\n";
	for (int i = 0; i < sz; i++){
		pii a = ans[i].F, b = ans[i].S;
		if (fl)
			swap(a.F, a.S), swap(b.F, b.S);
		cout << a.F+1 << " " << a.S+1 << " " << b.F+1 << " " << b.S+1 << "\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int sm = 0;
	for (int w = 0; w < 2; w++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) cin >> s[w][i][j], sm += s[w][i][j].size();
	if (max(n, m) == 2){
		for (int i = 0; i < s[0][0][0].size(); i++)
			ans[sz++] = {{0, 0}, {0, 1}};
		s[0][0][1] = s[0][0][0] + s[0][0][1];
		s[0][0][0] = "";

		for (int i = 0; i < s[0][1][1].size(); i++)
			ans[sz++] = {{1, 1}, {1, 0}};
		s[0][1][0] = s[0][1][1] + s[0][1][0];
		s[0][1][1] = "";

		while (s[0][0][1].size()){
			if (s[0][0][1].back() == '1'){
				s[0][0][1].pop_back();
				ans[sz++] = {{0, 1}, {1, 1}};
			}
			else {
				s[0][0][1].pop_back();
				ans[sz++] = {{0, 1}, {0, 0}};
			}
		}

		while (s[0][1][0].size()){
			if (s[0][1][0].back() == '1'){
				s[0][1][0].pop_back();
				ans[sz++] = {{1, 0}, {1, 1}};
			}
			else {
				s[0][1][0].pop_back();
				ans[sz++] = {{1, 0}, {0, 0}};
			}
		}

		for (int j = (int)s[1][0][0].size()-1; ~j; j--)
			if (s[1][0][0][j] == '0')
				move(0, 0, 0, 1);
			else
				move(1, 1, 0, 1);

		for (int j = (int)s[1][1][1].size()-1; ~j; j--)
			if (s[1][1][1][j] == '0')
				move(0, 0, 1, 0);
			else
				move(1, 1, 1, 0);

		for (int j = (int)s[1][0][1].size()-1; ~j; j--)
			if (s[1][0][1][j] == '0')
				move(0, 0, 0, 1);
			else
				move(1, 1, 0, 1);

		for (int j = (int)s[1][1][0].size()-1; ~j; j--)
			if (s[1][1][0][j] == '0')
				move(0, 0, 1, 0);
			else
				move(1, 1, 1, 0);

		for (int j = (int)s[1][0][0].size()-1; ~j; j--)
			move(0, 1, 0, 0);
		for (int j = (int)s[1][1][1].size()-1; ~j; j--)
			move(1, 0, 1, 1);
	}
	else{
		if (n > m)
			reflect();

		for (int w = 0; w < 2; w++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					for (char c:s[w][i][j])
						cnt[w][i][int(c-'0')]++;

		int req[2] = {0, 0};
		for (int i = 0; i < n; i++) {
			for (int j = 2; j < m; j++){
				reverse(s[0][i][j].begin(), s[0][i][j].end());
				for (char c:s[0][i][j])
					if (c == '0')
						move(i, j, i, 0);
					else
						move(i, j, i, 1);
				s[0][i][j] = "";
			}

			for (int j = 0; j < 2; j++){
				reverse(s[0][i][j].begin(), s[0][i][j].end());
				for (char c:s[0][i][j]){
					int cc = int(c - '0');
					if (cc != j)
						move(i, j, i, cc);
					else{
						if (cnt[0][i][cc] <= cnt[1][i][cc])
							move(i, j, i, 2), s[0][i][2] += c;
						else{
							while (cnt[0][req[cc]][cc] >= cnt[1][req[cc]][cc]) req[cc]++;
							move(i, j, req[cc], j);
							cnt[0][req[cc]][cc]++;
							cnt[0][i][cc]--;
						}
					}
				}
			}

			for (char c:s[0][i][2])
				move(i, 2, i, int(c-'0'));

			for (int j = 0; j < 2; j++)
				while (cnt[0][i][j] > cnt[1][i][j]){
					cnt[0][i][j]--;
					int cc = j;
					while (cnt[0][req[cc]][cc] >= cnt[1][req[cc]][cc]) req[cc]++;
					move(i, j, req[cc], j);
					cnt[0][req[cc]][cc]++;
				}
		}

		for (int i = 0; i < n; i++){
			for (int j = 0; j < 2; j++){
				reverse(s[1][i][j].begin(), s[1][i][j].end());
				for (char c:s[1][i][j]){
					int cc = int(c - '0');
					move(i, cc, i, 2);
				}
			}
			for (int j = 2; j < m; j++){
				reverse(s[1][i][j].begin(), s[1][i][j].end());
				for (char c:s[1][i][j]){
					int cc = int(c - '0');
					move(i, cc, i, j);
				}
			}
			for (int j = 0; j < 2; j++)
				for (int w = 0; w < s[1][i][j].size(); w++)
					move(i, 2, i, j);
		}
	}

	showAns();
	return 0;
}