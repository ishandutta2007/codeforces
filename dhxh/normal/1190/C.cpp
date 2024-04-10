#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

int a[maxn];
int sum[maxn][2];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> n >> m;
	
	for(i=1;i<=n;i++){
		char ch;
		cin >> ch;
		a[i] = ch - '0';
		sum[i][0] = sum[i - 1][0];
		sum[i][1] = sum[i - 1][1];
		sum[i][a[i]]++;
	}
	
	for(i=0;i<=n-m;i++){
		if(sum[i][0] == i and sum[n][0] - sum[i + m][0] == n - m - i){
			cout << "tokitsukaze" << endl;
			return 0;
		}
		if(sum[i][1] == i and sum[n][1] - sum[i + m][1] == n - m - i){
			cout << "tokitsukaze" << endl;
			return 0;
		}
	}
	
	if(2 * m < n){
		cout << "once again" << endl;
		return 0;
	}
	
	for(i=1;i<n-m;i++){
		if(!((sum[i][0] == i or sum[i][1] == i) and (sum[n][0] - sum[i + m][0] == n - m - i or sum[n][1] - sum[i + m][1] == n - m - i))){
			cout << "once again" << endl;
			return 0;
		}
	}
	
	cout << "quailty" << endl;
	
	return 0;
}