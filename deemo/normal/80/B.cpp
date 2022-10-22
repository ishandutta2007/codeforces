#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
	int a, b;	scanf("%d:%d", &a, &b);
	a %= 12;
	cout << fixed << setprecision(12);
	a = (a * 60 + b);
	double t = (double(a)/double(12*60)) * double(360);
	cout << t << " " ;
	t = (double(b)/ double(60)) * double(360);
	cout << t << "\n";
	return	0;
}