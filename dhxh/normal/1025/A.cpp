#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

string a;

int cnt[205];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> n;
	
	cin >> a;
	
	for(i=0;i<n;i++){
		cnt[a[i]]++;
	}
	
	if(n == 1){
		cout << "YES" << endl;
		return 0;
	}
	
	for(i='a';i<='z';i++){
		if(cnt[i] >= 2){
			cout << "YES" << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
	
	return 0;
}