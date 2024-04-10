#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n;
int vec[MAXN];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	int ans = 0;
	for (int i = 0; i < n; i++){
		int t = 0;
		for (int j = i; j < n; j++){
			t ^= vec[j];
			ans = max(ans, t);
		}
	}
	cout << ans << endl;
	return 0;
}