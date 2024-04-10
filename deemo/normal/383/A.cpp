#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 2e5 + 20;

int n;
int vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int c1 = 0, c0 = 0;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		if (vec[i] == 0)	c0++;
		else	c1++;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++){
		if (vec[i] == 1)
			ans += c0;
		if (vec[i] == 1)	c1--;
		else	c0--;
	}
	cout << ans << endl;
	return 0;		
}