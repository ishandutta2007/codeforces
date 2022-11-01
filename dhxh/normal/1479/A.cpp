#include <bits/stdc++.h>

using namespace std;

int n, m, t;

int query(int x){
	cout << "? " << x << endl;
	cin >> x;
	return x;
}

int main(){
	ios::sync_with_stdio(false);
	int i, j;
	
	cin >> n;
	
	int l = 1, r = n;
	
	int x = query(l), y = query(r);
	
	if(x == 1){
		cout << "! " << l << endl;
		return 0;
	}
	
	if(y == 1){
		cout << "! " << r << endl;
		return 0;
	}
	
	while(l + 2 < r){
		int mid = (l + r) / 2;
		
		if(query(mid) < query(mid + 1)){
			r = mid + 1;
		}else{
			l = mid;
		}
	}
	
	for(i=max(l-1,1);i<=min(r+1,n);i++){
		int x, m, y;
		if(i - 1) x = query(i - 1);
		else x = n + 100;
		m = query(i);
		if(i + 1 <= n) y = query(i + 1);
		else y = n + 100;
		
		if(x > m and m < y){
			cout << "! " << i << endl;
			return 0;
		}
	}

	return 0;
}