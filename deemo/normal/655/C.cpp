#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n, k, p[MAXN];
string s;

bool ok(int mid){
	for (int i = 0; i < n; i++)
		if (s[i] == '0')
			if (p[min(n, i + mid + 1)] - p[i + 1] + p[i] - p[max(0, i - mid)] >= k)	return	true;
	return	false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++)	p[i + 1] = p[i] + bool(s[i] == '0');
	
	int b = 1, e = n, ret = n;
	while (b <= e){
		int mid = (b + e)/ 2;
		if (ok(mid))
			ret = mid, e = mid - 1;
		else
			b = mid + 1;
	}
	cout << ret << "\n";
	return	0;
}