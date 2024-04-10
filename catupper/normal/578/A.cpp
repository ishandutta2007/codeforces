#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long Int;


Int a, b;
double solve(double x, Int b){
	if(x == 0)return 1 << 30;
	Int p = x / b;
	p += 10;
	if(p%2)p++;
	while(true){
		if(x >= b * p)return x / p;
		p -= 2;
	}
}

int main(){
	cin >> a >> b;
	if(a < b){
		cout << -1 << endl;
		return 0;
	}
	printf("%.10lf\n", min(solve(a + b, b), solve(a - b, b)));
	return 0;
}