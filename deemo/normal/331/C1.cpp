#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e6 + 10;

int n, d[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	d[0] = 0;
	for (int i = 1; i <= n; i++){
		int tx = i;
		d[i] = 1e9;
		while (tx){
			d[i] = min(d[i], d[i - tx % 10] + 1);
			tx /= 10;
		}
	}
	cout << d[n] << "\n";
	return	0;	
}