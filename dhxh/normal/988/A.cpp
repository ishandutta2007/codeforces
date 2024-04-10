#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

bool isc[105];
int ans[105];
int a[105];
int cnt = 0;
int n, k;


int main(){
	int i, j;
	
	cin >> n >> k;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(i=1;i<=n;i++){
		if(!isc[a[i]]){
			cnt++;
			ans[cnt] = i;
			isc[a[i]] = true;
		}
	}
	
	if(cnt >= k){
		cout << "YES" << endl;
		for(i=1;i<=k;i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}else{
		cout << "NO" << endl;
	}
	
	return 0;
}