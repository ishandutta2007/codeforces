#include <bits/stdc++.h>

using namespace std;

int n, m; 

int query(string x){
	cout << x << endl;
	int y;
	cin >> y;
	return y;
}

int main(){
	int i, j;
	int x, y;
	
	x = query("a");
	
	string ans = "a";
	
	if(x == 300){
		ans = "";
		for(i=1;i<=x;i++){
			ans.push_back('b');
		}
		cout << ans << endl;
		return 0;
	}
	
	for(i=1;i<=x;i++){
		ans.push_back('a');
	}
	
	y = query(ans);
	
	if(y > x){
		ans = "";
		for(i=1;i<=x;i++){
			ans.push_back('b');
		}
		cout << ans << endl;
		return 0;
	}else{
		n = x + 1;
		m = y;
	}
	if(!m)return 0;
	
	for(i=1;i<n;i++){
		ans[i - 1] = 'b';
		x = query(ans);
		if(x < m){
			m = x;
		}else{
			ans[i - 1] = 'a';
		}
		if(!m)return 0;
	}
	
	if(m){
		ans[n - 1] = 'b';
	}	
	
	cout << ans << endl;
	
	return 0;
}