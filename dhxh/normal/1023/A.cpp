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
string b;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int t = -1;
	
	cin >> n >> m;
	
	cin >> a >> b;
	
	for(i=0;i<n;i++){
		if(a[i] == '*'){
			t = i;
		}
	}
	
	if(t == -1){
		if(a == b){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
		return 0;
	}
	
	for(i=0;i<t;i++){
		if(a[i] != b[i]){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	for(i=n-1,j=m-1;i>t;i--,j--){
		if(a[i] != b[j] or j< t){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	for(;j>=t;j--){
		if('a' > b[j] or b[j] > 'z'){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	
	return 0;
}