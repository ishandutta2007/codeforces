#include <bits/stdc++.h>
using namespace std;
double PI=3.14159265357;
int T;
double n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		printf("%.8lf\n",1.0/tan(PI/n/2));
	}
}