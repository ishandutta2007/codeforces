#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 20;

int vec[MAXN], mark[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);

	int q;	cin >> q;
	ll sum = 0;
	int sz = 0;
	vec[sz++] = 0;
	while (q--){
		int type;	cin >> type;
		if (type == 1){
			int t, x;	cin >> t >> x;
			mark[t - 1] += x;
			sum += x * t;
		}
		else if (type == 2){
			int x;	cin >> x;
			vec[sz++] = x;
			sum += x;
		}
		else{
			int x = vec[sz - 1] + mark[sz - 1];
			mark[sz - 2] += mark[sz - 1];
			mark[sz - 1] = 0;
			sum -= x;
			sz--;
		}
		cout << double(sum)/(double)sz << "\n";
	}

	return 0;
}