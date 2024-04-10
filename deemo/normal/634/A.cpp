#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 2e5 + 10;

int n;
vector<int>	a, b;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++)	cin >> b[i];
	for (int i = 0; i < n; i++)
		if (a[i] == 0){
			a.erase(a.begin() + i);
			break;
		}
	for (int i = 0; i < n; i++)
		if (b[i] == 0){
			b.erase(b.begin() + i);
			break;
		}

	int ind = 0;
	n--;
	for (int j = 0; j < n; j++)
		if (a[j] == b[0])	ind = j;
	bool fl = 0;
	int cur = 0;
	for (; cur < n; cur++)
		if (b[cur] != a[(ind + cur) % n])	fl = 1;
	if (!fl)
		cout << "YES\n";
	else
		cout << "NO\n";
	return	0;
}