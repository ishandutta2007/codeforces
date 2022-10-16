#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
double l,h;
signed main(){
	cin>>h>>l;
	printf("%.10lf",((l*l)-(h*h))/(2*h));
	cout<<endl;
	return 0;
}