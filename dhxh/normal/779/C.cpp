#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

struct ex {
	int a;
	int b;
	int d;
};

ex item[200005];

long long ans = 0;

int n, k;

int read(){
	int x;
	scanf("%d", &x);
	return x; 
}

bool cmp(ex a, ex b){
	return a.d < b.d;
}

int main(){
	int i, j;
	int x;
	
	n = read();
	k = read();
	
	for(i=1;i<=n;i++){
		item[i].a = read();
	}
	
	for(i=1;i<=n;i++){
		item[i].b = read();
		item[i].d = item[i].a - item[i].b;
	}
	
	sort(item + 1, item + n + 1, cmp);
	
	i = 1;
	
	while(i <= k or item[i].d < 0){
		ans = ans + item[i].a;
		i++;
	}
	
	while(i <= n){
		ans = ans + item[i].b;
		i++;
	}
	
	cout << ans << endl;
	
	return 0;
}