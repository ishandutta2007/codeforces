#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int h, w;
int q;
int r1, r2, c1, c2;
int ii[510][510];
int jj[510][510];
char f[510][510];

int main(){
	scanf("%d%d", &h, &w);
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			scanf(" %c", &f[i][j]);
		}
	}
	
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			if(i != h && f[i][j] == '.' && f[i+1][j] == '.')ii[i][j] = 1;
			if(j != w && f[i][j] == '.' && f[i][j+1] == '.')jj[i][j] = 1;
		}
	}
	
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			ii[i][j] = ii[i][j] + ii[i-1][j] + ii[i][j-1] - ii[i-1][j-1];
			jj[i][j] = jj[i][j] + jj[i-1][j] + jj[i][j-1] - jj[i-1][j-1];
		}
	}
	
	scanf("%d", &q);
	while(q--){
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		int res = 0;
		r1--;c1--;
		res += ii[r2-1][c2] - ii[r1][c2] - ii[r2-1][c1] + ii[r1][c1];
		res += jj[r2][c2-1] - jj[r1][c2-1] - jj[r2][c1] + jj[r1][c1];
		
		printf("%d\n", res);
	}
	return 0;
	
}