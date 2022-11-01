#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, p;

char ch[2005];
int a[2005];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	int pos, x, y;
	bool isf = false;
	
	cin >> n >> p;
	
	for(i=1;i<=n;i++){
		cin >> ch[i];
		if(ch[i] == '0'){
			a[i] = 0;
		}else if(ch[i] == '1'){
			a[i] = 1;
		}else{
			a[i] = 2;
		}
	}
	
	for(i=1;i<=n-p;i++){
		if(a[i] != a[i + p] or a[i] == 2 or a[i + p] == 2){
			isf = true;
			
			if(a[i] == 2 and a[i + p] == 2){
				a[i] = 1;
				a[i + p] = 0;
			}else if(a[i] == 2){
				a[i] = !a[i + p];
			}else if(a[i + p] == 2){
				a[i + p] = !a[i];
			}
			break;
		}
	}
	
	if(!isf){
		cout << "No" << endl;
		return 0;
	}
	
	for(i=1;i<=n;i++){
		if(a[i] == 2){
			a[i] = 0;
		}
		cout << a[i];
	}
	
	cout << endl;
	
	return 0;
}