#include<iostream>
#include<algorithm>

using namespace std;

#define MOD 1000000007

long long ans[] = {1, 2, 9, 64, 625, 7776, 117649, 2097152};

int main(){
    long long n, k, res = 1;
    cin >> n >> k;
    for(long long i = k + 1;i <= n;i++){
	res *= (n - k);
	res %= MOD;
    }
    res *= ans[k - 1];
    cout << res % MOD << endl;
    return 0;
}