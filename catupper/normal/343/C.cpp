#include <iostream>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define INF (1LL << 60)
long long p[105000], h[105000], n, m;
bool check(long long x){
	int leftest = 0;
	for(int i = 0;i < n;i++){
		if(leftest == m)return true;
		if(p[leftest] >= h[i]){
			while(leftest < m && p[leftest] <= h[i] + x)leftest++;
		}
		else{
			long long dist = h[i] - p[leftest];
			if(dist > x)return false;
			long long tx = max((x - dist) / 2, x - dist * 2);
			while(leftest < m && p[leftest] <= h[i] + tx)leftest++;
		}
	}
	if(leftest < m)return false;
	return true;
}

int main() {
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> h[i];
	}bool zero = true;
	for(int i = 0;i < m;i++){
		cin >> p[i];
		if(*lower_bound(h, h + n, p[i]) != p[i])zero = false;
	}
	long long l = 0, r = INF;
	if(zero)r = 0;
	while(r - l > 1){
		long long mid = (l + r) / 2;
		if(check(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
	return 0;
}