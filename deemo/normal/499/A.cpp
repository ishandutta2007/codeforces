#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXX = 1e5 + 10;

int n, x;
bool mark[MAXX];

int main(){
	cin >> n >> x;
	for (int i = 0; i < n; i++){
		int l, r;	cin >> l >> r;
		for (; l <= r; l++)
			mark[l] = 1;
	}

	int ans = 0;
	for (int i = 1; i < MAXX;){
		if (mark[i]){
			i++;
			ans++;
			continue;
		}
		int j = i;
		while (j < MAXX && !mark[j])	j++;
		if (j == MAXX)	break;
		ans += (j - i) % x;
		i = j;
	}
	cout << ans << "\n";
	return	0;
}