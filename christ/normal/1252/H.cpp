#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+2;
int c[MN][2];
int t[MN];
bool irrel[MN];
bool flip[MN];
void dfs (int cur) {
	if (t[cur] == 5) {
		flip[cur] = c[cur][0];
		return;
	}
	dfs(c[cur][0]); if (~c[cur][1]) dfs(c[cur][1]);
	if (t[cur] == 1) flip[cur] = flip[c[cur][1]] & flip[c[cur][0]];
	else if (t[cur] == 2) flip[cur] = flip[c[cur][0]] | flip[c[cur][1]];
	else if (t[cur] == 3) flip[cur] = flip[c[cur][0]] ^ flip[c[cur][1]];
	else flip[cur] = !flip[c[cur][0]];
}
void prop (int cur) {
	if (t[cur] == 5) return;
	if (irrel[cur] || (t[cur] == 1 && flip[c[cur][0]] == 0 && flip[c[cur][1]] == 0) || (t[cur] == 2 && flip[c[cur][0]] == 1 && flip[c[cur][1]] == 1)) {
		irrel[c[cur][0]] = 1;
		if (~c[cur][1]) irrel[c[cur][1]] = 1;
	}
	if ((t[cur] == 2 && flip[c[cur][0]] == 0 && flip[c[cur][1]] == 1) || (t[cur] == 1 && flip[c[cur][0]] == 1 && flip[c[cur][1]] == 0)) irrel[c[cur][0]] = 1; 
	if ((t[cur] == 2 && flip[c[cur][0]] == 1 && flip[c[cur][1]] == 0) || (t[cur] == 1 && flip[c[cur][0]] == 0 && flip[c[cur][1]] == 1)) irrel[c[cur][1]] = 1;  
	prop(c[cur][0]);
	if (~c[cur][1]) prop(c[cur][1]);
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	string s;
    int n,a,b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
		cin >> s >> a;
		if (s != "IN" && s != "NOT") cin >> b;
		else b = -1;
		c[i][0] = a; c[i][1] = b;
		if (s == "AND") t[i] = 1;
		else if (s == "OR") t[i] = 2;
		else if (s == "XOR") t[i] = 3;
		else if (s == "NOT") t[i] = 4;
		else t[i] = 5, assert(s == "IN"); 
	}
	dfs(1);
	prop(1);
	for (int i = 1; i <= n; i++) {
		if (t[i] == 5) putchar(flip[1]^(!irrel[i]+'0'));
	}
	putchar(10);
    return 0;
}