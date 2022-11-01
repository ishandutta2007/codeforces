#include <bits/stdc++.h>

using namespace std;

int n;
int A[55];
char str[55];
int f[55][55][25][25];

int dfs(int x, int a, int b, int c){
	if(x == -1){
		if(a == A[0] and b == 0 and c == 0){
			return 0;
		}else{
			return 0x3f3f3f3f;
		}
	}
	
	int &ret = f[x][a + 20][b + 12][c + 12];
	if(ret != -1) return ret;
	ret = 0x3f3f3f3f;
	
	if(x == 1){
		a += b;
		b = 0;
	}
	if(x == 0){
		a += c;
		c = 0;
	}
	
	if(a > A[x]){
		ret = min(ret, (a - A[x]) * (x + 1) + dfs(x - 1, A[x], b, c));
		ret = min(ret, (a - A[x] - 1) * (x + 1) + x + dfs(x - 1, A[x] + 9, b + (c + 1) / 11, (c + 1) % 11));
		ret = min(ret, (a - A[x] + 1) * (x + 1) + dfs(x - 1, A[x] - 10, b + (c - 1) / 11, (c - 1) % 11));
	}else{
		ret = min(ret, (A[x] - a) * (x + 1) + dfs(x - 1, A[x], b, c));
		ret = min(ret, (A[x] - a + 1) * (x + 1) + x + dfs(x - 1, A[x] + 9, b + (c + 1) / 11, (c + 1) % 11));
		ret = min(ret, abs(A[x] - 1 - a) * (x + 1) + dfs(x - 1, A[x] - 10, b + (c - 1) / 11, (c - 1) % 11));
	}
		
	return ret;
}

int main(){
	int i, j;
	
	scanf("%s", str);
	n = strlen(str);
	
	reverse(str, str + n);
	
	for(i=0;i<n;i++) A[i] = str[i] - '0';
	
	memset(f, -1, sizeof(f));
	
	printf("%d\n", dfs(n, 0, 0, 0));
	
	return 0;
}