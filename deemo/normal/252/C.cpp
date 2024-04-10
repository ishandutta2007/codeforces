#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAXN = 1e5 + 20;

int n, d;
int vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	

	int e = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++){
		e = max(e, i);
		while (e < n && vec[e] - vec[i] <= d)	e++;
		if (e - i >= 3){
			long long z = e - i - 2;
			ans += z * (z + 1) / 2;
		}
	}
	cout << ans << endl;
	return 0;
}