#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double res;
int main(){
	int m, n;
	cin >> m >> n;
	for(int i = 1;i <= m;i++){
		res += (pow(i*1.0/m,n) - pow((i - 1) *1.0/m,n)) * i;
	}
	printf("%.10lf\n", res);
	return 0;
}