#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

const int MAXK = 99 + 3;

int k, par[MAXK][MAXK], ss[MAXK][MAXK];
bool tt[MAXK][MAXK];

int get(int i, int j, int n){return par[i][j + n] - par[i][j];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;	cin >> q >> k;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)	ss[i][j] = abs(i - k/2) + abs(j - k/2);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			par[i][j + 1] = par[i][j] + ss[i][j];

	while (q--){
		int n;	cin >> n;
		pair<int, int>	p(-1, -1);
		int mn = 2e9;
		for (int i = 0; i < k; i++){
			for (int j = 0; j < k;){
				if (tt[i][j]){
					j++;
					continue;
				}

				int w = j;
				while (w < k && !tt[i][w])	w++;
				
				for (int z = j; z + n <= w; z++){
					int temp = get(i, z, n);
					if (temp < mn){
						mn = temp;
						p = {i, z};
					}		
				}
				j = w;
			}
		}
		if (p.first == -1)
			cout << "-1\n";
		else{
			cout << p.first + 1 << " " << p.second + 1 << " " << p.second + n << "\n";
			for (int j = p.second; j < p.second + n; j++)
				tt[p.first][j] = 1;
		}
	}
	return	0;
}