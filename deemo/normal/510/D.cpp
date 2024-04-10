#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 300 + 5;

int n, vec[MAXN], c[MAXN];
vector<int>	sec[MAXN];
int d[MAXN][1<<12];
int ans = 1e9, ms[MAXN];

void get(int ind){
	int x = vec[ind];
	for (ll i = 2; i * i <= vec[ind]; i++)
		if (vec[ind] % i == 0){
			sec[ind].push_back(i);
			while (vec[ind] % i == 0)
				vec[ind] /= i;
		}
	if (vec[ind] > 1)	sec[ind].push_back(vec[ind]);
	vec[ind] = x;
}

int cal(int ind){
	int sz = sec[ind].size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (1 << sz); j++)	
			d[i][j] = 1e9;
				
	for (int i = ind + 1; i < n; i++){
		ms[i] = 0;
		for (int j = 0; j < sz; j++)
			if (vec[i] % sec[ind][j])
				ms[i] |= 1 << j;
	}
	
	d[ind][0] = c[ind];
	for (int i = ind + 1; i < n; i++)
		for (int j = 0; j < (1<<sz); j++){
			d[i][j] = min(d[i][j], d[i - 1][j]);
			int s = j | ms[i];
			d[i][s] = min(d[i][s], d[i - 1][j] + c[i]);
		}	
	return	d[n - 1][(1<<sz) - 1];
}

int main(){
	cin >> n;	for (int i = 0; i < n; i++)	cin >> vec[i], get(i);	for (int i = 0; i < n; i++)	cin >> c[i];
	for (int i = 0; i < n; i++)
		ans = min(ans, cal(i));
	if (ans == 1e9)	ans = -1;
	cout << ans << endl;
	return	0;
}