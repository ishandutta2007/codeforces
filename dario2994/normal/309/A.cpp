#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 1000000
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

int N;
LL l, t;
LL x[MAXN], y[MAXN];

LL calcola(LL i, LL * a){
	LL ss=a[i]+2*t;
	if(ss<l)return upper_bound(a,a+N,a[i]+2*t)-(a+i)-1;
	LL ris=N-1-i;
	ss-=l;
	ris+=(N-1)*LL(ss/l);
	LL ff=(a[i]+2*t)%l;
	LL j=upper_bound(a,a+N,ff)-a;
	ris+=j;
	if(j>i)ris--;
	return ris;
}

int main(){
	cin >> N >> l >> t;
	for(int i=0;i<N;i++){
		cin >> x[i];
		y[N-1-i]=l-1-x[i];
	}
	
	LL res=0;
	for(LL i=0;i<N;i++){
		res+=calcola(i,x)+calcola(i,y);
		//~ cout << i << ": "<< calcola(i,x) << ", " << calcola(i,y) << "\n";
	}
	cout.precision(7);
	cout << fixed << ((double)res)/(double)8 << "\n";
}