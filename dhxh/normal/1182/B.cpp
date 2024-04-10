#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

char a[505][505];
bool v[505][505];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	bool flag = false;
	
	cin >> n >> m;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j] == '*' and a[i - 1][j] == '*' and a[i + 1][j] == '*' and a[i][j - 1] == '*' and a[i][j + 1] == '*'){
				flag = true;
				x = i, y = j;
				break;
			}
		}
		if(flag)break;
	}
	
	if(!flag){
		cout << "NO" << endl;
		return 0;
	}
	
	for(i=x;i>0;i--){
		if(a[i][y] == '*'){
			v[i][y] = true;
		}else{
			break;
		}
	}
	
	for(i=x;i<=n;i++){
		if(a[i][y] == '*'){
			v[i][y] = true;
		}else{
			break;
		}
	}
	
	for(i=y;i>0;i--){
		if(a[x][i] == '*'){
			v[x][i] = true;
		}else{
			break;
		}
	}
	
	for(i=y;i<=m;i++){
		if(a[x][i] == '*'){
			v[x][i] = true;
		}else{
			break;
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j] == '*' and !v[i][j]){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	
	cout << "YES" << endl;
	
	return 0;
}