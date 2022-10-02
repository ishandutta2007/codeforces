#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#define INF 1000000100
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int main(){
	int n,k;
	cin >> n >> k;
	int r[2*n+5];
	for(int i=1;i<=2*n+1;i++)cin >> r[i];
	int toS=k;
	for(int i=2;i<=2*n;i+=2){
		if(r[i]-1>r[i-1] and r[i]-1>r[i+1] and toS>0){
			r[i]--;
			toS--;
		}
	}
	for(int i=1;i<=2*n+1;i++)cout << r[i] << " ";
}