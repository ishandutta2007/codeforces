#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 2e6 + 10;

vector<int>	vec, sec[MAXN];

int main(){
	int sum, lim;	cin >> sum >> lim;
	for (int i = 1; i <= lim; i++){
		int z = 0;
		for (int j = 0; j < 20; j++)
			if ((i >> j) & 1){
				z = j;
				break;
			}
		z = 1 << z;
		sec[z].push_back(i);
	}

	int b = 1 << 20;
	for (int i = 1 << 20; i >= 1; i >>= 1){
		if ((i & sum) == 0)	continue;

		int z = 0;
		while (b && z < i){
			if (z + b > i || sec[b].size() == 0){
				b--;
				continue;
			}
			z += b;
			vec.push_back(sec[b].back());
			sec[b].pop_back();
		}
		if (i != z){
			cout << -1 << endl;
			return	0;
		}
	}


	cout << vec.size() << endl;
	for (int v:vec)
		cout << v << " ";
	cout << endl;
	return 0;
}