#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int a[105];
bool vis[605];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int ans = 0;
	cin >> n;
	
	for(i=1;i<=n;i++){
		a[i] = read();
		
		if(!vis[a[i]] and a[i] != 0){
			vis[a[i]] = true;
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}