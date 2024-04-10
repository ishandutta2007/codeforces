#include <iostream>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
typedef long long ll;

int n, m, q;
int a[500][500];
int maxx[500];

void findmax(int i){
	int min = -1, max = -1, buf = 0;
	FOR(k, m){
		if (a[i][k] == 1){if (min == -1) min = k; max = k; if (k == m - 1) buf = MAX(buf, max - min + 1);}
		else {if (min > -1) buf = MAX(buf, max - min + 1); min = max = -1;}
	}
	maxx[i] = buf;
}

void solve(){
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n>>m>>q;
	memset(maxx, 0, sizeof(maxx));
	FOR(i, n) {FOR(j, m) cin>>a[i][j]; findmax(i);}
	FOR(i, q){
		int x, y; cin>>x>>y; x--; y--;
		a[x][y] = 1 - a[x][y];
		findmax(x);
		int buf = 0;
		FOR(i, n) buf = MAX(buf, maxx[i]);
		cout<<buf<<"\n";
	}
}

int main(){
	solve();
	return 0;
}