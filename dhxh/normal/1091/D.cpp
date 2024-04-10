#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long n, m, t;

long long mod = 998244353;

vector <int> vec;

bool vis[20];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int x, vector <int> t){
	if(x > 6){
		for(int i=0;i<6;i++){
			vec.push_back(t[i]);
		}
		return 0;
	}
	
	for(int i=1;i<=6;i++){
		if(!vis[i]){
			t.push_back(i);
			vis[i] = true;
			dfs(x + 1, t);
			vis[i] = false;
			t.pop_back();
		}
	}
	
	
	return 0;
}

int main(){
	long long i, j;
	long long ans = 1;
	long long fac = 1;
	
	cin >> n;
	
	for(i=2;i<=n;i++){
		fac = fac * i % mod;
		ans = ((((ans - 1 + mod) % mod) * i % mod) + fac) % mod;
	}
	
	cout << ans << endl;
	
	return 0;
}