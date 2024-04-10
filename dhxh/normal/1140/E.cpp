#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

long long ans = 0;

long long mod = 998244353;

long long n, m, t;

vector <int> a[2];

queue <int> q[2];

long long f[maxn][2];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		x = read();
		a[i & 1].push_back(x);
		if(x != -1){
			q[i & 1].push(x);
		}
	}
	
	if(a[0][0] == -1){
		f[0][0] = m - 1;
		f[0][1] = 1;
	}else{
		q[0].pop();
		if(q[0].size() and q[0].front() == a[0][0]){
			f[0][0] = 0;
			f[0][1] = 1;
		}else{
			f[0][0] = 1;
			f[0][1] = 0;
		}
	}
	
	for(i=1;i<a[0].size();i++){
		if(a[0][i] == -1){
			f[i][0] = (f[i - 1][0] * (m - 2) % mod + f[i - 1][1] * (m - 1) % mod) % mod;
			f[i][1] = f[i - 1][0];
		}else{
			q[0].pop();
			if(q[0].size() and q[0].front() == a[0][i]){
				f[i][0] = 0;
				f[i][1] = f[i - 1][0];
			}else{
				f[i][0] = f[i - 1][0];
				f[i][1] = 0;
			}
		}
	}
	
	ans = (f[a[0].size() - 1][0] + f[a[0].size() - 1][1]) % mod;
	
	if(a[1][0] == -1){
		f[0][0] = m - 1;
		f[0][1] = 1;
	}else{
		q[1].pop();
		if(q[1].size() and q[1].front() == a[1][0]){
			f[0][0] = 0;
			f[0][1] = 1;
		}else{
			f[0][0] = 1;
			f[0][1] = 0;
		}
	}
	
	for(i=1;i<a[1].size();i++){
		if(a[1][i] == -1){
			f[i][0] = (f[i - 1][0] * (m - 2) % mod + f[i - 1][1] * (m - 1) % mod) % mod;
			f[i][1] = f[i - 1][0];
		}else{
			q[1].pop();
			if(q[1].size() and q[1].front() == a[1][i]){
				f[i][0] = 0;
				f[i][1] = f[i - 1][0];
			}else{
				f[i][0] = f[i - 1][0];
				f[i][1] = 0;
			}
		}
	}
	
	ans = ans * (f[a[1].size() - 1][0] + f[a[1].size() - 1][1]) % mod;
	
	cout << ans << endl;
	
	return 0;
}