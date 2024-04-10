#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;

int cnt = 0;

int ans[maxn][2];

int gcd(int x, int y){
	if(x % y){
		return gcd(y, x % y);
	}else{
		return y;
	}
}

int main(){
	int i, j;
	
	cin >> n >> m;
	
	if(m < n - 1){
		cout << "Impossible" << endl;
		return 0;
	}
	
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(gcd(i, j) == 1){
				cnt++;
				ans[cnt][0] = i;
				ans[cnt][1] = j;
				if(cnt == m){
					break;
				}
			}
		}
		if(cnt == m){
			break;
		}
	}
	
	if(m > cnt){
		cout << "Impossible" << endl;
	}else{
		cout << "Possible" << endl;
		for(i=1;i<=m;i++){
			cout << ans[i][0] << " " << ans[i][1] << endl;
		}
	}
	
	return 0;
}