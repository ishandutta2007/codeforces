#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long Int;
Int n;
Int num[2160][2160];
Int sum[108000];
Int dif[108000];
Int ox, oy, ex, ey;
Int ores = -1, eres = -1;
int main(){
	scanf("%d", &n);
	for(Int i = 0;i < n;i++){
		for(Int j = 0;j < n;j++){
			scanf("%d", &num[i][j]);
			sum[i+j] += num[i][j];
			dif[i - j + 2000] += num[i][j];
		}
	}
	for(Int i = 0;i < n;i++){
		for(Int j = 0;j < n;j++){
			if(i % 2 == j % 2){
				if(eres < sum[i + j] + dif[i - j + 2000] - num[i][j]){
					eres = sum[i + j] + dif[i - j + 2000] - num[i][j];
					ex = i;
					ey = j;
				}
			}
			else{
				if(ores < sum[i + j] + dif[i - j + 2000] - num[i][j]){
					ores = sum[i + j] + dif[i - j + 2000] - num[i][j];
					ox = i;
					oy = j;
				}
			}
		}
	}
	cout << ores + eres << endl;
	cout << ox+1 << " " << oy+1 << " " << ex+1 << " " << ey+1 << endl;
	return 0;
}