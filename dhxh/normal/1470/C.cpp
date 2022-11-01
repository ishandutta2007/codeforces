#include <bits/stdc++.h>

using namespace std;

int n, m, t;

int query(int x){
	cout << "? " << x << endl;
	cin >> x;
	return x;
}

void getans(int l, int r){
	int i, x;
	for(i=l;i<r;i++){
		if(i <= n) x = query(i);
		else x = query(i - n);
		if(x == m){
			cout << "! " << i << endl;
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int i, j;
	int x, y;
	
	cin >> n >> m;
	
	int sz = sqrt(n);
	
	for(i=0;i<=sz;i++){
		query(1);
	}
	
	sz -= 1;
	
	int l = -1;
	
	for(i=1;i<=n+sz;i+=sz){
		if(i <= n) x = query(i);
		else x = query(i - n);
		if(x <= m){
			l = i;
		}else if(l != -1){
			getans(l, i);
			return 0;
		}
	}
	
	return 0;
}