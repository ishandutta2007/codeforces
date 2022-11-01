#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long mod = 1e9 + 7;

int n, m, t;

string a, b;

int f[2005][2005][2];
long long ten[2005];
long long tb[2005];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

long long getans(string str, bool flag){
	int i, j, k;
	memset(f, 0, sizeof(f));
	long long ans = 0;
	int N = str.length();
	str = '0' + str;
	
	f[0][0][0] = 1;
	
	for(i=1;i<=N;i++){
		for(j=0;j<10;j++){
			if(((i & 1) and j == n) or ((i & 1) == 0 and j != n))continue;
			for(k=0;k<m;k++){
				f[i][(k + tb[N - i] * j) % m][1] += f[i - 1][k][1];
				if(f[i][(k + tb[N - i] * j) % m][1] >= mod)f[i][(k + tb[N - i] * j) % m][1] -= mod;
				
				if(j < str[i] - '0'){
					f[i][(k + tb[N - i] * j) % m][1] += f[i - 1][k][0];
					if(f[i][(k + tb[N - i] * j) % m][1] >= mod)f[i][(k + tb[N - i] * j) % m][1] -= mod;
				}else if(j == str[i] - '0'){
					f[i][(k + tb[N - i] * j) % m][0] += f[i - 1][k][0];
					if(f[i][(k + tb[N - i] * j) % m][0] >= mod)f[i][(k + tb[N - i] * j) % m][0] -= mod;
				}
			}
		}
	}
	
	ans = f[N][0][1];
	if(flag)ans += f[N][0][0];
	if(ans >= mod)ans -= mod;
	
	return ans;
}

int main(){
	int i, j;
	
	cin >> m >> n;
	
	cin >> a >> b;
	
	ten[0] = 1;
	tb[0] = 1;
	for(i=1;i<=2000;i++){
		ten[i] = ten[i - 1] * 10 % mod;
		tb[i] = tb[i - 1] * 10 % m;
	}
	
	cout << (getans(b, true) - getans(a, false) + mod) % mod << endl;
	
	return 0;
}