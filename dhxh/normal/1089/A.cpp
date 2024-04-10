#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, t;

bool f[205][205][5][5];

vector <pair <int, int> > vec[205][205][5][5];

int init(){
	int i, j, k, l, m;
	
	f[0][0][0][0] = true;
	
	for(i=0;i<=200;i++){
		for(j=0;j<=200;j++){
			for(k=0;k<3;k++){
				for(l=0;l<3;l++){
					if(f[i][j][k][l]){
						if(k == 2 and l == 2){
							for(m=0;m<14;m++){
								if(i + 15 <= 200 and j + m <= 200 and !f[i + 15][j + m][k + 1][l]){
									f[i + 15][j + m][k + 1][l] = true;
									vec[i + 15][j + m][k + 1][l] = vec[i][j][k][l];
									vec[i + 15][j + m][k + 1][l].push_back(make_pair(15, m));
								}
								if(i + m <= 200 and j + 15 <= 200 and !f[i + m][j + 15][k][l + 1]){
									f[i + m][j + 15][k][l + 1] = true;
									vec[i + m][j + 15][k][l + 1] = vec[i][j][k][l];
									vec[i + m][j + 15][k][l + 1].push_back(make_pair(m, 15));
								}
							}
							
							for(m=14;m<200;m++){
								if(i + m + 2 <= 200 and j + m <= 200 and !f[i + m + 2][j + m][k + 1][l]){
									f[i + m + 2][j + m][k + 1][l] = true;
									vec[i + m + 2][j + m][k + 1][l] = vec[i][j][k][l];
									vec[i + m + 2][j + m][k + 1][l].push_back(make_pair(m + 2, m));
								}
								if(i + m <= 200 and j + m + 2 <= 200 and !f[i + m][j + m + 2][k][l + 1]){
									f[i + m][j + m + 2][k][l + 1] = true;
									vec[i + m][j + m + 2][k][l + 1] = vec[i][j][k][l];
									vec[i + m][j + m + 2][k][l + 1].push_back(make_pair(m, m + 2));
								}
							}
						}else{
							for(m=0;m<24;m++){
								if(i + 25 <= 200 and j + m <= 200 and !f[i + 25][j + m][k + 1][l]){
									f[i + 25][j + m][k + 1][l] = true;
									vec[i + 25][j + m][k + 1][l] = vec[i][j][k][l];
									vec[i + 25][j + m][k + 1][l].push_back(make_pair(25, m));
								}
								if(i + m <= 200 and j + 25 <= 200 and !f[i + m][j + 25][k][l + 1]){
									f[i + m][j + 25][k][l + 1] = true;
									vec[i + m][j + 25][k][l + 1] = vec[i][j][k][l];
									vec[i + m][j + 25][k][l + 1].push_back(make_pair(m, 25));
								}
							}
							
							for(m=24;m<200;m++){
								if(i + m + 2 <= 200 and j + m <= 200 and !f[i + m + 2][j + m][k + 1][l]){
									f[i + m + 2][j + m][k + 1][l] = true;
									vec[i + m + 2][j + m][k + 1][l] = vec[i][j][k][l];
									vec[i + m + 2][j + m][k + 1][l].push_back(make_pair(m + 2, m));
								}
								if(i + m <= 200 and j + m + 2 <= 200 and !f[i + m][j + m + 2][k][l + 1]){
									f[i + m][j + m + 2][k][l + 1] = true;
									vec[i + m][j + m + 2][k][l + 1] = vec[i][j][k][l];
									vec[i + m][j + m + 2][k][l + 1].push_back(make_pair(m, m + 2));
								}
							}
						}
					}
				}
			}
		}
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &t);
	
	init();
	
	while(t--){
		scanf("%d%d", &x, &y);
		
		if(f[x][y][3][0]){
			printf("%d:%d\n", 3, 0);
			for(i=0;i<vec[x][y][3][0].size();i++){
				printf("%d:%d ", vec[x][y][3][0][i].first, vec[x][y][3][0][i].second);
			}
			printf("\n");
		}else if(f[x][y][3][1]){
			printf("%d:%d\n", 3, 1);
			for(i=0;i<vec[x][y][3][1].size();i++){
				printf("%d:%d ", vec[x][y][3][1][i].first, vec[x][y][3][1][i].second);
			}
			printf("\n");
		}else if(f[x][y][3][2]){
			printf("%d:%d\n", 3, 2);
			for(i=0;i<vec[x][y][3][2].size();i++){
				printf("%d:%d ", vec[x][y][3][2][i].first, vec[x][y][3][2][i].second);
			}
			printf("\n");
		}else if(f[x][y][2][3]){
			printf("%d:%d\n", 2, 3);
			for(i=0;i<vec[x][y][2][3].size();i++){
				printf("%d:%d ", vec[x][y][2][3][i].first, vec[x][y][2][3][i].second);
			}
			printf("\n");
		}else if(f[x][y][1][3]){
			printf("%d:%d\n", 1, 3);
			for(i=0;i<vec[x][y][1][3].size();i++){
				printf("%d:%d ", vec[x][y][1][3][i].first, vec[x][y][1][3][i].second);
			}
			printf("\n");
		}else if(f[x][y][0][3]){
			printf("%d:%d\n", 0, 3);
			for(i=0;i<vec[x][y][0][3].size();i++){
				printf("%d:%d ", vec[x][y][0][3][i].first, vec[x][y][0][3][i].second);
			}
			printf("\n");
		}else{
			printf("Impossible\n");
		}
	}
	
	return 0;
}
/*
6
75 0
90 90
20 0
0 75
78 50
80 100
*/