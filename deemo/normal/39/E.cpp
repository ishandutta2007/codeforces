#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXA = 4e4 + 10;
const int MAXB = 30 + 2;

int a, b, n;
short d[MAXB][MAXA];

bool check(ll x, int y){
	ll temp = x;
	for (int i = 1; x < n && i < y; i++)
		x *= temp;
	return x >= n;
}

int main(){
	cin >> a >> b >> n;
	for (int j = MAXB - 1; ~j; j--)
		for (int i = MAXA - 1; ~i; i--){
			if (check(i, j))
				d[j][i] = 1;
			else{
				if (i == MAXA - 1){
					int dif = n - i;
					if (dif & 1)
						d[j][i] = 0;
					else
						d[j][i] = 1;
				}
				else if (j == MAXB - 1)
					d[j][i] = 2;
				else{
					if (!d[j][i + 1] || !d[j + 1][i])
						d[j][i] = 1;
					else if (d[j][i + 1] == 2 || d[j + 1][i] == 2)
						d[j][i] = 2;
					else
						d[j][i] = 0;
				}
			}
		}
	
	if (d[b][a] == 2)
		cout << "Missing\n";
	if (d[b][a] == 1)
		cout << "Masha\n";
	if (d[b][a] == 0)
		cout << "Stas\n";
	return 0;
}