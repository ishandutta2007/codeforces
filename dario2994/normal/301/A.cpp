#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

int N,cc;
int MM=100000;
int ss=0;

int main(){
	cin >> N;
	for(int i=0;i<2*N-1;i++){
		int x;
		cin >> x;
		if(x<0){
			cc++;
			x*=-1;
		}
		ss+=x;
		MM=min(MM,x);
	}
	if(cc%2==0){
		cout <<  ss << "\n";
		return 0;
	}
	if(N%2==1){
		cout << ss << "\n";
		return 0;
	}
	cout << ss-2*MM << "\n";
}