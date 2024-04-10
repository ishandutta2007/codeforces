#include <iostream>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) > (b) ? (b) : (a)

int n;
int a[100][100];
int nr;
bool r[100];

void solve()
{
	memset(r, true, 100);
	cin>>n;
	nr = n;
	FOR(i, n) FOR(j, n){
		cin>>a[i][j];
		if ((a[i][j] == 1 || a[i][j] == 3) && r[i]) {r[i] = false; nr--;}
		if ((a[i][j] == 2 || a[i][j] == 3) && r[j]) {r[j] = false; nr--;}
	}
	cout<<nr<<"\n";
	FOR(i, n) if (r[i]) cout<<i + 1<<" ";
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}