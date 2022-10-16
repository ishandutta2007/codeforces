#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int a[5],d;
signed main(){
	cin>>a[1]>>a[2]>>a[3]>>d;
	sort(a+1,a+4);
	cout<<max(0,d-(a[2]-a[1]))+max(0,d-(a[3]-a[2]))<<endl;
	return 0;
}