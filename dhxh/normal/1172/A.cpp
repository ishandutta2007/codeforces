#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

int a[maxn];
int b[maxn];

bool v[maxn];
int ans = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool check(int x){
	int i, j, k = 1;
	int cnt = 0;
	vector <int> vec;
	
	memset(v, 0, sizeof(v));
	for(i=1;i<=n;i++){
		v[a[i]] = true;
		if(a[i])cnt++;
	}
	
	for(i=1;i<=x;i++){
		v[b[i]] = true;
		if(b[i])cnt++;
	}
	
	for(i=x+1;i<=n;i++){
		if(cnt == 0)break;
		while(!v[k] and k <= n)k++;
		if(k == n + 1)return false;
		vec.push_back(k);
		v[k] = false;
		cnt--;
		v[b[i]] = true;
		if(b[i])cnt++;
	}
	
	for(j=1;i<=n;i++,j++){
		if(x != 0)break;
		if(b[i] != j){
			return false;
		}
	}
	
	if(x != 0)j = 1;
	
	for(i=0;i<vec.size();i++,j++){
		if(vec[i] != j)return false;
	}
	
	return true;
}

int getans(int x){
	int i, j, k = 1;
	int cnt = 0;
	vector <int> vec;
	
	memset(v, 0, sizeof(v));
	for(i=1;i<=n;i++){
		v[a[i]] = true;
		if(a[i])cnt++;
	}
	
	for(i=1;i<=x;i++){
		v[b[i]] = true;
		if(b[i])cnt++;
	}
	
	for(i=x+1;i<=n;i++){
		if(cnt == 0)break;
		while(!v[k] and k <= n)k++;
		vec.push_back(k);
		v[k] = false;
		cnt--;
		v[b[i]] = true;
		if(b[i])cnt++;
	}
	
	i--;
	
	return i + cnt;
}

int main(){
	int i, j;
	int flag = -1;
	
	n = read();
	int l = 1, r = n;
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	for(i=1;i<=n;i++){
		b[i] = read();
		if(b[i] == 1){
			flag = i;
		}
	}
	
	if(check(0)){
		printf("%d\n", getans(0));
		return 0;
	}
	
	if(flag != -1)l = flag;
	
	while(l < r){
		int mid = (l + r) / 2;
		if(!check(mid)){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	
	printf("%d\n", getans(l));
	
	return 0;
}