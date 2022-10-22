#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 200 + 4;

int n, m;
string s[MAXN], t[MAXN];

void show(string ss){
	for (int i = 0; i < m; i++)
		cout << ss[i] << ss[i];
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++)	cin >> s[i];
	for (int i = 0; i < MAXN; i++)
		t[i].resize(MAXN);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			t[j][n - i - 1] = s[i][j];
	swap(n, m);
	for (int i = 0; i < n; i++)
		reverse(t[i].begin(), t[i].begin() + m);
	for (int i = 0; i < n; i++)
		show(t[i]), show(t[i]);
	return	0;
}