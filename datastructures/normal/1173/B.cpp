#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,m,x,y;
signed main(){
	cin>>n;
	m=n/2+1;
	x=y=1;
	cout<<m<<endl;
	while(n--){
		cout<<x<<' '<<y<<endl;
		if (y<m)y++;
		else x++;
	} 
	return 0;
}