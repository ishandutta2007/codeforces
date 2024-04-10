/*
3 3
1 2 3
5 6 1
4 4 1
*/
/*
2 3
4 8 8 
9 2 9
*/
/*
2 2 
1 3
4 2
*/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int N,M;
int X[600][600];
int primes[200000];
int cntP=0;
bool isPrime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	} 
	return true;
} 
int up(int x){
	return (*lower_bound(primes,primes+cntP,x))-x;
}
int main(){
	for(int i=2;i<=200000;i++){
		if(isPrime(i)) primes[cntP++]=i;
	}
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>X[i][j];
		}
	}
	int ans=1e9;
	for(int i=0;i<N;i++){
		int sum=0;
		for(int j=0;j<M;j++){
			sum+=up(X[i][j]);
		}
		ans=min(ans,sum);
	}
	for(int j=0;j<M;j++){
		int sum=0;
		for(int i=0;i<N;i++){
			sum+=up(X[i][j]);
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}