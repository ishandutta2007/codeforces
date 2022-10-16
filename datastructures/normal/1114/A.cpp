#include <iostream>
#include <cstdio>
using namespace std;
int x,y,z,a,b,c;
int main(){
	cin>>x>>y>>z>>a>>b>>c;
	if (x>a){
		puts("NO");
		return 0;
	}
	a-=x;
	if (y>a+b){
		puts("NO");
		return 0;
	}
	if (y+z>a+b+c){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}