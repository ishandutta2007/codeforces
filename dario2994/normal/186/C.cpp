#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define MAXN 100010
#define INF 1000000100
#define mod 1000000007
#define rp(i,n) for(int i=0;i<n;i++)
#define rp1(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

ULL n;

LL pot(ULL a,ULL e){
	if(e==0)return 1;
	if(e%2==1)return (a*pot((a*a)%mod,e/2))%mod;
	return pot((a*a)%mod,e/2);
}

int main(){
	cin >> n;
	if(n==0){
		cout << 1;
		return 0;
	}
	cout << (pot(2,2*n-1)+pot(2,n-1))%mod;
}