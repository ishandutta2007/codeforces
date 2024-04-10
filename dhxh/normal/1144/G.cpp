#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5;

int inf = 0x3f3f3f3f;

int n, m, t;

int a[maxn];

int f[maxn][2];
int fr[maxn][2];

vector <int> ans;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		f[i][0] = -inf;
		f[i][1] = inf;
	}
	
	f[1][0] = inf;
	f[1][1] = -inf;
	
	//0 biggest when going up
	//1 smallest when going down
	
	for(i=2;i<=n;i++){
		if(f[i - 1][0] != -inf){
			if(a[i] > a[i - 1]){
				f[i][0] = f[i - 1][0];
				fr[i][0] = 0;
			}
			
			if(f[i - 1][0] > a[i]){
				f[i][1] = a[i - 1];
				fr[i][1] = 0;
			}
		}
		
		if(f[i - 1][1] != inf){
			if(a[i] < a[i - 1] and f[i - 1][1] < f[i][1]){
				f[i][1] = f[i - 1][1];
				fr[i][1] = 1;
			}
			
			if(f[i - 1][1] < a[i] and f[i][0] < a[i - 1]){
				f[i][0] = a[i - 1];
				fr[i][0] = 1;
			}
		}
	}
	
	if(f[n][0] != -inf){
		x = 0;
	}else if(f[n][1] != inf){
		x = 1;
	}else{
		printf("NO\n");
		return 0;
	}
	
	for(i=n;i>0;i--){
		ans.push_back(x);
		x = fr[i][x];
	}
	
	reverse(ans.begin(), ans.end());
	
	printf("YES\n");
	for(auto x : ans){
		printf("%d ", x);
	}
	printf("\n");
	
	return 0;
}