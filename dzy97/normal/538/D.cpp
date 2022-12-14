#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
int n;
char s[105][105], t[105][105];
int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++) scanf("%s", s[i] + 1);
	for(int i = 1;i < n * 2;i ++){
		for(int j = 1;j < n * 2;j ++){
			int flag = 0;
			for(int p = 1;p <= n;p ++){
				for(int q = 1;q <= n;q ++){
					int x = i + p - n, y = j + q - n;
					if(x >= 1 && x <= n && y >= 1 && y <= n && s[p][q] == 'o'){
						if(s[x][y] == '.'){
							flag = 1;
							break;
						}
					}
				}
			}
			if(!flag){
				t[i][j] = 'x';
				for(int p = 1;p <= n;p ++){
					for(int q = 1;q <= n;q ++){
						int x = i + p - n, y = j + q - n;
						if(x >= 1 && x <= n && y >= 1 && y <= n && s[p][q] == 'o'){
							if(s[x][y] == 'x') s[x][y] = '1';
						}
					}
				}
			}else{
				t[i][j] = '.';
			}
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			if(s[i][j] == 'x'){
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	t[n][n] = 'o';
	for(int i = 1;i < 2 * n;i ++) printf("%s\n", t[i] + 1);
	return 0;
}