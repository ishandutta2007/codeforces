#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

string str;

int a[maxn];

vector <int> ans;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(vector <int> &x, vector <int> &y){
	if(x.size() != y.size()){
		return x.size() < y.size();
	}else{
		for(int i=x.size()-1;i>=0;i--){
			if(x[i] != y[i]){
				return x[i] < y[i];
			}
		}
	}
	return false;
}

int split(int p){
	if(p <= 1){
		return 0;
	}
	if(p > n){
		return 0;
	}
	if(a[p] == 0)return 0;
	vector <int> x, y;
	vector <int> ret;
	
	for(int i=p-1;i>=1;i--){
		x.push_back(a[i]);
	}
	
	for(int i=n;i>=p;i--){
		y.push_back(a[i]);
	}
	
	if(x.size() < y.size()){
		swap(x, y);
	}
	
	x.push_back(0);
	x.push_back(0);
	x.push_back(0);
	
	for(int i=0;i<x.size()-1;i++){
		if(i < y.size())x[i] += y[i];
		x[i + 1] += x[i] / 10;
		x[i] %= 10;
	}
	int i=y.size();
	x[i + 1] += x[i] / 10;
	x[i] %= 10;
	
	while(!x.back()){
		x.pop_back();
	}
	
	if(ans.size() == 0 or cmp(x, ans)){
		ans = x;
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		char ch;
		cin >> ch;
		a[i] = ch - '0';
	}
	
	if(n % 2 == 0){
		for(x=n/2+1;a[x]==0 and x>0;x--);
		for(y=n/2+1;a[y]==0 and y<n;y++);
		split(x);
		split(y);
	}else{
		m = n / 2 + 1;
		for(x=m-1;a[x]==0 and x>0;x--);
		for(y=m-1;a[y]==0 and y<n;y++);
		split(x);
		split(y);
		
		for(x=m;a[x]==0 and x>0;x--);
		for(y=m;a[y]==0 and y<n;y++);
		split(x);
		split(y);
		
		for(x=m+1;a[x]==0 and x>0;x--);
		for(y=m+1;a[y]==0 and y<n;y++);
		split(x);
		split(y);
	}
	
	for(i=ans.size()-1;i>=0;i--){
		cout << ans[i];
	}
	cout << endl;
	
	return 0;
}