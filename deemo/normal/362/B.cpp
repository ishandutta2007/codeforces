#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAXN = 3e3 + 30;

int n, m;
int c[MAXN];

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> c[i];
		if (c[i] == 1 || c[i] == n){
			cout << "NO\n";
			return 0;
		}
	}	
	sort(c, c + m);
	bool fl = 1;
	for (int i = 2; i < m; i++)
		if (c[i] == c[i - 1] + 1 && c[i - 1] == c[i - 2] + 1)
			fl = 0;
	if (fl)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}