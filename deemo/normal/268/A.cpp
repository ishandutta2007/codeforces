#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 50;

int n;
int a[MAXN], b[MAXN];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i] >> b[i];
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			if (i == j)	continue;
			if (a[i] == b[j])	ans++;
		}
	cout << ans << endl;
	return 0;
}