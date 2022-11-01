#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

char a[1005][5];
bool b[1005][3];
int c[1005];

int s[1005];

int mina = 1e9 + 7, minb = 1e9 + 7, minc = 1e9 + 7;

int minn = 1e9 + 7;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	bool x, y, z;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> c[i] >> a[i];
		
		for(j=0;j<strlen(a[i]);j++){
			if(a[i][j] == 'A'){
				b[i][0] = true;
				mina = min(mina, c[i]);
			}
			if(a[i][j] == 'B'){
				b[i][1] = true;
				minb = min(minb, c[i]);
			}
			if(a[i][j] == 'C'){
				b[i][2] = true;
				minc = min(minc, c[i]);
			}
		}
		
		if(b[i][0] and b[i][1] and b[i][2]){
			minn = min(minn, c[i]);
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			x = b[i][0] | b[j][0];
			y = b[i][1] | b[j][1];
			z = b[i][2] | b[j][2];
			
			if(x and y and z){
				minn = min(minn, c[i] + c[j]);
			}
			if(x and y and !z){
				minn = min(minn, c[i] + c[j] + minc);
			}
			if(x and !y and z){
				minn = min(minn, c[i] + c[j] + minb);
			}
			if(!x and y and z){
				minn = min(minn, c[i] + c[j] + mina);
			}
		}
	}
	
	if(minn == 1000000007){
		cout << -1 << endl;
		return 0;
	}
	
	cout << minn << endl;
	
	return 0;
}