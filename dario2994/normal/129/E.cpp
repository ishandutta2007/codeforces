#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define MAXN 1000020
#define MOD ULL(1000000007)
typedef unsigned long long ULL;
using namespace std;

ULL inverso(ULL n){
	ULL m=MOD;
	if(n<=1)return 1;
	else{
		return (((m/n)*((m-inverso(m%n))%m))%m); 
	}
}

ULL bin(int n,int k){
	ULL res=1;
	for(int i=n;i>n-k;i--)res=(res*i)%MOD;
	for(int i=1;i<=k;i++)res=(res*inverso(i))%MOD;
	return res;
}

int main(){
	ULL n,m,k;
	cin >> n >> m >> k;
	if(2*k>=n or 2*k>=m)cout << 0;
	else cout << (bin(n-1,2*k)*bin(m-1,2*k))%MOD;
}