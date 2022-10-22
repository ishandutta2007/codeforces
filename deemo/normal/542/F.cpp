#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXH = 100 + 2;

int n, T, t[MAXN], val[MAXN], p[MAXN], d[MAXH][MAXN];
vector<int>	vec[MAXH];

int main(){
	cin >> n >> T;
	for (int i = 0; i < n; i++){
		cin >> t[i] >> val[i], t[i] = T - t[i];
		vec[t[i]].push_back(val[i]);
	}
	for (int i = 0; i < MAXH; i++)
		sort(vec[i].begin(), vec[i].end(), greater<int>());

	d[0][0] = (vec[0].size()?vec[0][0]:0);
	d[0][1] = 0;
	int mx = d[0][0], tt = 1;
	for (int h = 1; h < MAXH; h++){
		int lt = tt;
		tt <<= 1;
		tt = min(tt, MAXN - 4);
		int sz = vec[h].size();
		for (int i = 0; i < sz; i++)
			p[i + 1] = p[i] + vec[h][i];
		for (int i = sz + 1; i < MAXN; i++)
			p[i] = p[i - 1];
		
		for (int i = tt; i >= 0; i--){
			d[h][i] = d[h][i + 1];
			int x = i/2 + bool(i % 2);
			while (x <= lt){
				d[h][i] = max(d[h][i], d[h - 1][x] + p[min(MAXN - 1, 2 * x - i)]);
				x++;	
			}
			mx = max(mx, d[h][i]);
		}
	}
	cout << mx << "\n";
	return	0;
}