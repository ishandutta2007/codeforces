#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
int n, a[100];
ll m;

void find(int l, int r, int d, ll rem){
//	cout <<l <<" " <<r <<" "<<d <<" "<< rem << endl;
	if(l == r){
		a[l] = d + 1;
		return;
	}
	if(rem > (1LL << (r - l - 1))){
		a[r] = d + 1;
		find(l, r - 1, d + 1, rem - (1LL << (r - l - 1)));
	}else{
		a[l] = d + 1;
		find(l + 1, r, d + 1, rem);
	}
}
		
int main(){
	cin >> n >> m;
	find(1, n, 0, m);
	for(int i = 1;i <= n;i ++) printf("%d ", a[i]);
	return 0;
}