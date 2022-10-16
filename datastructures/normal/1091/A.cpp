#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a,b,c;
int main(){
	cin>>a>>b>>c;
	a++,c--;
	cout<<3*min(a,min(b,c))<<endl;
	return 0;
}