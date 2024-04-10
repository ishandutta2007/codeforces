#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int x,y,z;
signed main(){
	cin>>x>>y>>z;
	if (x+z<y){
		cout<<'-'<<endl;
		return 0;
	}
	if (y+z<x){
		cout<<'+'<<endl;
		return 0;
	}
	if (x+z==y&&y+z==x){
		cout<<0<<endl;
		return 0;
	}
	cout<<'?'<<endl;
	return 0;
}