#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 3e5 + 5;

long long n, m;
long long x, y;

string tmp;

int a[maxn];

long long cnt = 0;

long long ans = 1e9 * maxn;

int main(){
	long long i, j;
	
	cin >> n >> x >> y;
	cin >> tmp;
	
	a[0] = tmp[0] - '0';
	m = 1;
	
	for(i=1;i<n;i++){
		if(tmp[i] != tmp[i - 1]){
			a[m] = tmp[i] - '0';
			m++;
		}
	}
	
	for(i=0;i<m;i++){
		if(a[i] == 0){
			cnt++;
		}
	}
	
	if(cnt == 0){
		cout << 0 << endl;
		return 0;
	}
	
	for(i=0;i<cnt;i++){
		ans = min(ans, i * x + (cnt - i) * y);
	}
	
	cout << ans << endl;
	
	return 0;
}