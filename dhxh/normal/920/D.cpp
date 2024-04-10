#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 5000 + 5;

int n, k, v;

int a[maxn];

bool f[maxn][maxn];
pair <int, int> fr[maxn][maxn];
bool u[maxn][maxn];

bool vis[maxn];

struct ex {
	int cnt, x, y;
};

vector <ex> ans;
vector <int> vec;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	k = read();
	v = read();
	
	f[0][0] = true;
	
	for(i=1;i<=n;i++){
		a[i] = read();
		for(j=0;j<k;j++){
			f[i][j] = f[i - 1][j];
			fr[i][j] = make_pair(i - 1, j);
			u[i][j] = false;
		}
		
		for(j=0;j<k;j++){
			if(f[i - 1][j]){
				if(!f[i][(j + a[i]) % k]){
					f[i][(j + a[i]) % k] = true;
					fr[i][(j + a[i]) % k] = make_pair(i - 1, j);
					u[i][(j + a[i]) % k] = true;
				}
			}
		}
	}
	
	if(!f[n][v % k]){
		printf("NO\n");
		return 0;
	}
	
	pair <int, int> tmp = make_pair(n, v % k);
	
	while(tmp.first){
		if(u[tmp.first][tmp.second]){
			vec.push_back(tmp.first);
			vis[tmp.first] = true;
		}
		
		tmp = fr[tmp.first][tmp.second];
	}
	
	for(i=1;i<vec.size();i++){
		x = vec[i];
		ans.push_back((ex){a[x] / k + 1, x, vec[0]});
		a[vec[0]] += a[x];
		a[x] = 0;
	}
	
	if(v % k){
		x = vec[0];
		y = 1;
		if(x == 1){
			y = 2;
		}
	}else{
		x = 1;
		y = 2;
		ans.push_back((ex){a[x] / k + 1, x, y});
		a[y] += a[x];
		a[x] = 0;
		vis[x] = true;
	}
	
	for(i=1;i<=n;i++){
		if(!vis[i]){
			y = i;
			break;
		}
	}
	
	for(i=y+1;i<=n;i++){
		if(!vis[i]){
			ans.push_back((ex){a[i] / k + 1, i, y});
			a[y] += a[i];
			a[i] = 0;
		}
	}
	
	if(a[x] >= v){
		ans.push_back((ex){(a[x] - v) / k, x, y});
	}else{
		if(a[x] + a[y] / k * k < v){
			printf("NO\n");
			return 0;
		}else{
			ans.push_back((ex){(v - a[x]) / k, y, x});
		}
	}
	
	printf("YES\n");
	
	for(ex t : ans){
		if(t.cnt >= 1)printf("%d %d %d\n", t.cnt, t.x, t.y);
	}
	
	return 0;
}