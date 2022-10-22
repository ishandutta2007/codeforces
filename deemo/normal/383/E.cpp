//These photographs mean nothing To the poison that they take
//The angry river rises as we step into the rain..

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e4 + 10;
const int C = 24;

int n, z[MAXN], d[2][1<<C];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		string temp;	cin >> temp;
		for (char c:temp)
			z[i] |= 1<<int(c - 'a');
		d[0][z[i]]++;
	}

	bool cur = 0;
	for (int w = 0; w < C; w++, cur = !cur)
		for (int ms = 0; ms < (1<<C); ms++)
			if ((ms >> w) & 1)
				d[!cur][ms] = d[cur][ms ^ (1<<w)];
			else
				d[!cur][ms] = d[cur][ms] + d[cur][ms^(1<<w)];
	
	int ans = 0;
	for (int ms = 0; ms < (1<<C); ms++)
		ans ^= (n - d[cur][ms]) * (n - d[cur][ms]);
	cout << ans << "\n";
	return 0;
}