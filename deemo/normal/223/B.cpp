#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 2e5;
const int C = 26;

int n, m;
string s, t;
bool seg[C + 1][4 * (MAXN + 5)];
int le[MAXN], ri[MAXN];

void init(){
	int cur = 0;
	n = s.size();
	m = t.size();
	for (int i = 0; i < n; i++){
		if (cur != m && s[i] == t[cur])	cur++;
		le[i + 1] = cur;
	}

	cur = m - 1;
	for (int i = n - 1; i >= 0; i--){
		if (cur >= 0 && s[i] == t[cur])	cur--;
		ri[i] = ((m - 1) - cur);
	}
}

void build(int v, int b, int e){
	if (e - b == 1){
		seg[t[b] - 'a'][v] = 1;
		return;
	}

	int mid = (b + e)/ 2;
	build(v<<1, b, mid);
	build(v<<1^1, mid, e);
	for (int i = 0; i < C; i++)
		seg[i][v] = seg[i][v<<1] | seg[i][v<<1^1];
}

bool exs(int v, int b, int e, int l, int r, int x){
	if (l <= b && e <= r)	return	seg[x][v];
	if (r <= b || e <= l)	return	0;

	int mid = (b + e)/ 2;
	return	exs(v<<1, b, mid, l, r, x) | exs(v<<1^1, mid, e, l, r, x);
}

bool ok(int ind){
	int r = min(le[ind], m - 1), l = max(0, m - ri[ind + 1] - 1);
	r++;
	if (l >= r)	return	false;
	return	exs(1, 0, m, l, r, s[ind] - 'a');
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	init();
	build(1, 0, m);

	bool fl = 0;
	for (int i = 0; i < (int)s.size(); i++)
		fl |= !ok(i);
	if (fl)
		cout << "No\n";
	else
		cout << "Yes\n";
	return 0;
}