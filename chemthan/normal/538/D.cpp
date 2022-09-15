#include <iostream>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int n;
int a[50][50];
int vec[100][100];

void solve()
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	memset(vec, 0, 100 * 100 * sizeof(int));
	cin>>n;
	FOR(i, n){char str[51]; cin>>str; FOR(j, n) if (str[j] == '.') a[i][j] = 0; else if (str[j] == 'o') a[i][j] = 1; else a[i][j] = 2;}
	FOR(i, n) FOR(j, n) FOR(k, n) FOR(l, n) if (a[i][j] == 1 && a[k][l] == 0) vec[n - 1 + k - i][n - 1 + l - j] = 1;
	FOR(i, n) FOR(j, n) {
		if (a[i][j] == 2){
			bool check = false;
			FOR(k, n) FOR(l, n) if (a[k][l] == 1 && vec[n - 1 + i - k][n - 1 + j - l] == 0) {check = true; break;}
			if (!check) {cout<<"NO"; return;}
		}
	}
	cout<<"YES\n";
	FOR(i, 2 * n - 1) {FOR(j, 2 * n - 1) if (i == n - 1 && j == n - 1) cout<<"o"; else if (vec[i][j] == 0) cout<<"x"; else cout<<"."; cout<<"\n";}
}

int main()
{
	solve();
	return 0;
}