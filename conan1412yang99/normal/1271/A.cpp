#include <bits/stdc++.h>

using namespace std;

int main(){
	int a[4] , b[2] , m = 0;
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>b[0]>>b[1];
	for(int i = 0 ; i <= min(a[0] , a[3]) ; i++) m = max(m , b[0] * i + b[1] * min({a[1] , a[2] , a[3] - i})); cout<<m; 
}