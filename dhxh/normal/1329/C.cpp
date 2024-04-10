#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e6 + 5;

int n, m, t;
int N, M;

int a[maxn];
int p[maxn];
int ans[maxn];
bool vis[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

vector <int> dfs(int x){
	vector <int> vec;
	if(x > n) return vec;
	vector <int> A, B;
	A = dfs(x * 2);
	B = dfs(x * 2 + 1);
	
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	
	if(x * 2 <= m){
		while(A.size() and A.back() < ans[x * 2 + 1]){
			A.pop_back();
		}
		while(B.size() and B.back() < ans[x * 2]){
			B.pop_back();
		}
		
		if(!A.size()){
			ans[x] = B.back();
			B.pop_back();
		}else if(!B.size()){
			ans[x] = A.back();
			A.pop_back();
		}else if(A.back() > B.back()){
			ans[x] = B.back();
			B.pop_back();
		}else{
			ans[x] = A.back();
			A.pop_back();
		}
		reverse(A.begin(), A.end());
		reverse(B.begin(), B.end());
		vec.resize(A.size() + B.size());
		merge(A.begin(), A.end(), B.begin(), B.end(), vec.begin());
		vec.push_back(a[x]);
	}else if(x <= m){
		if(A.back() > B.back()){
			ans[x] = B.back();
			B.pop_back();
		}else{
			ans[x] = A.back();
			A.pop_back();
		}
		reverse(A.begin(), A.end());
		reverse(B.begin(), B.end());
		vec.resize(A.size() + B.size());
		merge(A.begin(), A.end(), B.begin(), B.end(), vec.begin());
		vec.push_back(a[x]);
	}else{
		reverse(A.begin(), A.end());
		reverse(B.begin(), B.end());
		vec.resize(A.size() + B.size());
		merge(A.begin(), A.end(), B.begin(), B.end(), vec.begin());
		vec.push_back(a[x]);
	}
	
	return vec;
}

int main(){
	int i, j;
	
	t = read();
	
	while(t--){
		N = read();
		M = read();
		n = (1 << N) - 1;
		m = (1 << M) - 1;
		
		for(i=1;i<=n;i++) vis[i] = ans[i] = 0;
		
		for(i=1;i<=n;i++){
			a[i] = read();
			p[a[i]] = i;
		}
		
		dfs(1);
		
		long long ret = 0;
		for(i=1;i<=m;i++){
			vis[p[ans[i]]] = true;
			ret += ans[i];
		}
		
		printf("%lld\n", ret);
		for(i=n;i>0;i--){
			if(!vis[i]){
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	
	return 0;
}