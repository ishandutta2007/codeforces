#include<bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
string a[N];
int t[N];
int n, m;
void work(int p, int l, int r){
	if(l >= r) return;
	sort(t + l, t + r + 1, [&](int x, int y){
		if(p & 1) return a[x][p] > a[y][p];
		else return a[x][p] < a[y][p];
	});
	for(int L = l, R; L <= r; L = R + 1){
		R = L;
		while(R != r && a[t[R + 1]][p] == a[t[R]][p]) R++;
		work(p + 1, L, R);
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) t[i] = i;
	work(0, 0, n - 1);
	for(int i = 0; i < n; i++) cout << t[i] + 1 << " \n"[i == n - 1];
	return 0;
}