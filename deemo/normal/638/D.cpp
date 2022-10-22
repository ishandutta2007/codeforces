#include<iostream>
#include<string>
#include<array>
using namespace std;
const int MAXN = 1e2 + 2;
int n, m, k;
bool del[MAXN][MAXN][MAXN];
bool fit(array<int, 3> p){return 0 <= p[0] && p[0] < n && 0 <= p[1] && p[1] < m && 0 <= p[2] && p[2] < k && !del[p[0]][p[1]][p[2]];}
bool access(array<int, 3> p1, array<int, 3> p2, array<int, 3> p3){
	if (p1 == p2)	return	true;
	for (int i = 0; i < 3; i++)
		if (p1[i] < p2[i]){
			auto tp = p1; tp[i]++;
			if (fit(tp) && tp != p3 && access(tp, p2, p3))	return	true;
		}
	return	false;
}
bool check(array<int, 3> p){
	for (int i = 0; i < 3; i++){
		auto tp = p; tp[i]++;
		if (fit(tp))
			for (int j = 0; j < 3; j++){
				auto sp = p; sp[j]--;
				if (fit(sp) && !access(sp, tp, p))	return	true;
			}
	}
	return	false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;	
	for (int i = 0; i < n; i++)	for (int j = 0; j < m; j++){string s;	cin >> s;	for (int w = 0; w < k; w++)	del[i][j][w] = s[w] != '1';}
	int ans = 0;	for (int i = 0; i < n; i++)	for (int j = 0; j < m; j++)	for (int w = 0; w < k; w++)	if (!del[i][j][w] && check({i, j, w}))	ans++;
	cout << ans << "\n";
	return	0;
}