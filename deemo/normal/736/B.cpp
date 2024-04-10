#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e3 + 10;

int mx[MAXN], dp[MAXN];

bool check(int x){
	if (x < 2)	return false;
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0)	return false;
	return true;;
}

int main(){
	for (int i = 1; i < MAXN; i++)
		for (int j = i + i; j < MAXN; j += i)
			mx[j] = i;
	dp[0] = dp[1] = 1e9;
	for (int i = 2; i < MAXN; i++){
		dp[i] = mx[i];
		for (int j = 2; j < i; j++)
			dp[i] = min(dp[i], dp[i-j] + mx[j]);
	}
	int x;	cin >> x;
	if (x < MAXN - 2)
		cout << dp[x] << endl;
	else{
		if (x % 2 == 0)
			cout << "2\n";
		else{
			if (check(x))
				cout << "1\n";
			else if (check(x - 2))
				cout << "2\n";
			else
				cout << "3\n";
		}
	}
	return 0;
}