#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int a,b,c,d;
signed main(){
	cin>>a>>b>>c>>d;
	if (a+b==c+d||a+c==b+d||a+d==b+c||a==b+c+d||b==a+c+d||c==a+b+d||d==a+b+c)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}