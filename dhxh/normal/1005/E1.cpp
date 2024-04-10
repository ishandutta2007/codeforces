#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5; 

long long n, m;

long long a[maxn];

long long b[maxn];

int pos;

long long f[maxn * 2][2];

long long ans = 0;

int getn(int x){
	return x + maxn;
}

int main(){
	int i, j;
	int l, r;
	int tmp = 0;
	int t = 1;
	
	cin >> n >> m;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] < m){
			b[i] = -1;
		}else if(a[i] > m){
			b[i] = 1;
		}else{
			b[i] = 0;
			pos = i;
		}
	}
	
	for(i=pos;i>0;i--){
		tmp += b[i];
		f[getn(tmp)][t]++;
		t = !t;
	}
	
	tmp = 0;
	t = 1;
	
	for(i=pos;i<=n;i++){
		tmp += b[i];
		ans += f[getn(-tmp)][t];
		ans += f[getn(-tmp + 1)][!t];
		t = !t;
	}
	
	cout << ans << endl;
	
	return 0;
}