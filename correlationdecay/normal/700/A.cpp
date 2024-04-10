#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	double l,v1,v2;
	cin>>a>>l>>v1>>v2>>b;
	double n=(a+b-1)/b;
	double k=(n-1)*(v2-v1)/(v1+v2)+(n-1);
	double t1=l/(v2+v1*k);
	printf("%.12f\n",(1+k)*t1);
	//system("pause");
	return 0;
}