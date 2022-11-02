#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
#define maxn 1000009
using namespace std;
const int MOD = 1e9 + 7;
long long bin[maxn];
char s[maxn];
int main(){
	
	scanf("%s", s);
	int n = strlen(s);
	bin[0] = 1;
	for(int i = 1; i <= n; i++)
		bin[i] = bin[i - 1] * 2 % MOD;
	long long ans = 0;
	int sum = 0;
	for(int i = 0; i <n ;i++){
		if(s[i] == 'a')
			sum++;
		else{
			ans = ans + bin[sum] - 1;
			ans %= MOD;
		}
	}
	ans += MOD;
	ans %= MOD;
	cout << ans << endl;
	return 0;
}