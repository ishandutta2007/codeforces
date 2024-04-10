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
	if (a!=d){
		cout<<0<<endl;
		return 0;
	}
	if (a==0&&d==0){
		if (c!=0){
			cout<<0<<endl;
			return 0;
		}
		cout<<1<<endl;
		return 0;
	}
	cout<<1<<endl;
	return 0;
}