#include <bits/stdc++.h>

using namespace std;

int n, m, t;

char a[305][305];

int cnt[3][2];

int main(){
	int i, j;
	char c;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		
		memset(cnt, 0, sizeof(cnt));
		
		int sum = 0;
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf(" %c", &a[i][j]);
				if(a[i][j] == 'X') cnt[(i + j) % 3][0]++, sum++;
				else if(a[i][j] == 'O') cnt[(i + j) % 3][1]++, sum++;
			}
		}
		
		int x, y;
		
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(i == j) continue;
				if(cnt[i][0] + cnt[j][1] <= sum / 3){
					x = i, y = j;
					break;
				}
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(a[i][j] == 'X' and (i + j) % 3 == x) a[i][j] = 'O';
				else if(a[i][j] == 'O' and (i + j) % 3 == y) a[i][j] = 'X';
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				printf("%c", a[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}