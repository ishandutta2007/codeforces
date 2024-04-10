#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int a,b;
signed main(){
	cin>>a>>b;
	if (a==9&&b==1){
		cout<<99<<' '<<100<<endl;
		return 0;
	}
	if (a==b){
		cout<<a*10<<' '<<b*10+1<<endl;
		return 0;
	}
	if (b-a==1){
		cout<<a<<' '<<b<<endl;
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}