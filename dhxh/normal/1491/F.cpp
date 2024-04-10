#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 5;

int n, m, t;

int query(vector <int> &A, vector <int> &B){
	int i;
	cout << "? " << A.size() << " " << B.size() << endl;
	for(i=0;i<A.size();i++){
		cout << A[i];
		if(i + 1 != A.size()) cout << " ";
		else cout << endl;
	}
	
	for(i=0;i<B.size();i++){
		cout << B[i];
		if(i + 1 != B.size()) cout << " ";
		else cout << endl;
	}
	int ans;
	cin >> ans;
	return ans;
}

int query(int a, int b){
	cout << "? 1 1" << endl;
	cout << a << endl;
	cout << b << endl;
	int ans;
	cin >> ans;
	return ans;
}

void solve(){
	vector <int> ans;
	vector <int> A = {1};
	vector <int> B;
	int i;
	int x, y;
	
	for(i=2;i<=n;i++){
		B = {i};
		if(query(A, B)){
			x = i;
			break;
		}
		A.push_back(i);
	}
	
	int l = 1, r = x - 1;
	B = {x};
	
	while(l < r){
		int mid = (l + r) / 2;
		A.clear();
		for(i=1;i<=mid;i++){
			A.push_back(i);
		}
		
		if(query(A, B) == 0){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	
	for(i=1;i<l;i++) ans.push_back(i);
	for(i=l+1;i<x;i++) ans.push_back(i);
	
	for(i=x+1;i<=n;i++){
		if(query(x, i) == 0){
			ans.push_back(i);
		}
	}
	
	cout << "! " << ans.size();
	for(auto x : ans){
		cout << " " << x;
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int i, j, k;
	int x, y;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		solve();
	}
	
	return 0;
}