#include<iostream>
#include<algorithm>

using namespace std;
#define MOD (1000000007)

long long res;
long long sum;
long long a, b;
int main(){
	cin >> a >> b;
	for(int i = 0;i < b;i++){
		sum += i;
		sum %= MOD;
	}
	for(int i = 1;i <= a;i++){
		res += ((b*i%MOD) + 1) * sum ;
		res %= MOD;
	}
	cout << res << endl;
	return 0;
}