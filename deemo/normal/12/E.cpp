#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e3 + 10;

int n, a[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			if (i == j)	
				cout << 0 << " ";
			else{
				if (i < n - 1 && j < n - 1)
					cout << (i + j) % (n - 1) + 1 << " ";
				else{
					if (i != n - 1)
						cout << (i + i) % (n - 1) + 1 << " ";
					else
						cout << (j + j) % (n - 1) + 1 << " ";
				}
			}
		cout << "\n";
	}
	return	0;
}