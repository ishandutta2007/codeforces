#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 1e3 + 10;

int n, k, a, b, c, d, sec[MAXN], sz;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cin >> a >> b >> c >> d;
	if (n == 4){
		cout << "-1\n";
		return 0;
	}
	if (k < n + 1){
		cout << "-1\n";
		return 0;
	}
	
	for (int i = 1; i <= n; i++)	
		if (i != a && i != b && i != c && i != d)	sec[sz++] = i;
	cout << a << " " << c << " ";
	for (int i = 0; i < sz; i++)
		cout << sec[i] << " ";
	cout << d << " " << b << "\n";
	cout << c << " " << a << " ";
	for (int i = 0; i < sz; i++)
		cout << sec[i] << " ";
	cout << b << " " << d << "\n";
	return 0;
}