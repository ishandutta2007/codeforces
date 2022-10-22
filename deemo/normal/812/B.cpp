#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 10;

int n, m, tl[MAXN], tr[MAXN];
string s[MAXN];

void smin(int &x, int y){x = min(x, y);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = n-1; ~i; i--){
		cin >> s[i];
		tl[i] = -1, tr[i] = m+10;
		for (int j = 0; j < m+2; j++)
			if (s[i][j] == '1'){
				tl[i] = j;
				break;
			}
		for (int j = m+2; ~j; j--)
			if (s[i][j] == '1'){
				tr[i] = j;
				break;
			}
	}

	int mx = -1;
	for (int i = 0; i < n; i++)
		if (tl[i] != -1)
			mx = i;
	if (mx == -1){
		cout << "0\n";
		return 0;
	}
	
	int a = 0, b = m+1;
	for (int i = 0; i < mx; i++){
		int c = 1e9, d = 1e9;
		if (tr[i] == m+10) smin(c, a+1);
		else smin(c, a+tr[i]*2+1);
		smin(d, a+m+2);

		if (tl[i] == -1) smin(d, b+1);
		else smin(d, b+(m+1-tl[i])*2+1);
		smin(c, b+m+2);
		a=c, b=d;
	}
	
	int ans = 1e9;
	smin(ans, a+tr[mx]);
	smin(ans, b+(m+1-tl[mx]));
	cout << ans << "\n";
	return 0;
}