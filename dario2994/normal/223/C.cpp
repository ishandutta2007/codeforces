#include <iostream>
#include <cstdlib>
#include <fstream>
#include <tr1/unordered_map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define MAXN 4000
#define INF 1000000100
#define MOD ULL(1000000007)
#define rp(i,n) for(int i=0;i<n;i++)
#define rp1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using namespace tr1;
typedef long long LL;
typedef unsigned long long ULL;

int N;
ULL K;
ULL a[MAXN];
ULL binom[MAXN];
ULL res[MAXN];

ULL inverso(ULL n){
	ULL m=MOD;
	if(n<=1)return 1;
	else{
		return (((m/n)*((m-inverso(m%n))%m))%m); 
	}
}

int main(){
	//~ int A[21];
	//~ for(int i=1;i<=20;i++)A[i]=0;
	//~ A[1]=1;
	//~ for(int k=1;k<10;k++){
		//~ for(int i=2;i<=20;i++){
			//~ A[i]+=A[i-1];
		//~ }
		//~ for(int i=1;i<=20;i++)cout << A[i] << " ";
		//~ cout << endl;
	//~ }
	cin >> N >> K;
	for(int i=1;i<=N;i++)cin >> a[i];
	//~ 
	if(K==0){
		for(int i=1;i<=N;i++)cout << a[i] <<" ";
		return 0;
	}
	binom[0]=1;
	for(int i=1;i<=3000;i++){
		binom[i]=(((binom[i-1]*((K-1)+i))%MOD)*inverso(i))%MOD;
	}
	//for(int i=0;i<=K;i++)cout << binom[i] << " ";
	//return 0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++)res[i]=(res[i]+a[j]*binom[i-j])%MOD;
	}
	for(int i=1;i<=N;i++){
		if(res[i]>=0)cout << res[i]%MOD << " ";
		else cout << res[i]+MOD << " ";
	}
}