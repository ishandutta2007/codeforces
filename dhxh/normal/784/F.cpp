#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

long long n;
long long ans = 1;

int a[10005];
int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int ans = 0;
	
	clock_t start,finish;
	
	cin >> n;
    start=clock();
	
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	while(clock() - start <= 1.5 * CLOCKS_PER_SEC){
		ans++;
	}
	
	for(i=1;i<=n;i++){
		cout << a[i] << " ";
	}
	
	return 0;
}