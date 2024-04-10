#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n, k, p[MAXN];
string s;

bool ok(int mid){
	for (int i = 0; i + mid <= n; i++)
		if (min(p[i + mid] - p[i], mid - (p[i + mid] - p[i])) <= k)	return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k; 
	cin >> s;
	for (int i = 0; i < n; i++)
		p[i + 1] = p[i] + (s[i] == 'a');

	int b = 0, e = n, ret = 0;
	while (b <= e){
		int mid = (b + e)>>1;
		if (ok(mid))
			ret = mid, b = mid + 1;
		else
			e = mid - 1;
	}
	cout << ret << endl;
	return 0;
}