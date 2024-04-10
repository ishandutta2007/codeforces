//Sometimes love is not enough and the road gets tough i don't know why..

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;

const int max_n = 3e2 + 100;

int n;
int x[max_n], y[max_n];
ld dis[max_n][max_n];

ll gc(int i, int j, int k){
	return	((x[j] - x[i]) * (y[k] - y[i]) - (y[j] - y[i]) * (x[k] - x[i]));
}

ld get(int a, int b){
	return	sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

ld cal(int i, int j, int k){
	ld p = dis[i][j] + dis[j][k] + dis[i][k];
	p /= 2.0;
	ld temp = p;
	p *= (temp - dis[i][j]);
	p *= (temp - dis[j][k]);
	p *= (temp - dis[i][k]);
	return	sqrt(p);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(8);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dis[i][j] = get(i, j);

	ld maxi = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			if (i == j)	continue;

			ld m1 = 0, m2 = 0;
			for (int k = 0; k < n; k++){
				if (i == k || j == k)	continue;
				int t = gc(i, j, k);
				if (t > 0)
					m1 = max(m1, cal(i, j, k));
				else
					m2 = max(m2, cal(i, j, k));
			}
			if (m1 == 0 || m2 == 0)	continue;
			maxi = max(maxi, m1 + m2);
		}
	cout << maxi << endl;
	return 0;
}