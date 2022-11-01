#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, l;

int a[105];
int b[105];

bool flag = false;

bool check(){
	int i, j;
	
	for(i=1;i<=n;i++){
		if(a[i] != b[i]){
			return false;
		}
	}
	
	return true;
}

int main(){
	int i, j;
	
	cin >> n >> l;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(i=1;i<=n;i++){
		cin >> b[i];
	}
	
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	
	for(i=1;i<=l;i++){
		for(j=1;j<=n;j++){
			b[j] = b[j] + 1;
			b[j] = b[j] % l;
		}
		sort(b + 1, b + n + 1);
		
		if(check()){
			flag = true;
			break;
		}
	}
	
	if(flag){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	
	return 0;
}