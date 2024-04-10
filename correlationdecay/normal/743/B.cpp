#include <bits/stdc++.h>
#define maxn 100009
using namespace std;
char s[maxn];
int solve(int n, long long m){
	if(n == 1){
		return 1;
	}
	long long num = (1LL << (n - 1)) - 1;
	if(num  + 1 == m){
		return n;
	}
	else if(m <= num){
		return solve(n - 1, m);
	}
	else
		return solve(n - 1, m - num - 1);
}
int main(){
	long long n, m;
	cin >> n >> m ;
	cout << solve(n, m) <<endl;
	//system("pause");
	return 0;
}