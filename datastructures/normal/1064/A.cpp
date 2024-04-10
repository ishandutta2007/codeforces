#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
signed main(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<max(0,max(max(a+1-b-c,b+1-a-c),c+1-a-b))<<endl; 
	return 0;
}