#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e4 + 10;

int n, m, mn, mx, vec[MAXN];

int main(){
	cin >> n >> m >> mn >> mx;
	for (int i = 0; i < m; i++)	cin >> vec[i];
	sort(vec, vec + m);
	int need = 0;
	if (vec[0] != mn)	need++;
	if (vec[m - 1] != mx)	need++;
	if (need <= n - m && vec[0] >= mn && vec[m - 1] <= mx)
		cout << "Correct\n";
	else
		cout << "Incorrect\n";
	return	0;
}