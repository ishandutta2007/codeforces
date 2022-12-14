#include <bits/stdc++.h>

using namespace std;

int main(){
	char a[8][8],b[8][8];
	int p = 0 , k = 0 , q = 0;
	for(int i = 0 ; i < 8 ; i++)
		for(int t = 0 ; t < 8 ; t++) cin>>a[i][t] , b[i][t] = 'W';

	for(int i = 0 ; i < 8 ; i++){
		if(a[0][i] == 'B'){
			for(int t = 0 ; t < 8 ; t++){
				if(a[t][i] == 'B') p++;
				if(b[t][i] == 'D') q++;
			}
			if(p == 8 && q != 8) {
				k++ , p = 0 , q = 0;
				for(int o = 0 ; o < 8 ; o++) 
					b[o][i] = 'D';
			}
			else p = 0 , q = 0;
		}
	}
	for(int i = 0 ; i < 8 ; i++){
		if(a[i][0] == 'B'){
			for(int t = 0 ; t < 8 ; t++){
				if(a[i][t] == 'B') p++;
				if(b[i][t] == 'D') q++;
			}
			if(p == 8 && q != 8) k++ , p = 0 , q = 0;
			else p = 0 , q = 0;
		}
	}
	cout<<k<<endl;
}