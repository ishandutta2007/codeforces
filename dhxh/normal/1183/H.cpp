#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 105;

long long n, m, t;

string str;

long long f[maxn][maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, k;
	long long ans = 0;
	
	cin >> n >> m;
	cin >> str;
	str = '0' + str;
	
	f[0][0] = 1;
	for(i=1;i<=n;i++){
		for(j=i-1;j>=0;j--){
			for(k=0;k<=n;k++){
				f[i][k + 1] = min(m, f[i][k + 1] + f[j][k]);
			}
			if(str[i] == str[j])break;
		}
	}
	
	for(i=n;i>=0;i--){
		long long sum = 0;
		for(j=0;j<=n;j++){
			sum += f[j][i];
		}
		if(sum >= m){
			ans += m * (n - i);
			cout << ans << endl;
			return 0;
		}else{
			ans += sum * (n - i);
			m -= sum;
		}
	}
	
	cout << -1 << endl;
	
	return 0;
}