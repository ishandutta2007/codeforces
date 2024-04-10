#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m = 1;

int a[maxn];

int b[maxn];
int c[maxn];

int ans = 0;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	int i, j;
	int t = 1;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1, cmp);
	
	b[1] = a[1];
	c[1] = 1;
	
	for(i=2;i<=n;i++){
		if(a[i] == a[i - 1]){
			c[m]++;
		}else{
			m++;
			b[m] = a[i];
			c[m] = 1;
		}
	}
	
	t = c[1];
	
	for(i=2;i<=m;i++){
		if(t >= c[i]){
			ans += c[i];
		}else{
			ans += t;
			t = c[i];
		}
	}
	
	cout << ans << endl;
	
	return 0;
}