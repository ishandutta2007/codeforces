#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 20;

int n, k, vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);

	int maxi = 1, ans = vec[0], b = 0;
	ll sum = 0;
	for (int i = 1; i < n; i++){
		sum += ll(i - b) * ll(vec[i] - vec[i - 1]);
		while (sum > k){
			sum -= vec[i] - vec[b];
			b++;
		}			
		if (maxi < (i - b + 1)){
			maxi = i - b + 1;
			ans = vec[i];
		}
	}
	cout << maxi << " " << ans << endl;
	return 0;
}