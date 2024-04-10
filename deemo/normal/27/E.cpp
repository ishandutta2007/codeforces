#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 10;
const ll INF = 2e18;

ll sec[MAXN], sz;
int n;
ll d[MAXN][MAXN];

bool pr(int x){
	if (x < 2)	return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)	return false;
	return true;
}

int main(){
	for (int i = 2; i < 2000; i++)
		if (pr(i))	sec[sz++] = i;
	
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)	d[i][j] = INF;

	d[0][1] = 1;
	for (int i = 0; i < sz; i++){
		for (int j = 1; j < MAXN; j++)
			if (d[i][j]){
				ll z = d[i][j], x = 1;
				while (1){
					if (j * x >= MAXN)	break;
					d[i + 1][j * x] = min(d[i + 1][j * x], z);
					if (INF/ z < sec[i])	break;
					z *= sec[i];
					x++;
				}
			}
	}
	
	cin >> n;
	cout << d[sz][n] << endl;
	return 0;
}