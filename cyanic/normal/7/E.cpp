#include<bits/stdc++.h>
using namespace std;

const int maxn = 109;
map<string,int> f; string s;
int n, m; char t[maxn];

int F(int l, int r) {
	int L, R;
	for (int i=r,w=0; i>=l; i--) {
		w += (t[i] == '(');
		w -= (t[i] == ')');
		if (!w && (t[i] == '+' || t[i] == '-')) {
			L = F(l, i-1); R = F(i+1, r);
			if (L == 2 || R == 2) return 2;
			if (t[i] == '+') return 3;
			return R == 3 ? 2 : 3;
		}
	}
	for (int i=r,w=0; i>=l; i--) {
		w += (t[i] == '(');
		w -= (t[i] == ')');
		if (!w && (t[i] == '*' || t[i] == '/')) {
			L = F(l, i-1); R = F(i+1, r);
			if (L == 2 || R == 2) return 2;
			if (t[i] == '*') return L == 3 || R == 3 ? 2 : 4;
			return L == 3 || R == 3 || R == 4 ? 2 : 4;
		}
	}
	if (t[l] == '(') return F(l+1, r-1) != 2 ? 1 : 2;
	string tmp(t+l, t+r+1);
	return f[tmp] ? f[tmp] : 1;
}

int G() {
	gets(t); m = 0;
	for (int i=0; t[i]; i++)
		if (t[i] != ' ') t[m++] = t[i];
	t[m] = '\0';
	return F(0, m-1);
}

int main() {
	for (scanf("%d", &n); n; n--) {
		scanf(" #%*s"); cin >> s; f[s] = G();
	}
	puts(G() != 2 ? "OK" : "Suspicious");
	return 0;
}