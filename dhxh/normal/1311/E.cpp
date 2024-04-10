#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000 + 5;

int t;
int n, m;

int fa[maxn];

pair <int, int> getn(int d, int n){
	int x = 0, y = n * (d + d + n - 1) / 2;
	for(int i=0;n;i++){
		if(n <= (1 << i)){
			x += (i + d) * n;
			n = 0;
		}else{
			x += (i + d) * (1 << i);
			n -= (1 << i);
		}
	}
	return make_pair(x, y);
}

bool dfs(int d, int x, int c, int n, int m){
	bool flag = false;
	for(int i=0;i<=n/2;i++){
		pair <int, int> A = getn(d, i), B = getn(d, n - i);
		if(A.first + B.first <= m and m <= A.second + B.second){
			int a = 0, b = 0;
			if(B.first <= m - A.first and m - A.first <= B.second){
				a = A.first;
				b = m - A.first;
			}else if(B.first <= m - A.second and m - A.second <= B.second){
				a = A.second;
				b = m - A.second;
			}else if(A.first <= m - B.first and m - B.first <= A.second){
				a = m - B.first;
				b = B.first;
			}else if(A.first <= m - B.second and m - B.second <= A.second){
				a = m - B.second;
				b = B.second;
			}
			
			if(a){
				fa[c + 1] = x;
				dfs(d + 1, c + 1, c + 1, i - 1, a - d);
				c += i;
				flag = true;
			}
			if(b){
				fa[c + 1] = x;
				dfs(d + 1, c + 1, c + 1, n - i - 1, b - d);
				flag = true;
			}
		}
		if(flag) break;
	}
	
	return flag;
}

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		
		bool flag = dfs(1, 1, 1, n - 1, m);
		
		if(!flag){
			printf("NO\n");
		}else{
			printf("YES\n");
			for(i=2;i<=n;i++) printf("%d ", fa[i]);
			printf("\n");
		}
	}
	
	return 0;
}